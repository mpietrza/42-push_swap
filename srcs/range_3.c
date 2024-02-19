/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:55:21 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:06:56 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_range_2(t_stack **a)
{
	ft_swap(a);
}

void	ft_range_3(t_stack **a)
{
	if (ft_elem_min(a) == (*a)->nbr)
	{
		ft_rev_rotate(a);
		ft_swap(a);
	}
	else if (ft_elem_max(a) == (*a)->nbr)
	{
		ft_rotate(a);
		if (ft_is_stack_asc(a) == false)
			ft_swap(a);
	}
	else
	{
		ft_rev_rotate(a);
		if (ft_is_stack_asc(a) == false)
		{
			ft_swap(a);
			ft_rev_rotate(a);
		}
	}
}