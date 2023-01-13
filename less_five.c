/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:44:50 by satushi           #+#    #+#             */
/*   Updated: 2023/01/13 10:22:45 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_arrange(int *arrangement, t_staccontent **a, size_t a_len)
{
	size_t			i;
	t_staccontent	*node;
	t_staccontent	*f_node;

	f_node = *a;
	node = *a;
	i = 0;
	while (a_len != 0)
	{
		arrangement[i] = node->num;
		i++;
		a_len--;
		node = node->next;
	}
	*a = f_node;
}

size_t	count_under_num(int *arrange, size_t range)
{
	int		tmp_min;
	size_t	counter;

	tmp_min = arrange[0];
	counter = 0;
	while (range != 0)
	{
		if (tmp_min >= arrange[range - 1])
			counter++;
		range--;
	}
	return (counter);
}

int	arrange_sort(int *arrange, size_t	range)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (count_under_num(arrange, range) != ((range + 1) / 2))
	{
		tmp = arrange[0];
		while (i != range - 1)
		{
			arrange[i] = arrange[i + 1];
			i++;
		}
		arrange[i] = tmp;
		i = 0;
	}
	tmp = arrange[0];
	return (tmp);
}

void	move_a_to_b(t_staccontent **a, t_staccontent **b, int tmp)
{
	size_t	a_len;

	a_len = grasp_listlen(a);
	while (a_len != 0)
	{
		if (grasp_listlen(b) == 2)
			return ;
		if (tmp < (*a)->num)
			pb(a, b);
		else
			push_swap_ra(a);
		a_len--;
	}
}

bool	pt_less_five(t_staccontent **a, t_staccontent **b)
{
	size_t	a_len;
	int		*a_copyarrange;
	int		mediam_num;

	a_len = grasp_listlen(a);
	a_copyarrange = (int *)malloc(sizeof(int) * a_len);
	ready_arrange(a_copyarrange, a, a_len);
	mediam_num = arrange_sort(a_copyarrange, a_len);
	move_a_to_b(a, b, mediam_num);
	if (grasp_listlen(a) == 2 && (*a)->num > (*a)->next->num)
		anum_twopt(a, b);
	else
		less_three_sort(a, b);
	if ((*b)->num > (*b)->next->num)
		push_swap_sb(b);
	patt_twonum_in_b(b);
	b_to_a_sorted(a, b);
	b_to_a_sorted(a, b);
	//show_node(a);
	free(a_copyarrange);
	free(b);
	return (free_all_a(a));
}
