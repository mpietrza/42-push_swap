/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:08:53 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:14:12 by mpietrza         ###   ########.fr       */
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
	if (argc == 4)
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
	t_stack	**a = NULL;
	t_stack	**b = NULL;

	if (argc == 1 || ft_check_argv(argc, argv) == false)
		return (1);
	data = calloc(1, sizeof(t_data));
	if (!data)
		ft_error_exit("Error\nMemory allocation failure!\n");
	if (ft_stack_init(b, 'b', 0, 0) == false)
	{
		free(data);
		ft_error_exit("Error\nMemory allocation failure!\n");
	}
	if (ft_data_parse(a, argc, argv, data) == false)
		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
//	if (ft_init_data_args(data, argc, argv) == false)
//		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
	if (ft_is_stack_asc(a) == true)
		ft_exit_succesful(a, b, data);
	if (ft_range_bracket(argc, a) == false)
		ft_free_and_exit(a, b, data, "Error\nInput data error!\n");
	while (*a)
	{
		ft_printf("&d\n", (int)(*a)->nbr);
		(*a) = (*a)->next;
	}
	ft_exit_succesful(a, b, data);
	return (0);
}
