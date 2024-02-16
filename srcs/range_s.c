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
    t_stack *temp;

	ft_push(a, b);
	ft_give_index_a(a, data);
    temp = *a;
    while (temp)
    {
        ft_printf("Debug point: index = %d, value = %d\n", temp->index, temp->nbr);
        temp = temp->next;
    }
	/*ft_give_index_b(a, b);
	while (ft_is_stack_asc(a) == false)
	{
		if (ft_elem_min(a) == (*a)->nbr)
			ft_push(b, a, 'b');
		else
			ft_rotate(a);
	}*/
	(void)data;
}