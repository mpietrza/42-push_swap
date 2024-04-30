/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:00:12 by mpietrza          #+#    #+#             */
/*   Updated: 2024/04/30 18:00:30 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stack_new(char name, long nbr)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->name = name;
	new->nbr = nbr;
	new->target_index = 0;
	new->push_index = 0;
	new->is_pushed_to_end_of_stack = false;
	new->current_index = 0;
	new->is_upper_median = false;
	new->push_price = 0;
	new->cheapest = false;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack)
		ft_stack_last(*stack)->next = new;
	else
		*stack = new;
}
