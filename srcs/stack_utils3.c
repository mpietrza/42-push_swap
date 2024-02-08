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
		ft_printf("Debug point: prev_nbr = %d, nbr = %d\n", (int)prev_nbr, (int)temp->nbr);
		if (prev_nbr >= temp->nbr)
			return (false);
		prev_nbr = temp->nbr;
		temp = temp->next;
	}
	return (true);
}

void ft_give_index(t_stack **stack)
{
	t_stack	*temp;
	long	i;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->index = i;
		ft_printf("Debug point: index = %d, value = %d\n", (int)temp->index, (int)temp->nbr);
		temp = temp->next;
		i++;
	}
}

int	ft_find_index(t_stack **stack, int nbr)
{
	int	i;

	i = 0;
	while (*stack)
	{
		if ((*stack)->nbr == nbr)
			return (i);
		(*stack) = (*stack)->next;
		i++;
	}
	return (-1);
}

int	ft_find_index_after_push(t_stack **stack, int nbr_pushed)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_pushed > (*stack)->nbr && nbr_pushed < ft_stack_last(*stack)->nbr)
		i = 0;
	else if (nbr_pushed > ft_elem_max(stack)
		|| nbr_pushed < ft_elem_min(stack))
		i = ft_find_index(stack, ft_elem_max(stack));
	else
	{
		tmp = (*stack)->next;
		while ((*stack)->nbr < nbr_pushed || tmp->nbr >nbr_pushed)
		{
			(*stack) = (*stack)->next;
			tmp = (*stack)->next;
			i++;
		}
	}
	return (i);
}
