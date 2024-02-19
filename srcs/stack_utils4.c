/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:33:34 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 14:33:37 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


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
