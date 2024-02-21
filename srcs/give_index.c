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


void ft_give_index_a(t_stack **a)
{
    t_stack *temp;
    int index = 0;
    int nbr;
    int prev_nbr;
    int i;

    temp = *a;
    nbr = ft_elem_min(a);
    ft_printf("Debug point: min = %d\n", nbr);
    i = 0;
    while (i < ft_stack_size(a))
    {
        while (temp)
        {
            if (temp->nbr == nbr)
            {
                temp->current_index = index;
                index++;
                prev_nbr = nbr;
                nbr = ft_elem_min_higher_than_given(a, prev_nbr);
                ft_printf("Debug point: indexing index = %d, value = %d\n",
                    temp->current_index, temp->nbr);
            }
            temp = temp->next;
        }
        temp = *a;
        ft_printf("Debug point: i = %d\n", i);
        i++;
    }
}

void ft_give_index_b(t_stack **a, t_stack **b)
{
    t_stack *temp;
    int nbr;
    int prev_nbr;
    int i;

    temp = *b;
    nbr = ft_elem_min(b);
    ft_printf("Debug point: min. value from stack b = %d\n", nbr);
    i = 0;
    while (i < ft_stack_size(b))
    {
        while (temp)
        {
            if (temp->nbr == nbr)
            {
                temp->current_index = ft_find_nearest_higher(a, temp->nbr);
                prev_nbr = nbr;
                nbr = ft_elem_min_higher_than_given(b, prev_nbr);
                ft_printf("Debug point: indexing attempt index = %d, value = %d\n",
                    temp->current_index, temp->nbr);
            }
            temp = temp->next;
        }
        temp = *b;
        ft_printf("Debug point: i = %d\n", i);
        i++;
    }
}

void    ft_give_current_index(t_stack **stack)
{
    t_stack *temp;
    int i;

    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->current_index = i;
        ft_printf("Debug point: current index = %d, index = %d, value = %d\n",
            temp->current_index, temp->current_index, temp->nbr);
        temp = temp->next;
        i++;
    }
}