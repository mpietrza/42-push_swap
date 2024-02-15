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

t_data	*sub_main1(int argc, char **argv)
{
	int		fake_argc;
	char	**fake_argv = NULL;
	t_data	*data;

	fake_argc = 0;
	data = calloc(1, sizeof(t_data));
	ft_printf("Debug point: data created\n");
	if (!data)
		ft_error_exit("Error\nMemory allocation for 'data' failure!\n");
	if (argc == 2 && argv[1][0] != ' '
		&& (ft_strchr(argv[1], ' ') != NULL))
	{
		fake_argc = ft_fake_argc(argv[1]);
		ft_printf("Debug point: fake_argc created\n");
		fake_argv = ft_fake_argv(argv, fake_argc);
		if (!fake_argv)
			ft_error_exit("Error\nMemory allocation for 'fake_argv' failure!\n");
		ft_printf("Debug point: fake_argv initialized\n");
	}
	if (fake_argc == 0 && fake_argv == NULL)
	{
		ft_data_init(data, argv, argc, false);
		ft_printf("Debug point: data initialized without fake argv and argc\n");
	}
	else if (fake_argc > 0 && fake_argv != NULL)
	{
		ft_data_init(data, fake_argv, fake_argc, true);
		ft_printf("Debug point: data initialized with fake argv and argc\n");
	}
	else
		ft_error_exit("Error\nMemory inicialization of 'data' failure!\n");
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data = NULL;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*temp = NULL;

	if (argc == 1)
		return (0);
	else if (argc == 2
		&& (ft_strchr(argv[1], ' ') == NULL || argv[1][0] == '\0'))
		return (0);
	else
		data = sub_main1(argc, argv);
	if (data->argc > 4)
	{
		b = ft_stack_new('b', 0);
		if (!b)
			ft_error_exit("Error\nMemory allocation for stack 'b' failure!\n");
		else
			ft_printf("Debug point: stack 'b' created\n");
	}
	a = ft_stack_new('a', 0);
	if (!a)
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
	else if (data->atoi_error == true)
		ft_free_and_exit(&a, &b, data, "Error\nInput data error!\n");
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
