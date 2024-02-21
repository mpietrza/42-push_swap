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

bool	ft_data_parse(t_stack **a, t_data *data)
{
	int		j;
	long	num;
	t_stack	*temp;

	*a = ft_stack_new('a', ft_atoi_ps(data->argv[1], data));
	if (!*a || data->atoi_error == true)
		return (false);
	else
		ft_printf("Debug point: stack 'a' created, 1st num stacked\n");
	ft_printf("Debug point: argc = %d\n", data->argc);
	j = 2;
	while (j < data->argc)
	{
		ft_printf("Debug point: data->argv[%d] = %s\n", j, data->argv[j]);
		num = ft_atoi_ps(data->argv[j], data);
		if (data->atoi_error == true)
			return (false);
		ft_printf("Debug point: parsed atoi'ed num = %d\n", (int)num);
		ft_stack_add_bottom(a, ft_stack_new('a', num));
		j++;
	}

	
	temp = *a;
	while (temp)
	{
		ft_printf("Debug point: index = %d, value = %d\n",
			temp->current_index, temp->nbr);
		temp = temp->next;
	}
	if (j == data->argc)
		return (true);
	else
	{
		return (false);
	}
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