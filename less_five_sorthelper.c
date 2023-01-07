/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five_sorthelper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:41:20 by user              #+#    #+#             */
/*   Updated: 2023/01/07 13:57:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    less_three_sort(t_staccontent **a, t_staccontent **b)
{
    int next;
    int last;

    next = (*a)->next->num;
    last = (*a)->next->next->num;

    if ((*a)->num < next && next < last)
        return ;
    else if ((*a)->num < last && last < next)
    {
        push_swap_rra(a);
        if ((*b)->num > (*b)->next->num)
			push_swap_ss(a, b);
		else
			push_swap_sa(a);
    }
    else if (next < (*a)->num && (*a)->num < last)
    {
        if ((*b)->num > (*b)->next->num)
			push_swap_ss(a, b);
		else
			push_swap_sa(a);
    }
    else if (last < (*a)->num && (*a)->num < next)
        push_swap_rra(a);
    else if (next < last && last < (*a)->num)
        push_swap_ra(a);
    else if (last < next && next < (*a)->num)
    {
        push_swap_ra(a);
        if ((*b)->num > (*b)->next->num)
			push_swap_ss(a, b);
		else
			push_swap_sa(a);
    }
}