/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:26:02 by satushi           #+#    #+#             */
/*   Updated: 2023/01/15 22:47:36 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	patt_threenum_in_b(t_staccontent **list)
{
	if ((*list)->num > (*list)->next->num && \
	(*list)->next->num > (*list)->next->next->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
	}
	if ((*list)->next->next->num > (*list)->next->num && \
	(*list)->num > (*list)->next->next->num)
		push_swap_rb(list);
	if ((*list)->num > (*list)->next->num && \
	(*list)->next->next->num > (*list)->num)
		push_swap_sb(list);
	if ((*list)->next->num > (*list)->num && \
	(*list)->num > (*list)->next->next->num)
		push_swap_rrb(list);
	if ((*list)->next->num > (*list)->next->next->num && \
	(*list)->next->next->num > (*list)->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
		push_swap_rrb(list);
	}
}

static	void	all_reverse(t_staccontent **a, t_staccontent **b)
{
	pb(a, b);
	push_swap_sa(a);
	push_swap_ra(a);
	push_swap_ra(a);
	pa(a, b);
	push_swap_ra(a);
}

void	patt_threenum_in_a(t_staccontent **a, t_staccontent **b)
{
	int	i;

	i = 0;
	if ((*a)->num < (*a)->next->num && (*a)->next->num < (*a)->next->next->num)
		all_reverse(a, b);
	else if ((*a)->next->next->num < (*a)->num && (*a)->num < (*a)->next->num)
	{
		push_swap_sa(a);
		all_reverse(a, b);
	}
	else if ((*a)->num < (*a)->next->num && (*a)->next->next->num)
	{
		while (i != 3)
		{
			push_swap_sa(a);
			i++;
		}
	}
	else
		three_pt_helper(a);
}
