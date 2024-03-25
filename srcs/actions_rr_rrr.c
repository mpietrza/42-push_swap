/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rr_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:46:46 by mpietrza          #+#    #+#             */
/*   Updated: 2024/02/20 18:48:22 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void ft_stack_reset(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        temp->cheapest = false;
        temp->is_upper_median = false;
        if (temp->name == 'a')
            temp->push_index = 0;
        temp = temp->next;
    }
    ft_give_current_index(stack);
}

void ft_what_rotation(t_stack **a, t_stack **b,
    bool uppr_med_a, bool uppr_med_b)
{
    if ((*a)->cheapest == false && (*b)->cheapest == false)
    {
        if (uppr_med_a == true && uppr_med_b == true)
            ft_rr(a, b);
        else if (uppr_med_a == true && uppr_med_b == false)
        {
            ft_rotate(a);
            ft_rev_rotate(b);
        }
        else if (uppr_med_a == false && uppr_med_b == true)
        {
            ft_rev_rotate(a);
            ft_rotate(b);
        }
        else if (uppr_med_a == false && uppr_med_b == false)
            ft_rrr(a, b);
    }
    else if ((*a)->cheapest == false && (*b)->cheapest == true)
    {
        if (uppr_med_a == true)
            ft_rotate(a);
        else
            ft_rev_rotate(a);
    }
    else if ((*a)->cheapest == true && (*b)->cheapest == false)
    {
        if (uppr_med_b == true)
            ft_rotate(b);
        else
           ft_rev_rotate(b);
    }
}

bool    ft_cheapest_move(t_stack **b, t_stack **a)
{
    t_stack *temp;

    bool    uppr_med_a;
    bool    uppr_med_b;

    temp = *b;
    uppr_med_b = false;
    uppr_med_a = false;
    while (temp->cheapest == false)
        temp = temp->next;
    if (temp == NULL)
        return (false);
    if ((temp->push_index / ft_stack_size(a)) * 100 < 50)
        uppr_med_a = true;
    else
        uppr_med_a = false;
    uppr_med_b = temp->is_upper_median;
    if ((*b)->push_index == ft_stack_size(a))
    {
        ft_printf("Debug point: cheapest move 1\n");
        while ((*a)->target_index != 0)
        {
            if (uppr_med_a == true)
                ft_rotate(a);
            else if (uppr_med_a == false)
                ft_rev_rotate(a);
            else
                return (false);
        }
    }
    else
    {
        ft_printf("Debug point: cheapest move 2\n");
        while ((*a)->cheapest == false || (*b)->cheapest == false)
        {
            ft_what_rotation(a, b, uppr_med_a, uppr_med_b);
            ft_give_push_index_b_to_a(b, a);
        }
    }
    ft_push(b, a);
    ft_give_target_index_asc(a);
    ft_stack_reset(a);
    ft_stack_reset(b);
    return (true);
}

void    ft_final_rotations(t_stack **a)
{
    if ((*a)->target_index <= ft_stack_size(a) / 2)
    {
        ft_printf("Debug point: final rotations 1\n");
        while ((*a)->target_index != 0)
            ft_rev_rotate(a);
    }
    else
    {
        ft_printf("Debug point: final rotations 2\n");
        while ((*a)->target_index != 0)
            ft_rotate(a);
    }
}
    