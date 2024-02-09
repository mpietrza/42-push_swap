/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:37:33 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/02 13:56:39 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (!*stack_2)
		return (false);
	tmp = *stack_1;
	tmp->name = (*stack_2)->name;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = tmp;
	if (*stack_1)
		ft_printf("s%c\n", (*stack_1)->name);
	return (true);
}
