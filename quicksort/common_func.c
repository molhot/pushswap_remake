/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:21:23 by satushi           #+#    #+#             */
/*   Updated: 2023/01/01 14:21:37 by user             ###   ########.fr       */
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

//a 7 6 5 4 3 2 1(w)
//b 

void wedge_position_over_six(t_staccontent **a, t_staccontent **b)//6以上の時 ここが無駄になっていそう、bに戻す時にもう少し処理を簡略化する方法があるような気がする
{
	int		b_med;
	size_t	a_wedge_num;
	size_t	b_len;
	bool	first_operation;

	a_wedge_num = obtain_wedgeposition(a);
	while (a_wedge_num != 0)
	{
		if ((*b)->wedge = true)
			(*b)->wedge = false;
		pb(a, b);
		a_wedge_num--;
	}
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

void wedge_position_under_six(t_staccontent **a, t_staccontent **b)//6以下の時
{
	t_staccontent	*f_node;
	t_staccontent	*node;
	size_t			counter;

	f_node = (*a);
	node = (*a);
	counter = 0;
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