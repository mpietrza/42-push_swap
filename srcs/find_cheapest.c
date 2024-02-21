/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:59:39 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/20 18:00:18 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long  ft_find_median(t_stack **stack)
{
    t_stack *temp;
    long     median;
 
    temp = *stack;
    median = ft_stack_size(stack) / 2;
    return (median);
}

static void ft_check_stack_median(t_stack **stack, long median)
{
    t_stack *temp;
    long    i;

    temp = *stack;
    i = 0;
    while (temp)
    {
        if (i < median)
            temp->is_upper_median = true;
        else
            temp->is_upper_median = false;
        temp = temp->next;
        i++;
    }
}

void    ft_give_push_price(t_stack **a, t_stack **b)
{
    t_stack *temp;
    long    median_a;
    long    median_b;

    median_a = ft_find_median(a);
    median_b = ft_find_median(b);
    ft_check_stack_median(b, median_b);
    
    temp = *b;
    while (temp)
    {
        if (temp->is_upper_median == true && temp->current_index < median_a)
            temp->push_price = ft_stack_size(a) - temp->current_index
            + temp->current_index;
        else if (temp->is_upper_median == false && temp->current_index < median_a)
            temp->push_price = ft_stack_size(a) - temp->current_index
            + temp->current_index;
        else if (temp->is_upper_median == false && temp->current_index > median_a)
            temp->push_price = temp->current_index + temp->current_index;
        else if (temp->is_upper_median == true && temp->current_index > median_a)
            temp->push_price = temp->current_index + temp->current_index;
        temp = temp->next;
    }
}

void    ft_find_cheapest(t_stack **a, t_stack **b, t_data *data)
{
    t_stack *temp = NULL;
    long    last_price;

    last_price = INT_MAX;
    ft_give_push_price(a, b);
    temp = *b;
    while (temp)
    {
        if (temp->push_price < last_price)
        {
            last_price = temp->push_price;
            data->cheapest_push_source_ind_b = temp->push_price;
        }
        temp = temp->next;
    }
}