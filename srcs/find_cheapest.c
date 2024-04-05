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
    long     median;
 
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

void    ft_give_push_price(t_stack **b, t_stack **a)
{
    t_stack *temp;
    long    median_b;
    long    median_a;

    if ((*a) == NULL || (*b) == NULL || a == NULL || b == NULL)
    {
        ft_printf("Error\nStack is NULL\n");
        return ;
    }
    median_b = ft_find_median(b);
    median_a = ft_find_median(a);
    ft_check_stack_median(b, median_b);
    ft_check_stack_median(a, median_a);
    temp = *b;
    while (temp)
    {
        if (temp->push_index <= median_a && temp->is_upper_median == true)
            temp->push_price = temp->push_index + temp->current_index;
        else if (temp->push_index > median_a && temp->is_upper_median == false)
        {
            temp->push_price = ft_stack_size(a) - temp->push_index
            + ft_stack_size(b) - temp->current_index;
        }
        else if (temp->push_index > median_a && temp->is_upper_median == true)
        {
            temp->push_price = ft_stack_size(a) - temp->push_index
            + temp->current_index;
        }
        else if (temp->push_index <= median_a && temp->is_upper_median == false)
        {
            temp->push_price = temp->push_index
            + ft_stack_size(b) - temp->current_index;
        }
        temp = temp->next; 
    }
}

static bool	ft_find_cheapest_node(t_stack **b, t_stack **a)
{
	t_stack	*temp;
    t_stack *cheapest = NULL;
	int     prev_push_price;
    int     prev_cur_index;

    if (!*b || !b || !*a || !a)
		return (false);
	temp = *b;
    prev_cur_index = INT_MAX;
	prev_push_price = INT_MAX;
	while (temp)
	{
		if (temp->push_price < prev_push_price)
        {
			prev_push_price = temp->push_price;
            cheapest = temp;
        }
        else if ((temp->push_price == prev_push_price)
            && ((prev_cur_index > temp->current_index
            && temp->is_upper_median == true)
            || (prev_cur_index < temp->current_index
            && temp->is_upper_median == false)))
        {
            prev_push_price = temp->push_price;
            cheapest = temp;
        }
        prev_cur_index = temp->current_index;
        temp = temp->next;
	}
    if (cheapest == NULL)
        return (false);
    cheapest->cheapest = true;
    temp = *a;
    while (temp->next && temp->current_index != cheapest->push_index)
        temp = temp->next;
    if (temp->next == NULL && ft_stack_size(b) != 1)
        (*a)->cheapest = true;
    else
        temp->cheapest = true;
    return (true);
}

void    ft_find_cheapest(t_stack **source, t_stack **target)
{
    ft_give_push_price(source, target);
    ft_find_cheapest_node(source, target);
}