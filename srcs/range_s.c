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
	ft_print_stack(a);
	ft_print_stack(b);
	ft_push(b, a);
	ft_give_target_index_asc(a);
	while (temp_a->current_index != temp_a->target_index)
	{
		ft_rotate(a);
		ft_give_current_index(a);
		temp_a = *a;
	}
	ft_print_stack(a);
	if (*b)
		ft_print_stack(b);
}

/*void ft_range_5(t_stack **a, t_stack **b, t_data *data)
{
	t_stack *temp_a;
	t_stack *temp_b;
	
	temp_a = *a;
	temp_b = *b;
	ft_printf("Debug point: range_4\n");
	while (ft_stack_size(a) > 3)
		ft_push(a, b);
	if (ft_is_stack_desc(b) == false)
		ft_swap(b);
	ft_range_3(a);
	while (ft_stack_size(b) > 0)
	{
		ft_give_target_index_asc(a);
		ft_give_current_index(a);
		ft_give_current_index(b);
		ft_give_push_index_b_to_a(b, a);
		ft_print_stack(a);
		ft_print_stack(b);
	}
}*/

void ft_range_s(t_stack **a, t_stack **b, t_data *data)
{   
//	t_stack *temp;
	ft_printf("Debug point: range_s\n");
	data->is_int = true; //to be deleted
	while (ft_stack_size(a) > 3 && ft_stack_size(b) < 2)
	{
		ft_push(a, b);
		if (ft_is_stack_desc(b) == false)
			ft_swap(b);
	}
	while (ft_stack_size(a) > 3)
	{
		ft_give_target_index_asc(a);
		ft_give_current_index(a);
		ft_give_current_index(b);
		ft_give_push_index_a_to_b(a, b);
		ft_find_cheapest(a, b);
		ft_cheapest_move(a, b);
	}
	ft_print_stack(a);
	ft_print_stack(b);
	ft_range_3(a);
//
}