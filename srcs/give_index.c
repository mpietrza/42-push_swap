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


void ft_give_target_index_a(t_stack **a)
{
    t_stack *temp;
    int index = 0;
    int nbr;
    int prev_nbr;
    int i;

    temp = *a;
    nbr = ft_elem_min(a);
    i = 0;
    while (i < ft_stack_size(a))
    {
        while (temp)
        {
            if (temp->nbr == nbr)
            {
                temp->target_index = index;
                index++;
                prev_nbr = nbr;
                nbr = ft_elem_min_higher_than_given(a, prev_nbr);
                break;
            }
            temp = temp->next;
        }
        temp = *a;
        i++;
    }
}

void ft_give_target_index_b(t_stack **a, t_stack **b)
{
    t_stack *temp;
    t_stack *temp2;
    int nbr;
    int prev_nbr;
    int i;

    temp2 = *b;
    nbr = ft_elem_min(b);
    i = 0;
    while (i < ft_stack_size(b))
    {
        temp = *a;
        while (temp)
        {
            if (temp->nbr > nbr)
            {
                ft_printf("Debug: stack b value = %d, target index = %d\n", temp->nbr, temp->target_index);
                temp2->target_index = temp->target_index;
                prev_nbr = nbr;
                ft_printf("Debug: nbr = %d\n", nbr);
                nbr = ft_elem_min_higher_than_given(b, prev_nbr);
                ft_printf("Debug: higher nbr then given form stack 'b' = %d\n", nbr);
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            temp2->target_index = ft_give_current_index(a);
            prev_nbr = nbr;
            nbr = ft_elem_min_higher_than_given(b, prev_nbr);
        }
        temp2 = temp2->next;
        i++;
    }
}

int    ft_give_current_index(t_stack **stack)
{
    t_stack *temp;
    int i;

    if (!*stack || !stack)
        return (-1);
    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->current_index = i;
        temp = temp->next;
        i++;
    }
    return (i);
}