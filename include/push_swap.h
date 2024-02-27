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
	long			current_index;
	bool			is_upper_median;
	long			push_price;
	bool			cheapest;
//	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*struct - for data transfer thoughout the program*/
typedef struct	s_data
{	
	char	**argv;
	int		argc;
	bool	is_argc_fake;
//	bool	is_chpst_uppr_med_push;
//	bool	is_chpst_uppr_med_source;
//	long	cheapest_push_target_ind;
//	long 	cheapest_push_source_ind;
	bool 	atoi_error;
	bool	is_int;
//	int		j_atoi;
//	int		size_block;
//	int		arg_max;
//	int		arguments;
}				t_data;

/* list of functions */
long	ft_atoi_ps(char *s, t_data *data);
bool	ft_check_argv(int argc, char **argv);
bool	ft_cheapest_move(t_stack **a, t_stack **b);
bool	ft_duplicate_check(t_stack *a);
int		ft_fake_argc(char *s);
char	**ft_fake_argv(char **argv);
void	ft_data_init(t_data *data, char **argv, int argc, bool is_argc_fake);
bool	ft_data_parse(t_stack **a, t_data *data);
void	ft_error_exit(const char *error_message);
void	ft_exit_succesful(t_stack **a, t_stack **b, t_data *data);
void	ft_find_cheapest(t_stack **source, t_stack **target);
void	ft_free_and_exit(t_stack **a, t_stack **b, t_data *data, const char *error_message);
int		ft_elem_max(t_stack **stack);
int		ft_elem_min(t_stack **stack);
int		ft_elem_max_lower_than_given(t_stack **stack, int given);
int		ft_elem_min_higher_than_given(t_stack **stack, int given);
int		ft_give_current_index(t_stack **stack);
void	ft_give_target_index_asc(t_stack **a);
void	ft_give_target_index_desc(t_stack **b);
void	ft_give_push_index_a_to_b(t_stack **a, t_stack **b);
void	ft_give_push_index_b_1_node_to_a(t_stack **b, t_stack **a);
void	ft_give_push_index_b_to_a(t_stack **b, t_stack **a);
void	ft_give_push_price(t_stack **a, t_stack **b);
int		ft_find_nearest_higher(t_stack **stack, int nbr_to_push);
bool	ft_is_stack_asc(t_stack **stack);
bool	ft_is_stack_desc(t_stack **stack);
bool	ft_is_str_num(char *s);
void	ft_print_stack(t_stack **stack);
bool	ft_push(t_stack **stack_1, t_stack **stack_2);
bool	ft_rev_rotate(t_stack **stack);
bool	ft_rr(t_stack **a, t_stack **b);
bool	ft_rrr(t_stack **a, t_stack **b);
bool	ft_rotate(t_stack **stack);
bool	ft_ss(t_stack **a, t_stack **b);
bool	ft_swap(t_stack **stack);
bool	ft_range_bracket(t_stack **a, t_stack **b, t_data *data);
void	ft_range_2(t_stack **a);
void	ft_range_3(t_stack **a);
void	ft_range_4(t_stack **a, t_stack **b);
void	ft_range_s(t_stack **a, t_stack **b, t_data *data);
void	ft_stack_add_bottom(t_stack **stack, t_stack *new);
void	ft_stack_add_top(t_stack **stack, t_stack *new);
void	ft_stack_free(t_stack **stack);
t_stack *ft_stack_last(t_stack *stack);
t_stack *ft_stack_new(char name, long nbr);
int 	ft_stack_size(t_stack **stack);
void	ft_what_rotation(t_stack **a, t_stack **b,
		bool uppr_med_source, bool uppr_med_target);
void    ft_what_rotation_1_stack(t_stack **stack, t_data *data);
//sub_main - need to change name logic
t_data	*sub_main1(int argc, char **argv);

#endif

