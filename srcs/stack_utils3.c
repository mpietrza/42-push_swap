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
		temp->current_index = i;
		ft_printf("Debug point: index = %d, value = %d\n",
			(int)temp->current_index, (int)temp->nbr);
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


int ft_find_nearest_higher(t_stack **stack, int nbr_pushed)
{
	int		prev_nbr;
	int		index;
	t_stack	*temp;

	prev_nbr = INT_MIN;
	temp = *stack;
	index = 0;
	while (temp)
	{
		if (temp->nbr < nbr_pushed && temp->nbr > prev_nbr)
		{
			index = temp->current_index;
			prev_nbr = temp->nbr;
		}
		temp = temp->next;
	}
	ft_printf("Debug point: the index after pushing of the given number: %d is %d\n", nbr_pushed, index);
	return (index);
}