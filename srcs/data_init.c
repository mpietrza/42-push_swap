/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:25 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/13 15:09:32 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_data_init(t_data *data, int argc)
{
	data->argv = ft_calloc(1, sizeof(char *));
	if (data->argv == NULL)
		return (false);
	data->argc = argc;
	data->atoi_error = false;
	data->fake_argc = false;
	return (true);
}
