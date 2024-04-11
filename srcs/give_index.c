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

void    ft_give_target_index_asc(t_stack **a)
{
    t_stack *temp_a;
    int     nbr;
    int     i;

    temp_a = *a;
    nbr = ft_elem_min(a);
    i = 0;
    while (i < ft_stack_size(a))
    {
        while (temp_a->nbr != nbr)
            temp_a = temp_a->next;
        if (temp_a)
        {
            temp_a->target_index = i++;
            nbr = ft_elem_min_higher_than_given(a, nbr);
            temp_a = *a;
        }
        else
            break;
      }
}

void ft_give_push_index_b_1_node_to_a(t_stack **b, t_stack **a)
{
    t_stack *temp_a;
    long    index_best_match;

    index_best_match = INT_MAX;
    temp_a = *a;
    while (temp_a)
    {
        if (temp_a->nbr > (*b)->nbr && temp_a->nbr < index_best_match)
        {
            index_best_match = temp_a->nbr;
            (*b)->push_index = temp_a->current_index;
        }
        temp_a = temp_a->next;
    }
    if (index_best_match == INT_MAX)
        (*b)->target_index = 0;
}

void ft_give_push_index_b_to_a(t_stack **b, t_stack **a)
{
    t_stack *temp_a;
    t_stack *temp_b;
    int index_best_match;

    temp_b = *b;
    while (temp_b)
    {   
        index_best_match = INT_MAX;
        temp_a = *a;
        while (temp_a)
        {
            if (temp_a->nbr > temp_b->nbr && temp_a->nbr < index_best_match)
            {
                index_best_match = temp_a->nbr;
                temp_b->push_index = temp_a->current_index;
            }
            temp_a = temp_a->next;
        }
        if (index_best_match == INT_MAX)
            temp_b->push_index = ft_stack_size(a);
        temp_b = temp_b->next;
    }
}

long    ft_give_current_index(t_stack **stack)
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