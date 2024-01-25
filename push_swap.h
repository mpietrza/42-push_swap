/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:16:23 by mpietrza          #+#    #+#             */
/*   Updated: 2024/01/25 19:01:43 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

/*struct - for data transfer thoughout the program*/
typedef struct s_list
{
	int	*sa;
	int *sb;
	int	*sp;
	int	sia;
	int	sib;
	int	sip;
	int	num_of_args;
	int	percentage;
	int	lsp;
	int	control;
	int	cont;
	int	error;
	int atoi_error;
	int	j_atoi;
	int	size_block;
	int	arg_max;
	int	arguments;
}			t_list;



#endif
