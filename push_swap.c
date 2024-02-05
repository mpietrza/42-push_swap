/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:08:53 by mpietrza          #+#    #+#             */
/*   Updated: 2024/01/31 14:53:28 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_str_num(char *s)
{
	int	i;
	int	j;

	i = 0;
	if (s[0])
	{
		if (s[0] == '-' || ft_isdigit(s[0]))
			i++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (i == ft_strlen(s))
			return (true);
	}
	return (false);
}

bool	ft_stack_init(t_stack **stack, char name, long nbr, long index)
{
	*stack = ft_calloc(1, sizeof(stack));
	if (!*stack)
		return (false);
	(*stack)->name = name;
	(*stack)->nbr = nbr;
	(*stack)->index = index;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	return (true);
}

int	ft_error(t_list *data, int nbr)
{
	nbr = 0;
	data->atoi_error = 1;
	return (nbr);
}

int	ft_atoi_ps(const char *s, t_list *data)
{
	int				i;
	int				sign;
	long long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r' || s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + s[i] - '0';
		i++;
		if ((nbr > ((long long int)INT_MAX + 1) && sign == -1)
			|| (nbr > INT_MAX && sign == 1))
			return (ft_error(data, nbr));
	}
	return (sign * nbr);
}

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

bool	ft_data_parse(t_stack **a, int argc, char **argv, t_list *data)
{
	int	i;
	long	num;

	i = 1;
	*a == NULL;
	while (argv[i])
	{
		num = ft_atoi_ps(argv[i], data);
		if (data->atoi_error == true)
			return (false)
		ft_stack_add_bottom(a, ft_stack_new('a', num));
		i++;
	}
	if (i == argc)
		return (true);
	return (false);
}

bool	ft_duplicate_check(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->nbr == temp->nbr)
				return (false);
			temp = temp->next;
		}
		a = a->next;
	}
	return (true);
}

bool	ft_range_bracket(int argc, t_list *data)
{
	if (ft_duplicate_check(data) == false)
		return (false);
	if (argc == 3 || argc == 4)
		range_xs(data->sa, data);
	else if (argc >= 5 && argc <= 6)
		range_s(data->sa, data);
	else if (argc >=7 && argc <= 100)
		range_m(data);
	else if (argc >= 101)
		range_l(data);
	else
		return (false)
}

void	ft_error_exit(const char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	ft_free_and_exit(t_stack **a, t_stack **b, const char *error_message)
{
	if (*a)
		ft_stack_free(a);
	if (*b)
		ft_stack_free(b);
	ft_error_exit(error_message);
}

void	ft_exit_succesful(t_stack **a, t_stack **b)
	{
	if (*a)
		ft_stack_free(a);
	if (*b)
		ft_stack_free(b);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_stack	**a;
	t_stack	**b;

	if (argc == 1 || ft_check_argv(argc, argv) == false)
		return (1);
	data = calloc(1, sizeof(t_data));
	if (!data)
		ft_error_exit("Error\nMemory allocation failure!\n");
	if (ft_stack_init(&b, b, 0, 0) == false)
		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
	if (ft_data_parse(&a, argc, argv) == false)
		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
	if (ft_init_data_args(data, argc, argv) == false)
		ft_free_and_exit(a, b, data, "Error\nMemory allocation failure!\n");
	if (ft_is_stack_ascending(stack == false)
		ft_free_and_exit(a,b, data, "Error\nWrong order of data on stack A!\n");
	if (ft_range_bracket(argc, a, b, data) == false)
		ft_free_and_exit(a, b, data, "Error\nData input out of range!\n");
	ft_exit_succesful(data);
	return (0);
}
