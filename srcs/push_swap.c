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

bool	ft_range_bracket(int argc, t_stack **a)
{
	if (ft_duplicate_check(*a) == false)
		return (false);
	if (argc == 2)
		return (true);
	else if (argc == 3)
		ft_range_2(a);
	else if (argc == 4)
		ft_range_3(a);
//	else if (argc >= 5 && argc <= 6)
//		ft_range_s();
//	else if (argc >=7 && argc <= 100)
//		ft_range_m(data);
//	else if (argc >= 101)
//		range_l(data);
	else
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;
//	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	**temp = NULL;

	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL && argv[1][0] != '\0')
	{
		argc = ft_fake_argc(argv[1]);
		ft_printf("Debug point: fake argc = %d\n", argc);
		temp = argv;
		ft_printf("Debug point: temp = %s\n", temp[1]);
		if (ft_fake_argv(temp, argc) == false)
		{
			ft_printf("Debug point: fake argv = %s\n", temp[1]);
			ft_error_exit("Error\nMemory allocation failure!\n");
		}
	//	if (temp)
	//		free(temp);
	}
	else if (argc == 2 && (ft_strchr(argv[1], ' ') == NULL || argv[1][0] == '\0'))
		return (0);
	data = calloc(1, sizeof(t_data));
	ft_printf("Debug point: data created\n");
	if (!data)
		ft_error_exit("Error\nMemory allocation failure!\n");
	if (ft_stack_init(&b, 'b', 0) == false)
	{
		free(data);
		ft_error_exit("Error\nMemory allocation failure!\n");
	}
	else
		ft_printf("Debug point: stack 'b' created\n");
//	if (ft_stack_init(&a, 'a', 0) == false)
//	{
		if (data)
			free(data);
		if (b)
			ft_stack_free(&b);
		while (*argv)
		{
			ft_printf("Debug point: argv[0] = %s\n",  *argv++);
		}
		ft_error_exit("Error\nMemory allocation failure!\n");
/*	}
	else
	{
		ft_printf("Debug point: stack 'a' created\n");
		while (a)
		{
			printf("stack value = %d\n", (int)a->nbr);
			(a) = (a)->next;
		}
	}
	if (ft_data_parse(&a, argc, argv, data) == false)
		ft_free_and_exit(&a, &b, data, "Error\nMemory allocation failure!\n");
	else
		ft_printf("Debug point: data parsed to stack 'a'\n");
//	if (ft_init_data_args(data, argc, argv) == false)
//		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
	if (ft_is_stack_asc(&a) == true)
	{
		ft_printf("Debug point: stack is sorted\n");
		ft_exit_succesful(&a, &b, data);
	}
	else
		ft_printf("Debug point: stack is not sorted\n");
	if (ft_range_bracket(argc, &a) == false)
	{
		ft_free_and_exit(&a, &b, data, "Error\nInput data error!\n");
	}
	else
		ft_printf("Debug point: range bracket\n");
	while (a)
	{
		ft_printf("%d\n", (int)a->nbr);
		(a) = (a)->next;
	}
	ft_exit_succesful(&a, &b, data);
	return (0);*/
}
