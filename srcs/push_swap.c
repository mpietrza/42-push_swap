/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:08:53 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/07 15:51:14 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_is_str_num(argv[i]) == false || !argv[i])
			return (false);
	}
	return (true);
}

bool	ft_range_bracket(t_data *data, t_stack **a)
{
	if (ft_duplicate_check(*a) == false)
		return (false);
	if (data->argc == 2)
		return (true);
	else if (data->argc == 3)
		ft_range_2(a);
	else if (data->argc == 4)
		ft_range_3(a);
//	else if (data->argc >= 5 && argc <= 6)
//		ft_range_s(a, b, data);
//	else if (data->argc >=7 && argc <= 100)
//		ft_range_m(a, b, data);
//	else if (data->argc >= 101)
//		ft_range_l(a, b, data);
	else
		return (false);
	return (true);
}

static void	ft_argv_copy(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->argc)
	{
		data->argv[i] = ft_strdup(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*temp = NULL;

	if (argc == 1)
		return (0);
	else if (argc == 2
		&& (ft_strchr(argv[1], ' ') == NULL || argv[1][0] == '\0'))
		return (0);
	data = calloc(1, sizeof(t_data));
	ft_printf("Debug point: data created\n");
	if (!data)
		ft_error_exit("Error\nMemory allocation for 'data' failure!\n");
	if (ft_data_init(data, argc) == false)
	{
		free(data);
		ft_error_exit("Error\nMemory inicialization of 'data' failure!\n");
	}
	else
		ft_printf("Debug point: data initialized\n");	
	if (data->argc == 2 && argv[1][0] != ' '
		&& (ft_strchr(argv[1], ' ') != NULL))
	{
		ft_fake_argc(data, argv[1]);
		if (ft_fake_argv(argv, data) == false)
			ft_free_and_exit(&a, &b, data, "Error\nMemory allocation failure!\n");
		else
			ft_printf("Debug point: fake argc and argv created\n");
	}
	else
	{
		ft_argv_copy(argv, data);
		ft_printf("Debug point: argv copied to data\n");
	}
	if (data->argc > 4)
	{
		if (ft_stack_init(&b, 'b', 0) == false)
			ft_error_exit("Error\nMemory allocation for stack 'b' failure!\n");
		else
			ft_printf("Debug point: stack 'b' created\n");
	}
	if (ft_stack_init(&a, 'a', 0) == false)
	{
		if (data)
			free(data);
		if (b)
			ft_stack_free(&b);
		while (*data->argv)
		{
			ft_printf("Debug point: argv[0] = %s\n",  *data->argv++);
		}
		ft_error_exit("Error\nMemory allocation failure!\n");
	}
	else
	{
		ft_printf("Debug point: stack 'a' created\n");
	}
	if (ft_data_parse(&a, data) == false)
		ft_free_and_exit(&a, &b, data, "Error\nMemory allocation failure!\n");
	else
		ft_printf("Debug point: data parsed to stack 'a'\n");
	if (ft_is_stack_asc(&a) == true)
	{
		ft_printf("Debug point: stack is sorted\n");
		ft_exit_succesful(&a, &b, data);
	}
	else
		ft_printf("Debug point: stack is not sorted\n");
	if (ft_range_bracket(data, &a) == false)
	{
		ft_free_and_exit(&a, &b, data, "Error\nInput data error!\n");
	}
	else
	{
		ft_printf("Debug point: sorting done\n");
		temp = a;
		while (temp)
		{
			ft_printf("Debug point: index = %d, value = %d\n", temp->index, temp->nbr);
			temp = temp->next;
		}
	}
	ft_exit_succesful(&a, &b, data);
	return (0);
}
