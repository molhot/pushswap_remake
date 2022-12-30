/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_wedge_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:55:46 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 08:22:13 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_pt3_helper2(t_staccontent **a, t_staccontent **b, int f, int s, int l)
{
	if (l < s && s < f)
	{
		pb(a, b);
		push_swap_sa(a);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
	}
}

static void sort_pt3_helper1(t_staccontent **a, t_staccontent **b, int f, int s, int l)
{
	int i;

	i = 0;
	if (l < f && f < s)
	{
		pb(a, b);
		push_swap_sa(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
	}
	else if (s < l && l < f)
	{
		pb(a, b);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
	}
	else
		sort_pt3_helper2(a, b, f, s, l);
}

void sort_to_wedge_pt3(t_staccontent **a, t_staccontent **b, int f, int s, int l)
{
	int i;

	i = 0;
	if (f < s && s < l)
		while (i++ != 3)
			a_to_a_sorted(a);
	else if (f < l && l < s)
	{
		a_to_a_sorted(a);
		push_swap_sa(a);
		while (i++ != 2)
			a_to_a_sorted(a);
	}
	else if (s < f && f < l)
	{
		push_swap_sa(a);
		while (i++ != 3)
			a_to_a_sorted(a);
	}
	else
		sort_pt3_helper1(a, b, f, s, l);
}