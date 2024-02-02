#include "../include/push_swap.h"

bool	ft_is_stack_ascending(t_stack *stack)
{
	int	nbr;

	nbr = stack->nbr;
	while (stack)
	{
		if (nbr > stack->nbr)
			return (false);
		nbr = stack->nbr;
		stack = stack->next;
	}
	return (true);
}

