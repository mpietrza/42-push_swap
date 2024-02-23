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

bool    ft_cheapest_move_b_to_a(t_stack **a, t_stack **b, t_data *data)
{
    t_stack *temp;
    t_stack *temp2;

    temp = *a;
    temp2 = *b;

    while (temp2->cheapest == false)
        temp2 = temp2->next;
    if (temp2 == NULL)
        return (false);
    data->cheapest_push_target_ind_a = temp2->target_index;
    if (temp2->target_index / ft_stack_size(a) * 100 < 50)
        data->is_chpst_uppr_med_a = true;
    else
        data->is_chpst_uppr_med_a = false;
    data->cheapest_push_source_ind_b = temp2->current_index;
    data->is_chpst_uppr_med_b = temp2->is_upper_median;
    while (temp->current_index != data->cheapest_push_target_ind_a)
        temp = temp->next;
    if (temp == NULL)
        return (false);
    temp->cheapest = true;
    ft_what_rotation(a, b, data);
    ft_push(b, a);
    ft_print_stack(a);
    ft_print_stack(b);
    return (true);
}

void ft_what_rotation(t_stack **a, t_stack **b, t_data *data)
{
    t_stack *temp;
    t_stack *temp2;

    temp = *a;
    temp2 = *b;
    while (temp->cheapest != true && temp2->cheapest != true)
    {
//        ft_printf("a->chpst = %d, cur_ind = %d\nb->chpst = %d, cur_ind = %d\n",
//            (int)temp->cheapest, (int)temp->current_index, (int)temp2->cheapest,
//            (int)temp2->current_index);
        if (temp->cheapest != 0 && temp2->cheapest != 0)
        {
            if (data->is_chpst_uppr_med_a == true
                && data->is_chpst_uppr_med_b == true)
                ft_rr(a, b);
            else if (data->is_chpst_uppr_med_a == true
                && data->is_chpst_uppr_med_b == false)
            {
                ft_rotate(a);
                ft_rev_rotate(b);
            }
            else if (data->is_chpst_uppr_med_a == false
                && data->is_chpst_uppr_med_b == true)
            {
                ft_rev_rotate(a);
                ft_rotate(b);
            }
            else
                ft_rrr(a, b);
        }
        else if (temp->cheapest != 0 && temp2->cheapest == 0)
        {
            if (data->is_chpst_uppr_med_a == true)
                ft_rotate(a);
            else
                ft_rev_rotate(a);
        }
        else if (temp->cheapest == 0 && temp2->cheapest != 0)
        {
            if (data->is_chpst_uppr_med_b == true)
                ft_rotate(b);
            else
                ft_rev_rotate(b);
        }
        temp = *a;
        temp2 = *b;
    }
}
