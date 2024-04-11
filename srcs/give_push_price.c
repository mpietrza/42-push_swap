//missing header//
//

#include "../include/push_swap.h"

static void	ft_check_stack_median(t_stack **stack, long median)
{
	t_stack	*temp;
	long	i;
	
	temp = *stack;
	i = 0;
	while (temp)
	{
		if (i < median)
			temp->is_upper_median = true;
		else
			temp->is_upper_median = false;
		temp = temp->next;
		i++;
	}
}

static void	ft_give_push_price_core(t_stack **b, t_stack **a, long median_a)
{
	t_stack	*temp_b;

	temp_b = *b;
	while (temp_b)
	{
		if (temp_b->push_index <= median_a && temp_b->is_upper_median == true)
			temp_b->push_price = temp_b->push_index + temp_b->current_index;
		else if (temp_b->push_index > median_a && temp_b->is_upper_median == false)
		{
			temp_b->push_price = ft_stack_size(a) - temp_b->push_index
				+ ft_stack_size(b) - temp_b->current_index;
		}
		else if (temp_b->push_index > median_a && temp_b->is_upper_median == true)
		{
			temp_b->push_price = ft_stack_size(a) - temp_b->push_index
				+ temp_b->current_index;
		}
		else if (temp_b->push_index <= median_a && temp_b->is_upper_median == false)
		{
			temp_b->push_price = temp_b->push_index
				+ ft_stack_size(b) - temp_b->current_index;
		}
		temp_b = temp_b->next;
	}
}

void	ft_give_push_price(t_stack **b, t_stack **a)
{
	long	median_a;

	if ((*a) == NULL || (*b) == NULL || a == NULL || b == NULL)
	{
		ft_printf("Error\nStack is NULL\n");
		return ;
	}
	median_a = ft_stack_size(a) / 2;
	ft_check_stack_median(a, median_a);
	ft_give_push_price_core(b, a, median_a);
}