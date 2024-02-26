/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:58:57 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/16 16:59:24 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void ft_give_target_index_asc(t_stack **a)
{
    t_stack *temp;
    int index = 0;
    int nbr;
    int prev_nbr;
    int i;

    temp = *a;
    nbr = ft_elem_min(a);
    i = 0;
    while (i < ft_stack_size(a))
    {
        while (temp)
        {
            if (temp->nbr == nbr)
            {
                temp->target_index = index;
                index++;
                prev_nbr = nbr;
                nbr = ft_elem_min_higher_than_given(a, prev_nbr);
                break;
            }
            temp = temp->next;
        }
        temp = *a;
        i++;
    }
}
void ft_give_target_index_desc(t_stack **b)
{
    t_stack *temp;
    int index = 0;
    int nbr;
    int prev_nbr;
    int i;

    temp = *b;
    nbr = ft_elem_max(b);
    i = 0;
    while (i < ft_stack_size(b))
    {
        while (temp)
        {
            if (temp->nbr == nbr)
            {
                temp->target_index = index;
                index++;
                prev_nbr = nbr;
                nbr = ft_elem_max_lower_than_given(b, prev_nbr);
                break;
            }
            temp = temp->next;
        }
        temp = *b;
        i++;
    }
}



void ft_give_push_index_a_to_b(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    t_stack	*temp_b; 
	long	index_best_match; 

    temp_a = *a;
	while (temp_a) 
	{
		index_best_match = LONG_MIN; 
		temp_b = *b; 
        while (temp_b)
		{
			if (temp_b->nbr < temp_a->nbr && temp_b->nbr > index_best_match)
			{
				index_best_match = temp_b->nbr; 
				temp_a->push_index = temp_b->current_index;
			}
			temp_b = temp_b->next;
		}
		if (index_best_match == LONG_MIN)
			temp_a->push_index = ft_stack_size(b); 
		temp_a = temp_a->next;
	}
}

void ft_give_push_index_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *temp;
    t_stack *temp2;
    int nbr;
    int prev_nbr;
    int i;

    temp2 = *b;
    nbr = ft_elem_min(b);
    i = 0;
    while (i < ft_stack_size(b))
    {
        temp = *a;
        while (temp)
        {
            if (temp->nbr > nbr)
            {
                temp2->push_index = temp->current_index;
                prev_nbr = nbr;
                nbr = ft_elem_min_higher_than_given(b, prev_nbr);
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            temp2->target_index = 0;
        }
        temp2 = temp2->next;
        i++;
    }
}

int    ft_give_current_index(t_stack **stack)
{
    t_stack *temp;
    int i;

    if (!*stack || !stack)
        return (-1);
    temp = *stack;
    i = 0;
    while (temp)
    {
        temp->current_index = i;
        temp = temp->next;
        i++;
    }
    return (i);
}