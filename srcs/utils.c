/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:52:47 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/09 17:39:39 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_str_num(char *s)
{
	int	i;
//	int	j;

	i = 0;
	if (s[0])
	{
		if (s[0] == '-' || ft_isdigit(s[0]))
			i++;
		while (s[i] && ft_isdigit(s[i]))
			i++;
		if (i == (int)ft_strlen(s))
			return (true);
	}
	return (false);
}

int	ft_error(t_data *data, int nbr)
{
	nbr = 0;
	data->atoi_error = 1;
	return (nbr);
}

int	ft_atoi_ps(const char *s, t_data *data)
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

int	ft_fake_argc(char **argv)
{
	int		i;
	int		fake_argc;
	bool	is_space;

	i = 0;
	fake_argc = 1;
	is_space = false;
	while (argv[1][i])
		if (argv[1][i] == ' ')
			i++;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			if (is_space == true)
				fake_argc++;
			is_space = false;
		}
		else if (argv[1][i] == ' ')		
			is_space = true;
		i++;
	}
	return (fake_argc);
}

char	**ft_fake_argv(char **argv, int fake_argc)
		char *s = NULL;
		char **new_argv = NULL;

		new_argv = malloc(sizeof(char *) * new_argc);
		if (!new_argv)
			return (NULL);
		new_argv[0] = s;
