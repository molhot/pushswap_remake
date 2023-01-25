/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:21:23 by satushi           #+#    #+#             */
/*   Updated: 2023/01/25 17:57:47 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	more_threelen_pt(t_staccontent **a, t_staccontent **b, size_t b_len)
{
	while (b_len > 3)
	{
		while (obtain_minimumnum(b) == true && grasp_listlen(b) > 3)
			b_to_a_sorted(a, b);
		while (obtain_minimumnum_nextnode(b) == true && grasp_listlen(b) > 3)
		{
			push_swap_sb(b);
			b_to_a_sorted(a, b);
		}
		if (grasp_listlen(b) > 3)
			more_threenum(a, b, average(b));
		b_len = grasp_listlen(b);
	}
	less_threenum(a, b);
}

void	wedge_position_under_six(t_staccontent **a, t_staccontent **b)
{
	size_t			b_len;
	t_staccontent	*node;
	t_staccontent	*f_node;

	while ((*a)->wedge == false)
	{
		pb(a, b);
		if ((*b)->num < average(b) && grasp_listlen(b) != 1)
			push_swap_rb(b);
	}
	pb(a, b);
	if ((*b)->num < average(b))
		push_swap_rb(b);
	node = (*b);
	f_node = (*b);
	b_len = grasp_listlen(b);
	while (node->next != f_node)
	{
		(node)->wedge = false;
		node = node->next;
	}
	(node)->wedge = false;
	more_threelen_pt(a, b, b_len);
}

void	sort_to_wedge(t_staccontent **a, t_staccontent **b)
{
	int	i;

	i = 0;
	if (obtain_wedgeposition(a) == 1)
	{
		(*a)->wedge = false;
		(*a)->sorted = true;
		push_swap_ra(a);
	}
	else if (obtain_wedgeposition(a) == 2)
	{
		if ((*a)->num > (*a)->next->num)
			push_swap_sa(a);
		while (i++ != 2)
			a_to_a_sorted(a);
	}
	else if (obtain_wedgeposition(a) == 3)
		sort_to_wedge_pt3(a, b, (*a)->next->num, (*a)->next->next->num);
	else
		wedge_position_under_six(a, b);
}

bool obtain_minimumnum_by_wedge(t_staccontent **list)
{
	t_staccontent	*f_node;
	t_staccontent	*node;
	int				tmp;

	node = *list;
	f_node = *list;
	tmp = f_node->num;
	while (node->wedge == false)
	{
		if (tmp > node->num)
		{
			*list = f_node;
			return (false);
		}
		node = node->next;
	}
	if (tmp > node->num)
	{
		*list = f_node;
		return (false);
	}
	*list = f_node;
	return (true);
}
