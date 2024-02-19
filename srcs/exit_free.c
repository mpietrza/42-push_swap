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

static void	ft_free_core(t_stack **a, t_stack **b, t_data *data)
{
	int i;
//	int j;

	i = 0;
	if (*a)
	{
		ft_stack_free(a);
		*a = NULL;
		if (!*a)
			ft_printf("Debug point: *a is freed (NULL)\n");
	}
	if (*b && data->argc > 4)
	{
		ft_stack_free(b);
		*b = NULL;
		if (!*b)
			ft_printf("Debug point: *b is freed (NULL)\n");
	}
	if (data)
	{
		if (data->argv)
		{
			while(i <= data->argc)
			{
				//	ft_printf("Debug point: freeing data->argv[%d] = %s\n", i, data->argv[i]);
				if (data->is_argc_fake == true)
					free(data->argv[i]);
			/*
					j = 0;
					while (data->argv[i][j])
					{
						data->argv[i][j] = '\0';
						j++;
					}
				}*/
				data->argv[i] = NULL;
				if (!data->argv[i])
					ft_printf("Debug point: data->argv[%d] is freed (NULL)\n", i);
				i++;
			}
			if (data->is_argc_fake == true)
				free(data->argv);
			data->argv = NULL;
			if (!data->argv)
				ft_printf("Debug point: data->argv is freed (NULL)\n");
		}
		free(data);
		data = NULL;
		if (!data)
			ft_printf("Debug point: data is freed (NULL)\n");
	}
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
