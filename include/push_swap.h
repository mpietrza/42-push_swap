/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:16:23 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/06 17:14:17 by mpietrza         ###   ########.fr       */
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
	long			push_price;
	bool			cheapest;
//	struct s_stack	*prev;
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

/* list of functions */
int		ft_atoi_ps(const char *s, t_data *data);
bool	ft_data_parse(t_stack **a, int argc, char **argv, t_data *data);
bool	ft_duplicate_check(t_stack *a);
void	ft_error_exit(const char *error_message);
void	ft_free_and_exit(t_stack **a, t_stack **b, t_data *data,
		const char *error_message);
int		ft_fake_argc(char *s);
char	**ft_fake_argv(char **argv, int fake_argc);
void	ft_exit_succesful(t_stack **a, t_stack **b, t_data *data);
bool	ft_push(t_stack **stack_1, t_stack **stack_2);
bool	ft_rev_rotate(t_stack **stack);
bool	ft_rrr(t_stack **a, t_stack **b);
bool	ft_rotate(t_stack **stack);
bool	ft_rr(t_stack **a, t_stack **b);
bool	ft_swap(t_stack **stack);
bool	ft_ss(t_stack **a, t_stack **b);
bool	ft_check_argv(int argc, char **argv);
bool	ft_range_bracket(int argc, t_stack **a);
void	ft_range_2(t_stack **a);
void	ft_range_3(t_stack **a);
bool	ft_stack_init(t_stack **stack, char name, long nbr);
t_stack	*ft_stack_new(char name, long nbr);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_top(t_stack **stack, t_stack *new);
void	ft_stack_add_bottom(t_stack **stack, t_stack *new);
int		ft_elem_min(t_stack **stack);
int		ft_elem_max(t_stack **stack);
int		ft_stack_size(t_stack **stack);
bool	ft_is_stack_asc(t_stack **stack);
void	ft_give_index(t_stack **stack);
int		ft_find_index(t_stack **stack, int nbr);
int		ft_find_index_after_push(t_stack **stack, int nbr_pushed);
void	ft_stack_free(t_stack **stack);
bool	ft_is_str_num(char *s);
int		ft_error(t_data *data, int nbr);

#endif
