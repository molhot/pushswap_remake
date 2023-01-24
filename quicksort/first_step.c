/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:08:42 by satushi           #+#    #+#             */
/*   Updated: 2023/01/24 22:51:57 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	size_t	listlen;
	size_t	tmp_listlen;
	int		a_mediam;
	int		b_mediam;

	listlen = grasp_listlen(a);
	tmp_listlen = grasp_listlen(a);
	a_mediam = average(a);
	while (listlen != 0)
	{
		if (a_mediam > (*a)->num)
		{
			pb(a, b);
			b_mediam = average(b);
			if (grasp_listlen(b) != 1)
			{
				if (b_mediam >= (*b)->num && (*a)->num > average(a))
					push_swap_rr(a, b);
				// else if (b_mediam >= (*b)->num)
				// 	push_swap_rb(b);
			}
		}
		else
			push_swap_ra(a);
		if ((tmp_listlen % 2 == 0 && (tmp_listlen / 2) == grasp_listlen(b)) || (tmp_listlen % 2 == 1 && (tmp_listlen / 2 + 1) == grasp_listlen(b)))
			return ;
		listlen--;
	}
}

void	divide_less_six_helper(t_staccontent **a, t_staccontent **b, \
int *judge, int b_mediam)
{
	if (b_mediam < (*b)->num && *judge == 1)
	{
		*judge = 0;
		(*b)->wedge = true;
		pa(a, b);
	}
	else if (b_mediam < (*b)->num && *judge == 0)
		pa(a, b);
	else if (b_mediam >= (*b)->num)
		push_swap_rb(b);
}

void	divide_less_six(t_staccontent **a, t_staccontent **b)
{
	size_t	listlen;
	size_t	half_listlen;
	int		b_mediam;
	int		wedge_flag;

	listlen = grasp_listlen(b);
	wedge_flag = 1;
	while (listlen > 6)
	{
		half_listlen = listlen / 2;
		b_mediam = average(b);
		while (listlen != 0 && ((grasp_listlen(b) % 2 == 0 && grasp_listlen(b) != half_listlen) || (grasp_listlen(b) % 2 == 1 && grasp_listlen(b) != half_listlen + 1)))
		{
			divide_less_six_helper(a, b, &wedge_flag, b_mediam);
			listlen--;
		}
		listlen = grasp_listlen(b);
		wedge_flag = 1;
	}
}
