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

static void	ft_init_data_free(t_list *data)
{
	if (data)
	{
		if (data->sa)
			free(data->sa);
		if (data->sb)
			free(data->sb);
		if (data->sp)
			free(data->sp);
		free(data);
	}
}

bool	ft_init_data(t_list *data)
{
	data->sa = ft_calloc(data->num_of_args, sizeof(int));
	data->sb = ft_calloc(data->num_of_args, sizeof(int));
	data->sp = ft_calloc(data->num_of_args, sizeof(int));
	if (!data->sa || !data->sb || !data->sp)
	{
		ft_init_data_free(data);
		return (false);
	}
	data->sia = data->num_of_args;
	data->sib = 0;
	data->sip = data->num_of_args;
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

bool	ft_init_data_args(t_list *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_is_str_num(argv[i] == false))
			return (false);
		data->sa[i - 1] = ft_atoi_ps(argv[i], data);
		if (data->atoi_error == true)
			return (false);
		data->sp[i - 1] = ft_atoi_ps(argv[i], data);
		i++;
	}
	return (true);
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

bool	ft_check_order(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->num_of_args - 1)
	{
		if (data->sa[i] < data->sa[i + 1])
			j++;
		i++;
	}
	if (i == j)
		return (false);
	return (true);
}

static bool	ft_duplic_check_core(t_list *d, int nbr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (data->sa[j] == nbr)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_duplicate_check(t_list *d)
{
	int	i;

	i = 0;
	while (i <= data->sia - 1)
	{
		if (ft_duplicate_check_core(data, data->sa[i], i) == true)
			i++;
		else
			return (false);
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

void	ft_free_data(t_list *data)
{
	if (data)
	{
		if (data->sa)
		{
			free(data->sa);
			if (data->sa)
				data->sa = NULL;
		}
		if (data->sb)
		{
			free(data->sb);
			if (data->sb)
				data->sb = NULL;
		}
		if (data->sp)
		{
			free(data->sp);
			if (data->sp)
				data->sp = NULL;
		}
		free(data);
		if (data)
			data = NULL;
	}
}

void	ft_free_and_exit(t_data *data, const char *error_message)
{
	if (data)
		ft_free_data(data);
	ft_error_exit(error_message);
}

void	ft_exit_succesful(t_data *data)
	{
	if (data)
		ft_free_data(data);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc == 1 || ft_check_argv(argc, argv) == false)
		return (1);
	data = ft_calloc(1, sizeof(t_list));
	if (!data)
		ft_error_exit("Error\nMemory allocation failure!\n");
//		return (1);
	if (ft_init_data(data) == false)
	{
		ft_free_and_exit(data, "Error\nMemory allocation failure!\n");
//		return (1);
	}
	if (ft_init_data_args(data, argc, argv) == false)
	{
		ft_free_and_exit(data, "Error\nMemory allocation failure!\n");
//		return (1);
	}
	if (ft_check_order(data) == false)
		ft_free_and_exit(data, "Error\nWrong order of data on stack A!\n");
//		return (1);
	if (ft_range_bracket(argc, data) == false)
		ft_free_and_exit(data, "Error\nData input out of range!\n");
//		return (1);
	ft_exit_succesful(data);
	return (0);
}
