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
typedef struct		s_stack
{
	char			name;
	long			nbr;
	long			target_index;
	long			push_index;
	bool			is_pushed_to_end_of_stack;
	long			current_index;
	bool			is_upper_median;
	long			push_price;
	bool			cheapest;
	struct s_stack	*next;
}					t_stack;

/*struct - for data transfer thoughout the program*/
typedef struct	s_data
{
	char		**argv;
	int			argc;
	bool		is_argc_fake;
	bool 		atoi_error;
	int			atoi_sign;
	bool		is_int;
}				t_data;

/***************************** list of functions ******************************/
/*actions_rr_rrr.c*/
bool	ft_cheapest_move(t_stack **b, t_stack **a);
void    ft_final_rotations(t_stack **a);

/*data_parse_preparation.c*/
void	ft_data_init(t_data *data, char **argv, int argc, bool is_argc_fake);
bool	ft_data_parse(t_stack **a, t_data *data);
bool	ft_duplicate_check(t_stack *a);
bool	ft_check_argv(int argc, char **argv);

/*exit_free.c*/
void	ft_error_exit(const char *error_message);
void	ft_free_and_exit(t_stack **a, t_stack **b, t_data *data,
	const char *error_message);
void	ft_exit_succesful(t_stack **a, t_stack **b, t_data *data);

/*find_cheapest.c*/
bool	ft_find_cheapest(t_stack **b, t_stack **a);

/*give_index.c*/
void	ft_give_target_index_asc(t_stack **a);
void	ft_give_push_index_b_1_node_to_a(t_stack **b, t_stack **a);
void	ft_give_push_index_b_to_a(t_stack **b, t_stack **a);
long	ft_give_current_index(t_stack **stack);

/*give_push_price.c*/
void	ft_give_push_price(t_stack **b, t_stack **a);

/*oprs_push.c*/
bool	ft_push(t_stack **stack_1, t_stack **stack_2);

/*oprs_r_rotate.c*/
bool	ft_rev_rotate(t_stack **stack);
bool	ft_rrr(t_stack **a, t_stack **b);

/*oprs_rotate.c*/
bool	ft_rotate(t_stack **stack);
bool	ft_rr(t_stack **a, t_stack **b);

/*opr_swap.c*/
bool	ft_swap(t_stack **stack);
bool	ft_ss(t_stack **a, t_stack **b);

/*!!!!!!push_swap.c!!!!!!*/
bool	ft_range_bracket(t_stack **a, t_stack **b, t_data *data);
void	string_to_args(t_data *data, int argc, char **argv);

/*range_3.c*/
void	ft_range_2(t_stack **a);
void	ft_range_3(t_stack **a);

/*range_s.c*/
void	ft_range_4(t_stack **a, t_stack **b);
void	ft_range_5(t_stack **a, t_stack **b);

/*stack_utils.c*/

t_stack *ft_stack_new(char name, long nbr);
t_stack *ft_stack_last(t_stack *stack);
void	ft_stack_add_bottom(t_stack **stack, t_stack *new);

/*stack_utils2.c*/
long	ft_elem_min(t_stack **stack);
long	ft_elem_min_higher_than_given(t_stack **stack, int given);
long	ft_elem_max(t_stack **stack);
long 	ft_stack_size(t_stack **stack);
void	ft_stack_print(t_stack **stack);

/*stack_utils3.c*/
bool	ft_is_stack_asc(t_stack **stack);
void	ft_stack_free(t_stack **stack);
bool	ft_is_stack_asc_rollover(t_stack **stack);

/*utils.c*/
bool	ft_is_str_num(char *s);
long	ft_atoi_ps(char *s, t_data *data);
int		ft_fake_argc(char *s);
char	**ft_fake_argv(char **argv);

/*what_rotation.c*/
void    ft_what_rotation(t_stack **a, t_stack **b,
    	bool uppr_med_a, bool uppr_med_b);
void    ft_what_rotation_end_of_stack_a(t_stack **a, t_stack **b,
    	bool uppr_med_a, bool uppr_med_b);
		
#endif