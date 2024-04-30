/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:59:39 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 16:25:06 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	ft_find_chpst_node_b_end_of_st(t_stack **b, t_stack **cheapest_b)
{
	t_stack	*temp_b;
	int		prev_push_price;

	temp_b = *b;
	prev_push_price = INT_MAX;
	while (temp_b)
	{
		if (temp_b->push_price < prev_push_price)
		{
			prev_push_price = temp_b->push_price;
			*cheapest_b = temp_b;
		}
		temp_b = temp_b->next;
	}
	if (*cheapest_b == NULL)
		return (false);
	return (true);
	//need to simplify it
	//if (temp_b->next == NULL && ft_stack_size(b) != 1
    //&& (cheapest_b->nbr > temp_b->nbr))
    //(*b)->cheapest = true;  ????
}

static void	ft_find_cheapest_node_b_core(t_stack **b, t_stack **cheapest_b)
{
	t_stack	*temp_b;
	int		prev_push_price;
	int		prev_cur_index;

	temp_b = *b;
	prev_cur_index = INT_MAX;
	prev_push_price = INT_MAX;
	while (temp_b)
	{
		if ((temp_b->push_price < prev_push_price
				|| (temp_b->push_price == prev_push_price
					&& ((prev_cur_index > temp_b->current_index
							&& temp_b->is_upper_median == true)
						|| (prev_cur_index < temp_b->current_index
							&& temp_b->is_upper_median == false))))
			&& temp_b->is_pushed_to_end_of_stack == false)
		{
			prev_push_price = temp_b->push_price;
			*cheapest_b = temp_b;
		}
		prev_cur_index = temp_b->current_index;
		temp_b = temp_b->next;
	}
}

static bool	ft_find_cheapest_node_b(t_stack **b, t_stack **cheapest_b)
{
	ft_find_cheapest_node_b_core(b, cheapest_b);
	if (*cheapest_b == NULL)
	{
		if (ft_find_chpst_node_b_end_of_st(b, cheapest_b) == false)
			return (false);
	}
	(*cheapest_b)->cheapest = true;
	return (true);
}

static bool	ft_find_cheapest_nodes(t_stack **b, t_stack **a)
{
	t_stack	*temp_a;
	t_stack	*cheapest_b;

	temp_a = *a;
	cheapest_b = NULL;
	if (ft_find_cheapest_node_b(b, &cheapest_b) == false)
		return (false);
	while (temp_a->next && temp_a->current_index != cheapest_b->push_index)
		temp_a = temp_a->next;
	if (temp_a->next == NULL && ft_stack_size(b) != 1
		&& (cheapest_b->nbr > temp_a->nbr))
		(*a)->cheapest = true;
	else
		temp_a->cheapest = true;
	return (true);
}

bool	ft_find_cheapest(t_stack **b, t_stack **a)
{
	if (!*b || !b || !*a || !a)
		return (false);
	ft_give_push_price(b, a);
	if (ft_find_cheapest_nodes(b, a) == false)
		return (false);
	return (true);
}
