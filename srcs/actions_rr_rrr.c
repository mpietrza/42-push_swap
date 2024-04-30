/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:46:46 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/29 17:04:03 by mpietrza         ###   ########.fr       */
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
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b->cheapest != true)
		temp_b = temp_b->next;
	if (!temp_b)
		return (false);
	if (temp_b->push_index == ft_stack_size(a))
	{
		while ((*a)->target_index != 0 || (*b)->cheapest == false)
		{
			ft_what_rotation_end_of_stack_a(a, b, uppr_med_a, uppr_med_b);
			ft_give_current_index(a);
			ft_give_push_index_b_to_a(b, a);
		}
	}
	else
	{
		while ((*a)->cheapest == false || (*b)->cheapest == false)
		{
			ft_what_rotation(a, b, uppr_med_a, uppr_med_b);
			ft_give_current_index(a);
			ft_give_push_index_b_to_a(b, a);
		}
	}
	return (true);
}

static bool	find_target_index_zero(t_stack **a)
{
	t_stack	*temp_a;

	ft_give_current_index(a);
	ft_give_target_index_asc(a);
	temp_a = *a;
	while (temp_a->target_index != 0)
		temp_a = temp_a->next;
	if (!temp_a)
		return (false);
	if (temp_a->current_index < ft_stack_size(a) / 2)
		return (true);
	else
		return (false);
}

bool	ft_cheapest_move(t_stack **b, t_stack **a)
{
	t_stack	*temp_b;
	bool	uppr_med_a;
	bool	uppr_med_b;

	temp_b = *b;
	uppr_med_a = false;
	uppr_med_b = false;
	while (temp_b->cheapest == false)
		temp_b = temp_b->next;
	if (temp_b == NULL)
		return (false);
	if (temp_b->is_pushed_to_end_of_stack == true)

		uppr_med_a = find_target_index_zero(a);
	else if (temp_b->push_index < ft_stack_size(a) / 2)
		uppr_med_a = true;
	else
		uppr_med_a = false;
	uppr_med_b = temp_b->is_upper_median;
	if (ft_cheapest_move_core(b, a, uppr_med_a, uppr_med_b) == false)
		return (false);
	ft_push(b, a);
	ft_stack_reset(a);
	ft_give_target_index_asc(a);
	if (ft_is_stack_asc_rollover(a) == false)
		ft_swap(a);
	return (true);
}

void	ft_final_rotations(t_stack **a)
{
	if ((*a)->target_index > ft_stack_size(a) / 2)
	{
		while ((*a)->target_index != 0)
			ft_rotate(a);
	}
	else
	{
		while ((*a)->target_index != 0)
			ft_rev_rotate(a);
	}
}
