/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs_r_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:37:12 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 17:57:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	ft_rev_rotate_core(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return (false);
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	return (true);
}

bool	ft_rev_rotate(t_stack **stack)
{
	if (ft_rev_rotate_core(stack) == false)
		return (false);
	if (*stack)
		ft_printf("rr%c\n", (*stack)->name);
	return (true);
}

bool	ft_rrr(t_stack **a, t_stack **b)
{
	if (ft_rev_rotate_core(a) == false || ft_rev_rotate_core(b) == false)
		return (false);
	if (*a && *b)
		write(1, "rrr\n", 4);
	return (true);
}
