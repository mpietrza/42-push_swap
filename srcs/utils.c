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

int	ft_atoi_ps(char *s, t_data *data)
{
	int				i;
	int				sign;
	long long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (ft_is_str_num(s) == false)
	{
		data->atoi_error = true;
		return (-1);
	}
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
		{
			data->atoi_error = true;
			return (-1);
		}
	}
	return (sign * nbr);
}

int	ft_fake_argc(char *s)
{
	int		i;
	int		fake_argc;
	bool	is_space;

	i = 0;
	fake_argc = 1;
	is_space = true;
	while (s[i] && (s[i] == ' '))
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (is_space == true)
				fake_argc++;
			is_space = false;
		}
		else if (s[i] == ' ')		
			is_space = true;
		i++;
	}
	return (fake_argc);
}

char	**ft_fake_argv(char **argv, int	fake_argc)
{
	char	*s = NULL;
	char	*temp = NULL;
	char	**fake_argv = NULL;
//	int		i;

	fake_argv = ft_calloc(fake_argc, sizeof(char *));
	if (!fake_argv)
		return (NULL);
	temp = ft_strjoin(argv[0], " ");
	s = ft_strjoin(temp, argv[1]);
	free(temp);
	fake_argv = ft_split(s, ' ');
	free(s);
	return (fake_argv);
}

