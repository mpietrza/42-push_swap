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

	*a = ft_stack_new('a', ft_atoi_ps(data->argv[1], data));
	if (!*a || data->atoi_error == true)
		return (false);
	j = 2;
	while (j < data->argc)
	{
		num = ft_atoi_ps(data->argv[j], data);
		if (data->atoi_error == true)
			return (false);
		ft_stack_add_bottom(a, ft_stack_new('a', num));
		j++;
	}
	if (j == data->argc)
		return (true);
	else
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