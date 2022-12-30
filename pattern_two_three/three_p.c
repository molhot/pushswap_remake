/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:26:02 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 06:26:05 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	patt_threenum_in_b(t_staccontent **list)
{
	if ((*list)->num > (*list)->next->num && (*list)->next->num > (*list)->next->next->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
	}
	if ((*list)->next->next->num > (*list)->next->num && (*list)->num > (*list)->next->next->num)
		push_swap_rb(list);
	if ((*list)->num > (*list)->next->num && (*list)->next->next->num > (*list)->num)
		push_swap_sb(list);
	if ((*list)->next->num > (*list)->num && (*list)->num > (*list)->next->next->num)
		push_swap_rrb(list);
	if ((*list)->next->num > (*list)->next->next->num && (*list)->next->next->num > (*list)->num)
	{
		push_swap_rb(list);
		push_swap_sb(list);
		push_swap_rrb(list);
	}
}