#include "../include/push_swap.h"

bool	ft_is_stack_ascending(t_stack *stack)
{
	int	prev_nbr;

	prev_nbr = stack->nbr;
	while (stack)
	{
		if (prev_nbr > stack->nbr)
			return (false);
		prev_nbr = stack->nbr;
		stack = stack->next;
	}
	return (true);
}

