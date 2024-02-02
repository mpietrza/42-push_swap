/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:51:19 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/02 15:55:53 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.c"

int	ft_find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->nbr == nbr)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	ft_find_index_after_push(t_stack *stack, int nbr_pushed)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_pushed > stack->nbr && nbr_pushed < ft_stack_last(stack)->nbr)
		i = 0;
	else if (nbr_pushed > ft_elem_max(stack)
		|| nbr_pushed < ft_elem_min(stack))
		i = ft_find_index(stack, ft_elem_max(stack));
	else
	{
		tmp = stack->next;
		while (stack->nbr < nbr_pushed || tmp->nbr >nbr_pushed)
		{
			stack = stack->next;
			tmp = stack->next;
			i++;
		}
	}
	return (i);
}
