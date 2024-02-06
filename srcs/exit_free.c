/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:56:12 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 16:45:06 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_exit(const char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	ft_free_and_exit(t_stack **a, t_stack **b, t_data *data,
		const char *error_message)
{
	if (*a)
		ft_stack_free(a);
	if (*b)
		ft_stack_free(b);
	if (data)
		free(data);
	ft_error_exit(error_message);
}

void	ft_exit_succesful(t_stack **a, t_stack **b, t_data *data)
	{
	if (*a)
		ft_stack_free(a);
	if (*b)
		ft_stack_free(b);
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
}
