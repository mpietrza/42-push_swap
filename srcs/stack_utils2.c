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
 
long	ft_elem_min(t_stack **stack)
{
	t_stack	*temp;
	long	nbr;

	if (!*stack || !stack)
		return (INT_MAX);
	temp = *stack;
	nbr = temp->nbr;
	while (temp)
	{
		if (temp->nbr < nbr)
			nbr = temp->nbr;
		temp = temp->next;
	}
	return (nbr);
}

long	ft_elem_min_higher_than_given(t_stack **stack, int given)
{
	t_stack	*temp;
	long	nbr;

	if (!*stack || !stack)
		return (INT_MAX);
	temp = *stack;
	nbr = INT_MAX;
	while (temp)
	{
		if (temp->nbr < nbr && temp->nbr > given)
			nbr = temp->nbr;
		temp = temp->next;
	}
	return (nbr);
}

long	ft_elem_max(t_stack **stack)
{
	t_stack	*temp;
	long	nbr;

	if (!*stack || !stack)
		return (INT_MIN);
	temp = *stack;
	nbr = temp->nbr;
	while (temp)
	{
		if (temp->nbr > nbr)
			nbr = temp->nbr;
		temp = temp->next;
	}
	return (nbr);
}

long	ft_stack_size(t_stack **stack)
{
	long	size;
	t_stack	*temp = NULL;

	if (!*stack)
		return (0);
	size = 1;
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

/*void	ft_stack_print(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	ft_printf("\nSTACK %c:\n", (*stack)->name);
	while (temp)
	{
		ft_printf("name = %c, nbr = %d, target_index = %d, push_index = %d, current_index = %d, is_upper_median = %d, push_price = %d, cheapest = %d\n",
			temp->name, (int)temp->nbr, (int)temp->target_index, (int)temp->push_index, (int)temp->current_index, (int)temp->is_upper_median, (int)temp->push_price, (int)temp->cheapest);
		temp = temp->next;
	}
	ft_printf("------------------------------------------------------------------------------------------------------------\n\n");
}*/