/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_wedge_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:55:46 by satushi           #+#    #+#             */
/*   Updated: 2023/01/15 22:48:19 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_pt3_helper2(t_staccontent **a, \
t_staccontent **b, int s, int l)
{
	if (l < s && s < (*a)->num)
	{
		pb(a, b);
		push_swap_sa(a);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
	}
}

static	void	sort_pt3_helper1(t_staccontent **a, \
t_staccontent **b, int s, int l)
{
	if (l < (*a)->num && (*a)->num < s)
	{
		pb(a, b);
		push_swap_sa(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
	}
	else if (s < l && l < (*a)->num)
	{
		pb(a, b);
		a_to_a_sorted(a);
		a_to_a_sorted(a);
		pa(a, b);
		a_to_a_sorted(a);
	}
	else
		sort_pt3_helper2(a, b, s, l);
}

void	sort_to_wedge_pt3(t_staccontent **a, \
t_staccontent **b, int s, int l)
{
	int	i;

	i = 0;
	if ((*a)->num < s && s < l)
		while (i++ != 3)
			a_to_a_sorted(a);
	else if ((*a)->num < l && l < s)
	{
		a_to_a_sorted(a);
		push_swap_sa(a);
		while (i++ != 2)
			a_to_a_sorted(a);
	}
	else if (s < (*a)->num && (*a)->num < l)
	{
		push_swap_sa(a);
		while (i++ != 3)
			a_to_a_sorted(a);
	}
	else
		sort_pt3_helper1(a, b, s, l);
}
