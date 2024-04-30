/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:55:32 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 18:06:21 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_what_rotation_core(t_stack **a, t_stack **b,
	bool uppr_med_a, bool uppr_med_b)
{
	if (uppr_med_a == true && uppr_med_b == true)
		ft_rr(a, b);
	else if (uppr_med_a == true && uppr_med_b == false)
	{
		ft_rotate(a);
		ft_rev_rotate(b);
	}
	else if (uppr_med_a == false && uppr_med_b == true)
	{
		ft_rev_rotate(a);
		ft_rotate(b);
	}
	else if (uppr_med_a == false && uppr_med_b == false)
		ft_rrr(a, b);
}

void	ft_what_rotation(t_stack **a, t_stack **b,
	bool uppr_med_a, bool uppr_med_b)
{
	if ((*a)->cheapest == false && (*b)->cheapest == false)
		ft_what_rotation_core(a, b, uppr_med_a, uppr_med_b);
	else if ((*a)->cheapest == false && (*b)->cheapest == true)
	{
		if (uppr_med_a == true)
			ft_rotate(a);
		else
			ft_rev_rotate(a);
	}
	else if ((*a)->cheapest == true && (*b)->cheapest == false)
	{
		if (uppr_med_b == true)
			ft_rotate(b);
		else
			ft_rev_rotate(b);
	}
}

void	ft_what_rotation_end_of_stack_a(t_stack **a, t_stack **b,
		bool uppr_med_a, bool uppr_med_b)
{
	if ((*a)->target_index != 0 && (*b)->cheapest == false)
		ft_what_rotation_core(a, b, uppr_med_a, uppr_med_b);
	else if ((*a)->target_index != 0 && (*b)->cheapest == true)
	{
		if (uppr_med_a == true)
			ft_rotate(a);
		else
			ft_rev_rotate(a);
	}
	else if ((*a)-> target_index == 0 && (*b)->cheapest == false)
	{
		if (uppr_med_b == true)
			ft_rotate(b);
		else
			ft_rev_rotate(b);
	}
}
