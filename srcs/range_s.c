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

void ft_range_s(t_stack **a, t_stack **b/*, t_data *data*/)
{   
//	t_stack *temp;


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
	return ;
}