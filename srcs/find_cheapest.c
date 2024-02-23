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
    t_stack *temp2;
    long    median_a;
    long    median_b;

    median_a = ft_find_median(a);
    ft_printf("Debug point: median a = %d\n", median_a);
    median_b = ft_find_median(b);
    ft_printf("Debug point: median b = %d\n", median_b);
    ft_check_stack_median(b, median_b);
    
    temp2 = *b;
    while (temp2)
    {
        if (temp2->target_index <= median_a && temp2->is_upper_median == true)
            temp2->push_price = temp2->target_index + temp2->current_index;
        else if (temp2->current_index > median_a && temp2->is_upper_median == false)
        {
            temp2->push_price = ft_stack_size(a) - temp2->target_index
            + ft_stack_size(b) - temp2->current_index;
        }
        else if (temp2->target_index > median_a && temp2->is_upper_median == true)
        {
            temp2->push_price = ft_stack_size(a) - temp2->target_index
            + temp2->current_index;
        }
        else if (temp2->target_index <= median_a && temp2->is_upper_median == false)
        {
            temp2->push_price = temp2->target_index
            + ft_stack_size(b) - temp2->current_index;
        }
        temp2 = temp2->next;
        ft_print_stack(b);
    }
}


static bool	ft_find_cheapest_node(t_stack **stack)
{
	t_stack	*temp;
    t_stack *cheapest = NULL;
	int     prev_push_price;
    int     prev_cur_index;

    if (!*stack || !stack)
		return (false);
	temp = *stack;
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
            && ((prev_cur_index > temp->current_index && temp->is_upper_median == true)
                || (prev_cur_index < temp->current_index && temp->is_upper_median == false)))
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
    return (true);
}

void    ft_find_cheapest(t_stack **a, t_stack **b)
{
    ft_give_push_price(a, b);
    ft_find_cheapest_node(b);
}