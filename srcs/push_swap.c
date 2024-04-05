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

bool	ft_range_bracket(t_stack **a, t_stack **b, t_data *data)
{
	if (ft_duplicate_check(*a) == false)
		return (false);
	if (data->argc == 2)
		return (true);
	else if (data->argc == 3)
		ft_range_2(a);
	else if (data->argc == 4)
		ft_range_3(a);
	else if (data->argc == 5)
		ft_range_4(a, b);
	else if (data->argc >= 6)
		ft_range_5(a, b);
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
	if (!data)
		ft_error_exit("Error\nMemory allocation for 'data' failure!\n");
	if (argc == 2 && argv[1][0] != ' '
		&& (ft_strchr(argv[1], ' ') != NULL))
	{
		fake_argc = ft_fake_argc(argv[1]);
		if (fake_argc == 0)
			ft_error_exit("Error\nProblem with the data input!\n");
		else if (fake_argc == 1 || fake_argc == 2)
			return (NULL);
		fake_argv = ft_fake_argv(argv);
		if (!fake_argv)
			ft_error_exit("Error\nMemory allocation for 'fake_argv' failure!\n");
	}
	if (fake_argc == 0 && fake_argv == NULL)
		ft_data_init(data, argv, argc, false);
	else if (fake_argc > 0 && fake_argv != NULL)
		ft_data_init(data, fake_argv, fake_argc, true);
	else
		ft_error_exit("Error\nMemory inicialization of 'data' failure!\n");
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data = NULL;
	t_stack	*a = NULL;
	t_stack	*b = NULL;

	if (argc == 1)
		return (0);
	else if (argc == 2
		&& (ft_strchr(argv[1], ' ') == NULL || argv[1][0] == '\0'))
		return (0);
	else
		data = sub_main1(argc, argv);
	if (!data)
		return (0);
	if (ft_data_parse(&a, data) == false)
		ft_free_and_exit(&a, &b, data, "Error\nMemory allocation failure!\n");
	else if (data->atoi_error == true)
		ft_free_and_exit(&a, &b, data, "Error\nInput data error - atoi error!\n");
	else if (data->is_int == false)
		ft_free_and_exit(&a, &b, data,
			"Error\nInput data error - use only numbers in the integer range!\n");
	if (ft_is_stack_asc(&a) == true)
		ft_exit_succesful(&a, &b, data);
	else
		ft_printf("Debug point: stack is not sorted\n");
	if (ft_range_bracket(&a, &b, data) == false)
		ft_free_and_exit(&a, &b, data, "Error\nInput data error - range bracket!\n");
	ft_exit_succesful(&a, &b, data);
	return (0);
}
