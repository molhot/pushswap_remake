/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:38:45 by satushi           #+#    #+#             */
/*   Updated: 2023/01/25 21:10:10 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	not_sorted_num(t_staccontent **a, t_staccontent **b)
{
	t_staccontent	*node;

	node = *a;
	while (node->sorted == false)
	{
		node = node->next;
		pb(a, b);
		if (average(b) >= (*b)->num)
			push_swap_rb(b);
	}
}

void	quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	size_t	b_len;

	not_sorted_num(a, b);
	b_len = grasp_listlen(b);
	while (b_len > 5)
	{
		divide_less_six(a, b);
		b_len = grasp_listlen(b);
	}
	if (b_len <= 3)
		less_threenum(a, b);
	else
	{
		while (b_len > 3)
		{
			more_threenum(a, b, average(b));
			b_len = grasp_listlen(b);
		}
		less_threenum(a, b);
	}
	f_step_sort_towedge(a, b);
	if ((*a)->next->sorted == true && (*a)->num > (*a)->next->num)
	{
		(*a)->sorted = true;
		(*a)->wedge = false;
		push_swap_ra(a);
	}
}
