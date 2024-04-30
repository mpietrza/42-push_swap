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

void	ft_range_s(t_stack **a, t_stack **b)
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
		ft_cheapest_move(b, a);
		ft_give_target_index_asc(a);
	}
	ft_final_rotations(a);
}
