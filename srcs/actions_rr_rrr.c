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

bool    ft_cheapest_move(t_stack **source, t_stack **target)
{
    t_stack *temp;
    t_stack *temp2;
    bool    uppr_med_source;
    bool    uppr_med_target;

    temp = *source;
    temp2 = *target;
//    uppr_med_source = false;
    uppr_med_target = false;
    while (temp->cheapest == false)
        temp = temp->next;
    if (temp == NULL)
        return (false);
    if ((temp->push_index / ft_stack_size(target)) * 100 < 50)
        uppr_med_target = true;
    else
        uppr_med_target = false;
    uppr_med_source = temp->is_upper_median;
    ft_print_stack(source);
    ft_print_stack(target);
    //ft_what_rotation(source, target, uppr_med_source, uppr_med_target);
    //ft_push(source, target);
    return (true);
}

void ft_what_rotation(t_stack **a, t_stack **b,
    bool uppr_med_source, bool uppr_med_target)
{
    t_stack *temp;
    t_stack *temp2;

    temp = *a;
    temp2 = *b;
    while (temp->cheapest == false || temp2->cheapest == false)
    {
        if (temp->cheapest == false && temp2->cheapest == false)
        {
            if (uppr_med_target == true && uppr_med_source == true)
                ft_rr(a, b);
            else if (uppr_med_target == true && uppr_med_source == false)
            {
                ft_rev_rotate(a);
                ft_rotate(b);
            }
            else if (uppr_med_target == false && uppr_med_source == true)
            {
                ft_rotate(a);
                ft_rev_rotate(b);
            }
            else
                ft_rrr(a, b);
        }
        else if (temp->cheapest == false && temp2->cheapest == true)
        {
            if (uppr_med_source == true)
                ft_rotate(a);
            else
                ft_rev_rotate(b);
        }
        else if (temp->cheapest == true && temp2->cheapest == false)
        {
            if (uppr_med_target == true)
                ft_rotate(b);
            else
                ft_rev_rotate(b);
        }
        else
            break;
        temp = *a;
        temp2 = *b;
    }
    ft_printf("Debug: rotation successful\n");

}
