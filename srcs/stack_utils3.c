/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:51:19 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:08:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_stack_asc(t_stack **stack)
{
	long	prev_nbr;
	t_stack	*temp;

	if (!stack)
		return (false);
	temp = *stack;
	prev_nbr = temp->nbr;
	temp = temp->next;
	while (temp)
	{
		if (prev_nbr > temp->nbr)
			return (false);
		prev_nbr = temp->nbr;
		temp = temp->next;
	}
	return (true);
}

static void ft_stack_delone(t_stack *stack)
{
	if (stack)
	{
		if (stack->next)
		{
			stack->next = NULL;
		}		
		free(stack);
		stack = NULL;
	}
}

void	ft_stack_free(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		ft_stack_delone(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
