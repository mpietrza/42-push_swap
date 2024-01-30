/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:08:53 by mpietrza          #+#    #+#             */
/*   Updated: 2024/01/30 18:04:12 by mpietrza         ###   ########.fr       */
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

int	ft_atoi_ps(const char *s, t_list *d)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r' || s[i] == '+' || s[i] == '-')
	{
		if (s[i] = '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = nbr * 10 + s[i] - '0';
		i++;
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
		if (d->atoi_error == true)
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
		if (ft_is_str_num(argv[i] == false) || !argv[i])
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_list	*data;

	if (argc == 1 || ft_check_argv(argc, argv) == false)
		return (1);
	data = ft_calloc(1, sizeof(t_list));
	if (!data)
		return (1);
	if (ft_init_data(data) == false)
	{
		free(data);
		return (1);
	}
//
	return (0);
}
