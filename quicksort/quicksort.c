/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:03:23 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 08:54:28 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void quick_sort_main(t_staccontent **a, t_staccontent **b)
{
	int		b_len;
	bool	wedge_is_exist;

	quicksort_firststep(a, b);
	divide_less_six(a, b);
	b_len = grasp_listlen(b);
	if (b_len <= 3)
		less_threenum(a, b);
	else
	{
		while (b_len > 3)
		{
			more_threenum(a, b, mediam(b));
			b_len = grasp_listlen(b);
		}
		wedge_is_exist = wedge_in_a(a);
		while (wedge_is_exist == true)
		{
			sort_to_wedge(a, b);
			wedge_is_exist = wedge_in_a(a);
		}
	}
	quicksort_secondstep(a, b);
}

void less_threenum(t_staccontent **a, t_staccontent **b)
{
	int i = 0;

	if (grasp_listlen(b) == 1)
		b_to_a_sorted(a, b);
	else if (grasp_listlen(b) == 2)
	{
		patt_twonum_in_b(b);
		while (i++ != 2)
			b_to_a_sorted(a, b);
	}
	else if (grasp_listlen(b) == 3)
	{
		patt_threenum_in_b(b);
		while (i++ != 3)
			b_to_a_sorted(a, b);
	}
}

void more_threenum(t_staccontent **a, t_staccontent **b, int b_mediam)
{
	int		b_len;
	int		b_len_half;
	bool	f_moved;

	f_moved = true;
	b_len = grasp_listlen(b);
	while (b_len != 0)
	{
		if ((*b)->num >= b_mediam)
		{
			if (f_moved == true)
			{
				(*b)->wedge = true;
				f_moved = false;
			}
			pa(a, b);
		}
		else
			push_swap_rb(b);
		b_len--;
	}
}

//for check func
// printf("---------\n");
// show_node(a);
// printf("---------\n");
// show_node(b);
// printf("---------\n");