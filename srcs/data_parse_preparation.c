/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse_preparation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:59:27 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 16:46:18 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_data_parse(t_stack **a, int argc, char **argv, t_data *data)
{
	int		i;
	long	num;
	t_stack	*temp;

	i = 1;
	*a = NULL;
	while (argv[i])
	{
		num = ft_atoi_ps(argv[i], data);
		ft_printf("Debug point: parsed atoi'ed num = %d\n", (int)num);
		if (data->atoi_error == true)
			return (false);
		ft_stack_add_bottom(a, ft_stack_new('a', num));
		i++;
	}
	ft_give_index(a);
	temp = *a;
	while (temp)
	{
		ft_printf("Debug point: index = %d, value = %d\n", temp->index, temp->nbr);
		temp = temp->next;
	}
	if (i == argc)
		return (true);
	else
		printf("Error\nInvalid input data!\n");
	return (false);
}

bool	ft_duplicate_check(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (false);
			temp = temp->next;
		}
		a = a->next;
	}
	return (true);
}

