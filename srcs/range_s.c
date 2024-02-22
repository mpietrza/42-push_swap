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

void ft_range_s(t_stack **a, t_stack **b, t_data *data)
{   
//	t_stack *temp;

	while (ft_stack_size(a) > 3)
	{
		ft_printf("Debug point: stack size = %d\n", ft_stack_size(a));
		ft_push(a, b);
		ft_printf("Debug point: stack size after push = %d\n", ft_stack_size(a));
	}
	ft_range_3(a);
	ft_give_target_index_a(a);
	ft_give_current_index(a);
	ft_give_target_index_b(a, b);
	ft_give_current_index(b);
	ft_find_cheapest(a, b);
	ft_print_stack(a);
	ft_print_stack(b);
	ft_printf("Debug: PUSHING BACK STARTS,\nft_stack_size of b = %d\n", ft_stack_size(b));
	while (ft_stack_size(b) > 0)
	{
		if (ft_cheapest_move_b_to_a(a, b, data) == false)
		{	
			ft_printf("Debug: cheapest move error\n");
			break ;
		}
		ft_give_target_index_a(a);
		ft_give_current_index(a);
		ft_give_target_index_b(a, b);
		ft_give_current_index(b);
		ft_find_cheapest(a, b);
		ft_print_stack(a);
		ft_print_stack(b);
	}
}