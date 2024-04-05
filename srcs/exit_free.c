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

static void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->argv)
	{
		while (i <= data->argc)
		{
			if (data->is_argc_fake == true)
				free(data->argv[i]);
			data->argv[i] = NULL;
			i++;
		}
		if (data->is_argc_fake == true)
			free(data->argv);
		data->argv = NULL;
	}
	free(data);
	data = NULL;
}

static void	ft_free_core(t_stack **a, t_stack **b, t_data *data)
{
	if (*a)
	{
		ft_stack_free(a);
		*a = NULL;
	}
	if (*b && data->argc > 4)
	{
		ft_stack_free(b);
		*b = NULL;
	}
	if (data)
		ft_free_data(data);
}

void	ft_free_and_exit(t_stack **a, t_stack **b, t_data *data,
		const char *error_message)
{
	ft_free_core(a, b, data);
	ft_error_exit(error_message);
}

void	ft_exit_succesful(t_stack **a, t_stack **b, t_data *data)
{
	ft_free_core(a, b, data);
	exit(EXIT_SUCCESS);
}