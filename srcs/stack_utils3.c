/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:51:19 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:08:08 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_stack_asc(t_stack **stack)
{
	long	prev_nbr;
	t_stack	*temp;

	if (!stack)
	{
		ft_printf("Debug point: stack is NULL\n");
		return (false);
	}
	temp = *stack;
	prev_nbr = temp->nbr;
	temp = temp->next;
	while (temp)
	{
		if (prev_nbr >= temp->nbr)
			return (false);
		prev_nbr = temp->nbr;
		temp = temp->next;
	}
	ft_printf("Debug point: the stack is ascending\n");
	return (true);
}
