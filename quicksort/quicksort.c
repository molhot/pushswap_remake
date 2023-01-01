/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:03:23 by satushi           #+#    #+#             */
/*   Updated: 2023/01/01 20:09:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void quick_sort_main(t_staccontent **a, t_staccontent **b)
{
	int		b_len;

	quicksort_firststep(a, b);
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
	f_step_sort_towedge(a, b); //out.txt　のようなとき　secondstep（はじめに分けた残り二つ）に処理を渡すためにwedge処理をしなければならないが、wedgeの数は6以上もあるのでそれを解消する
	quicksort_secondstep(a, b);
}

//aのwedgeまでを入れる
//6より大きい　456 123の三パターンで行う
void f_step_sort_towedge(t_staccontent **a, t_staccontent **b)
{
	bool	wedge_is_exist;
	
	wedge_is_exist = wedge_in_a(a);
	while (wedge_is_exist == true)
	{
		sort_to_wedge(a, b);
		wedge_is_exist = wedge_in_a(a);
	}
}

void less_threenum(t_staccontent **a, t_staccontent **b)
{
	int i;

	i = 0;
	if (grasp_listlen(b) == 1)
		b_to_a_sorted(a, b);
	else if (grasp_listlen(b) == 2)
	{
		patt_twonum_in_b(b);
		while (i++ != 2)
			b_to_a_sorted(a, b);
		return ;
	}
	else if (grasp_listlen(b) == 3)
	{
		patt_threenum_in_b(b);
		while (i++ != 3)
			b_to_a_sorted(a, b);
		return ;
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