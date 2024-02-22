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
        if (temp->is_upper_median == true && temp->current_index <= median_a)
            temp->push_price = ft_stack_size(a) - temp->current_index
            + temp->current_index;
        else if (temp->is_upper_median == false && temp->current_index <= median_a)
            temp->push_price = ft_stack_size(a) - temp->current_index
            + temp->current_index;
        else if (temp->is_upper_median == false && temp->current_index > median_a)
            temp->push_price = temp->current_index + temp->current_index;
        else if (temp->is_upper_median == true && temp->current_index > median_a)
            temp->push_price = temp->current_index + temp->current_index;
        temp = temp->next;
    }
}


static bool	ft_find_cheapest_node(t_stack **stack)
{
	t_stack	*temp;
    t_stack *cheapest = NULL;

	int	i;

	if (!*stack || !stack)
		return (false);
	temp = *stack;
	i = temp->push_price;
	while (temp)
	{
		if (temp->push_price >= i)
        {
			i = temp->push_price;
            cheapest = temp;
        }
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
    ft_find_cheapest_node(a); 
    ft_find_cheapest_node(b);
}