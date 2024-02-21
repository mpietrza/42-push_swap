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

int	ft_elem_min_higher_than_given(t_stack **stack, int given)
{
	t_stack	*temp;
	int	i;

	if (!*stack || !stack)
		return (INT_MAX);
	temp = *stack;
	i = INT_MAX;
	while (temp)
	{
		if (temp->nbr < i && temp->nbr > given)
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
	t_stack	*temp = NULL;

	if (!*stack)
		return (0);
	i = 1;
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_print_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	while (temp)
	{
		ft_printf("name = %c, nbr = %d, target_index = %d, current_index = %d, is_upper_median = %d, push_index = %d, push_price = %d, cheapest = %d\n",
			temp->name, (int)temp->nbr, (int)temp->target_index, (int)temp->current_index, (int)temp->is_upper_median, (int)temp->push_index, (int)temp->push_price, (int)temp->cheapest);
		temp = temp->next;
	}
}
