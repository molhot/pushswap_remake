/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_lessthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:05:08 by satushi           #+#    #+#             */
/*   Updated: 2023/01/16 20:32:40 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	pt_less_three_helper(t_staccontent **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->next->num > (*a)->next->next->num)
	{
		push_swap_rra(a);
		push_swap_rra(a);
		push_swap_sa(a);
	}
	if ((*a)->next->num > (*a)->num && (*a)->num > (*a)->next->next->num)
		push_swap_rra(a);
	if ((*a)->next->num > (*a)->next->next->num && (*a)->next->next->num > (*a)->num)
	{
		push_swap_ra(a);
		push_swap_rra(a);
		push_swap_rra(a);
		push_swap_sa(a);
	}
	return (free_all_a(a));
}

bool	pt_less_three(t_staccontent **a, t_staccontent **b)
{
	free(b);
	if (grasp_listlen(a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			push_swap_sa(a);
		return (free_all_a(a));
	}
	if ((*a)->num > (*a)->next->next->num && (*a)->next->next->num > (*a)->next->num)
	{
		push_swap_ra(a);
		return (free_all_a(a));
	}
	if ((*a)->next->next->num > (*a)->num && (*a)->num > (*a)->next->num)
	{
		push_swap_sa(a);
		return (free_all_a(a));
	}
	else
		return (pt_less_three_helper(a));
}