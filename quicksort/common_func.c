/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:21:23 by satushi           #+#    #+#             */
/*   Updated: 2022/12/31 00:46:42 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void b_to_a_sorted(t_staccontent **a, t_staccontent **b)
{
	(*b)->sorted = true;
	pa(a, b);
	push_swap_ra(a);;
}

void a_to_a_sorted(t_staccontent **a)
{
	if ((*a)->wedge == true)
		(*a)->wedge = false;
	(*a)->sorted = true;
	push_swap_ra(a);
}

void wedge_position_over_six(t_staccontent **a, t_staccontent **b)//6以上の時
{
	
}

void wedge_position_under_six(t_staccontent **a, t_staccontent **b)//6以下の時
{
	t_staccontent	*f_node;
	t_staccontent	*node;
	size_t			counter;

	f_node = (*a);
	node = (*a);
}

void sort_to_wedge(t_staccontent **a, t_staccontent **b)
{
	int i;

	i = 0;
	if (obtain_wedgeposition(a) == 1)
		a_to_a_sorted(a);
	else if (obtain_wedgeposition(a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			push_swap_sa(a);
		while (i++ != 2)
			a_to_a_sorted(a);
	}
	else if (obtain_wedgeposition(a) == 3)
		sort_to_wedge_pt3(a, b, (*a)->num, (*a)->next->num, (*a)->next->next->num);
	else if (obtain_wedgeposition(a) < 7)
		wedge_position_under_six(a, b);
	else
		wedge_position_over_six(a, b);
}