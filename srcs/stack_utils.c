/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:52:54 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:04:19 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_stack_init(t_stack **stack, char name, long nbr, long index)
{
	*stack = ft_calloc(1, sizeof(stack));
	if (!*stack)
		return (false);
	(*stack)->name = name;
	(*stack)->nbr = nbr;
	(*stack)->index = index;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	return (true);
}

t_stack	*ft_stack_new(char name, long nbr)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->name = name;
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_add_top(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (*stack)
			new->next = *stack;
		*stack = new;
	}
}

void	ft_stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack)
		ft_stack_last(*stack)->next = new;
	else
		*stack = new;
}
