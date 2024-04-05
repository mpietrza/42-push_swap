/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:35:26 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/02 14:28:52 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool ft_swap_core(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (false);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (true);
}

bool	ft_swap(t_stack **stack)
{
	if (ft_swap_core(stack) == false)
		return (false);
	if (*stack)
		ft_printf("s%c\n", (*stack)->name);
	return (true);
}

bool	ft_ss(t_stack **a, t_stack **b)
{	
	if (ft_swap_core(a) == false || ft_swap_core(b) == false)
		return (false);
	if (*a && *b)
		write(1, "ss\n", 3);
	return (true);
}