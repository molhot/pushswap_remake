/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:21:23 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 18:50:48 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	over_six_b_to_a(t_staccontent **a, t_staccontent **b)
{
	int		b_med;
	size_t	b_len;
	bool	first_operation;

	b_med = mediam(b);
	b_len = grasp_listlen(b);
	first_operation = true;
	while (b_len != 0)
	{
		if (b_med <= (*b)->num)
		{
			if ((first_operation) == true)
			{
				first_operation = false;
				(*b)->wedge = true;
			}
			pa(a, b);
		}
		else
			push_swap_rb(b);
		b_len--;
	}
}

//aのwedgeが6以上の時
//ここが無駄になっていそう、bに戻す時にもう少し処理を簡略化する方法があるような気がする
void	wedge_position_over_six(t_staccontent **a, t_staccontent **b)
{
	size_t	a_wedge_num;
	size_t	b_len;
	bool	first_operation;

	a_wedge_num = obtain_wedgeposition(a);
	while (a_wedge_num != 0)
	{
		if ((*a)->wedge == true)
			(*a)->wedge = false;
		pb(a, b);
		a_wedge_num--;
	}
	over_six_b_to_a(a, b);
	b_len = grasp_listlen(b);
	first_operation = true;
	while (b_len != 0)
	{
		if (first_operation == true)
		{
			first_operation = false;
			(*b)->wedge = true;
		}
		pa(a, b);
		b_len--;
	}
}

//6以下の時
void	wedge_position_under_six(t_staccontent **a, t_staccontent **b)
{
	size_t			b_len;
	t_staccontent	*node;
	t_staccontent	*f_node;

	while ((*a)->wedge == false)
		pb(a, b);
	pb(a, b);
	node = (*b);
	f_node = (*b);
	b_len = grasp_listlen(b);
	while (node->next != f_node)
	{
		(node)->wedge = false;
		node = node->next;
	}
	(node)->wedge = false;
	while (b_len > 3)
	{
		more_threenum(a, b, mediam(b));
		b_len = grasp_listlen(b);
	}
	less_threenum(a, b);
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
	else if (obtain_wedgeposition(a) < 7)
		wedge_position_under_six(a, b);
	else
		wedge_position_over_six(a, b);
}
