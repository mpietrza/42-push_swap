/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:39:57 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 17:56:30 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_stack_change_name(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->name == 'a')
		tmp->name = 'b';
	else
		tmp->name = 'a';
}

bool	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	temp = NULL;
	if (!*stack_1)
		return (false);
	else if (!stack_2 || !(*stack_2))
	{
		temp = (*stack_1)->next;
		*stack_2 = *stack_1;
		(*stack_2)->next = NULL;
		*stack_1 = temp;
		ft_stack_change_name(stack_2);
	}
	else if (*stack_2)
	{
		temp = (*stack_1)->next;
		(*stack_1)->next = *stack_2;
		*stack_2 = *stack_1;
		*stack_1 = temp;
		ft_stack_change_name(stack_2);
	}
	if (stack_2 && *stack_2)
		ft_printf("p%c\n", (*stack_2)->name);
	return (true);
}
