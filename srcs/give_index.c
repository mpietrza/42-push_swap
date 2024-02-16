/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:58:57 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/16 16:59:24 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void ft_give_index_a(t_stack **a, t_data *data)
{
    t_stack *temp = *a;
    int index = 0;
    int nbr = ft_elem_min(a);
    int prev_nbr;

    while (temp)
    {
        while (temp->nbr != nbr)
        {
            temp->index = index;
            prev_nbr = nbr;
            nbr = ft_elem_min_higher_then_given(a, prev_nbr);
            ft_printf("Debug point: index = %d, value = %d\n", temp->index, temp->nbr);
            index++;
        }
        temp = temp->next;
    }
    (void)data;
}

