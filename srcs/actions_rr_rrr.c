/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:46:46 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/20 18:48:22 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_stack_reset(t_stack **stack)
{
	t_stack	*temp;
	
	temp = *stack;
	while (temp)
	{
		temp->cheapest = false;
		temp->is_upper_median = false;
		if (temp->name == 'a')
			temp->push_index = 0;
		temp = temp->next;
	}
	ft_give_current_index(stack);
}

static bool	ft_cheapest_move_core(t_stack **b, t_stack **a,
	bool uppr_med_a, bool uppr_med_b)
{
	if ((*b)->push_index == ft_stack_size(a))
	{
		while ((*a)->target_index != 0)
		{
			if (uppr_med_a == true)
				ft_rotate(a);
			else if (uppr_med_a == false)
				ft_rev_rotate(a);
			else
				return (false);
		}
	}
	else
	{
		while ((*a)->cheapest == false || (*b)->cheapest == false)
		{
			ft_what_rotation(a, b, uppr_med_a, uppr_med_b);
			ft_give_push_index_b_to_a(b, a);
		}
	}
	return (true);
}

bool    ft_cheapest_move(t_stack **b, t_stack **a)
{
	t_stack *temp_b;
	bool	uppr_med_a;
	bool	uppr_med_b;

	temp_b = *b;
	uppr_med_a = false;
	uppr_med_b = false;
	while (temp_b->cheapest == false)
		temp_b = temp_b->next;
	if (temp_b == NULL)
		return (false);
	if ((temp_b->push_index / ft_stack_size(a)) * 100 < 50)
		uppr_med_a = true;
	else
		uppr_med_a = false;
	uppr_med_b = temp_b->is_upper_median;
	if (ft_cheapest_move_core(b, a, uppr_med_a, uppr_med_b) == false)
		return (false);
	ft_push(b, a);
	ft_give_target_index_asc(a);
	ft_stack_reset(a);
	ft_stack_reset(b);
	return (true);
}

void	ft_final_rotations(t_stack **a)
{
	if ((*a)->target_index <= ft_stack_size(a) / 2)
	{
		while ((*a)->target_index != 0)
			ft_rev_rotate(a);
	}
	else
	{
		while ((*a)->target_index != 0)
			ft_rotate(a);
	}
}