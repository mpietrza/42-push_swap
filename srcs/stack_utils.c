#include "../include/push_swap.h"

t_stack	*ft_stack_new(char name, long nbr)
{
	t_stack	*new;

	new = calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->name = name;
	new->nbr = nbr;
	new->current_index = 0;
	new->push_price = 0;
	new->cheapest = false;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (*stack)
		ft_stack_last(*stack)->next = new;
	else
		*stack = new;
}