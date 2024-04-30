/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:56:04 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 17:58:14 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	ft_rotate_core(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return (false);
	tmp = *stack;
	*stack = ft_stack_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	return (true);
}

bool	ft_rotate(t_stack **stack)
{
	if (ft_rotate_core(stack) == false)
		return (false);
	if (*stack)
		ft_printf("r%c\n", (*stack)->name);
	return (true);
}

bool	ft_rr(t_stack **a, t_stack **b)
{
	if (ft_rotate_core(a) == false || ft_rotate_core(b) == false)
		return (false);
	if (*a && *b)
		write(1, "rr\n", 3);
	return (true);
}
