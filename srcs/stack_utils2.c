/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:25:47 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:06:29 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
 
int	ft_elem_min(t_stack **stack)
{
	t_stack	*temp;
	int	i;

	if (!*stack || !stack)
		return (INT_MAX);
	temp = *stack;
	i = temp->nbr;
	while (temp)
	{
		if (temp->nbr < i)
			i = temp->nbr;
		temp = temp->next;
	}
	return (i);
}

int	ft_elem_max(t_stack **stack)
{
	t_stack	*temp;
	int	i;

	if (!*stack || !stack)
		return (INT_MIN);
	temp = *stack;
	i = temp->nbr;
	while (temp)
	{
		if (temp->nbr > i)
			i = temp->nbr;
		temp = temp->next;
	}
	return (i);
}

int	ft_stack_size(t_stack **stack)
{
	int	i;

	if (!*stack)
		return (0);
	i = 1;
	while ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		i++;
	}
	return (i);
}
