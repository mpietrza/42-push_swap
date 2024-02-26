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

void    ft_give_push_price(t_stack **source, t_stack **target)
{
    t_stack *temp;
    long    median_source;
    long    median_target;

    ft_printf("Debug point: giving push price from %c to %c\n", 
    (*source)->name, (*target)->name);
    median_source = ft_find_median(source);
    median_target = ft_find_median(target);
    ft_check_stack_median(source, median_source);
    ft_check_stack_median(target, median_target);
    
    temp = *source;
    if (temp == NULL)
    {
        ft_printf("Error\nStack is NULL\n");
        return ;
    }
    while (temp)
    {
        if (temp->target_index <= median_target && temp->is_upper_median == true)
            temp->push_price = temp->target_index + temp->current_index;
        else if (temp->current_index > median_target && temp->is_upper_median == false)
        {
            temp->push_price = ft_stack_size(target) - temp->target_index
            + ft_stack_size(source) - temp->current_index;
        }
        else if (temp->target_index > median_target && temp->is_upper_median == true)
        {
            temp->push_price = ft_stack_size(target) - temp->target_index
            + temp->current_index;
        }
        else if (temp->target_index <= median_target && temp->is_upper_median == false)
        {
            temp->push_price = temp->target_index
            + ft_stack_size(source) - temp->current_index;
        }
        temp = temp->next; 
    }
    ft_printf("Debug point: ft_give push_price successful\n");
}


static bool	ft_find_cheapest_node(t_stack **source, t_stack **target)
{
	t_stack	*temp;
    t_stack *cheapest = NULL;
	int     prev_push_price;
    int     prev_cur_index;

    if (!*source || !source)
		return (false);
	temp = *source;
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
    temp = *target;
    while (temp && temp->current_index != cheapest->target_index) // Add null check
        temp = temp->next;
    if (temp == NULL)
        return (false);
    else
        temp->cheapest = true;
    ft_printf("Debug point: cheapest node found\n");
    return (true);
}

void    ft_find_cheapest(t_stack **source, t_stack **target)
{
    ft_give_push_price(source, target);
    ft_find_cheapest_node(source, target);
}