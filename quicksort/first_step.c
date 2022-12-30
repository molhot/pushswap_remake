/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:08:42 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 08:39:06 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void quicksort_firststep(t_staccontent **a, t_staccontent **b)
{
	size_t	listlen;
	int		a_mediam;
	int		b_mediam;

	listlen = grasp_listlen(a);
	a_mediam = mediam(a);
	while (listlen != 0)
	{
		if (a_mediam >= (*a)->num)
		{
			pb(a, b);
			b_mediam = mediam(b);
			if (b_mediam > (*b)->num)
				push_swap_rb(b);
		}
		else
			push_swap_ra(a);
		listlen--;
	}
}

void divide_less_six_helper(t_staccontent **a, t_staccontent **b, int *judge, int b_mediam)
{
	if (b_mediam <= (*b)->num && *judge == 1)
	{
		*judge = 0;
		(*b)->wedge = true;
		pa(a, b);
	}
	else if (b_mediam <= (*b)->num && *judge == 0)
		pa(a, b);
	else if (b_mediam > (*b)->num)
		push_swap_rb(b);
}

void divide_less_six(t_staccontent **a, t_staccontent **b)
{
	size_t	listlen;
	int		b_mediam;
	int		wedge_flag;

	listlen = grasp_listlen(b);
	wedge_flag = 1;
	while (listlen > 6)
	{
		b_mediam = mediam(b);
		while (listlen != 0)
		{
			divide_less_six_helper(a, b, &wedge_flag, b_mediam);
			listlen--;
		}
		listlen = grasp_listlen(b);
		wedge_flag = 1;
	}
}