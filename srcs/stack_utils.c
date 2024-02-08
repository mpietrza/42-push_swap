#include "../include/push_swap.h"

t_stack	*ft_stack_new(char name, long nbr)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->name = name;
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stack_add_top(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (*stack)
			new->next = *stack;
		*stack = new;
	}
}

void	ft_stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack)
		ft_stack_last(*stack)->next = new;
	else
		*stack = new;
}

bool	ft_stack_init(t_stack **stack, char name, long nbr)
{
	*stack = calloc(1, sizeof(t_stack));
	if (!*stack)
		return (false);
	(*stack)->name = name;
	(*stack)->nbr = nbr;
	(*stack)->index = 0;
	(*stack)->next = NULL;
	return (true);
}

