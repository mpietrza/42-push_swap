/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:37:33 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/01 17:10:38 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!stack_2)
		return (false);
	tmp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = tmp;
	if (*stack_1)
		ft_printf("s%c\n", (*stack_1)->name);
	/*
	{
		write(1, "s", 1);
		write(1, &((*stack_1)->name), 1);
		write(1, "\n", 1);
	}*/
	return (true);
}
