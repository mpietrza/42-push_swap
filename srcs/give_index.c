/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:58:57 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 17:35:10 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_give_target_index_asc(t_stack **a)
{
	t_stack	*temp_a;
	int		nbr;
	int		i;

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
			break ;
	}
}

static void	ft_give_cur_and_push_ind_b_to_a_core(t_stack **a,
	t_stack *temp_b, int best_match)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->nbr == best_match)
		{
			temp_b->push_index = temp_a->current_index;
			break ;
		}
		temp_a = temp_a->next;
	}
}

void	ft_give_push_index_b_to_a(t_stack **b, t_stack **a)
{
	t_stack	*temp_b;
	int		best_match;

	temp_b = *b;
	while (temp_b)
	{
		best_match = ft_elem_min_higher_than_given(a, temp_b->nbr);
		if (best_match == INT_MAX)
		{
			temp_b->push_index = ft_stack_size(a);
			temp_b->is_pushed_to_end_of_stack = true;
		}
		else
		{
			temp_b->is_pushed_to_end_of_stack = false;
			ft_give_cur_and_push_ind_b_to_a_core(a, temp_b, best_match);
		}
		temp_b = temp_b->next;
	}
}

long	ft_give_current_index(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	if (!*stack)
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

void	ft_give_cur_and_push_ind_b_to_a(t_stack **b, t_stack **a)
{
	ft_give_current_index(a);
	ft_give_current_index(b);
	ft_give_push_index_b_to_a(b, a);
}
