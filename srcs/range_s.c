/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:25:12 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/16 17:25:21 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_range_4(t_stack **a, t_stack **b)
{
	t_stack *temp_a;

	ft_push(a, b);
	ft_range_3(a);
	ft_give_current_index(a);
	ft_give_push_index_b_1_node_to_a(b, a);
	temp_a = *a;
	while (temp_a->current_index != (*b)->push_index)
		temp_a = temp_a->next;
	temp_a->push_index = -1;
	while ((*a)->push_index != -1)
		ft_rotate(a);
	ft_push(b, a);
	ft_give_target_index_asc(a);
	while (temp_a->current_index != temp_a->target_index)
	{
		ft_rotate(a);
		ft_give_current_index(a);
		temp_a = *a;
	}
	ft_give_target_index_asc(a);
	ft_give_current_index(a);
	if ((*a)->current_index != (*a)->target_index)
		ft_rotate(a);
}

void	ft_range_5(t_stack **a, t_stack **b)
{
	while (ft_stack_size(a) > 3)
		ft_push(a, b);
	ft_range_3(a);
	while (*b)
	{
		ft_give_current_index(a);
		ft_give_current_index(b);
		ft_give_target_index_asc(a);
		ft_give_push_index_b_to_a(b, a);
		ft_find_cheapest(b, a);
		ft_print_stack(a);
		ft_print_stack(b);
		ft_cheapest_move(b, a);
		ft_give_target_index_asc(a);
		ft_print_stack(a);
		ft_print_stack(b);
	}
	ft_final_rotations(a);
}
