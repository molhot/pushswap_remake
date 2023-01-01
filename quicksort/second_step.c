/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:38:45 by satushi           #+#    #+#             */
/*   Updated: 2023/01/01 20:29:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void not_sorted_num(t_staccontent **a, t_staccontent **b)
{
	t_staccontent	*node;

	node = *a;
	while (node->sorted == false)
	{
		node = node->next;
		pb(a, b);
	}
}

void quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	size_t	counter;
	size_t	b_len;

	not_sorted_num(a, b);
	b_len = grasp_listlen(b);
	while (b_len > 6)
	{
		divide_less_six(a, b);
		b_len = grasp_listlen(b);
	}
	if (b_len <= 3)// bの6以下の際の対応方法、かつ3以下
		less_threenum(a, b);
	else// bの6以下、かつ3より大きい
	{
		while (b_len > 3)
		{
			more_threenum(a, b, mediam(b));
			b_len = grasp_listlen(b);
		}
		less_threenum(a, b);
	}//ここまでfstep　b　の処理を記載している
	f_step_sort_towedge(a, b);
}