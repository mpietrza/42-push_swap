/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:47 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/02 14:50:55 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_elem_min(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = a->nbr;
		stack = stack->next;
	}
	return (i);
}

int	ft_elem_max(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}
