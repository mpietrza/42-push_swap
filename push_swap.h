/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:16:23 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/01 17:48:48 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

/*struct - stack*/
typedef struct	s_stack
{
	char			name;
	long			nbr;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*struct - for data transfer thoughout the program*/
typedef struct	s_data
{
	int		num_of_args;
	int		percentage;
	int		lsp;
	int		control;
	int		cont;
	int		error;
	bool 		atoi_error;
	int		j_atoi;
	int		size_block;
	int		arg_max;
	int		arguments;
}				t_data;



#endif
