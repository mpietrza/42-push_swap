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

void	ft_data_init(t_data *data, char **argv, int argc, bool is_argc_fake)
{
	data->argv = argv;
	data->argc = argc;
	data->atoi_error = false;
	data->is_int = true;
	data->is_argc_fake = is_argc_fake;
}
