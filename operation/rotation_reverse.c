/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:04:20 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 19:57:10 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reversrotation(t_staccontent **subject)
{
	t_staccontent	*head;
	t_staccontent	*tail;
	t_staccontent	*sentinel;

	head = *subject;
	sentinel = (*subject)->prev;
	tail = (*subject)->prev->prev;
	if (head == sentinel)
		return ;
	tail->prev->next = sentinel;
	sentinel->prev = tail->prev;
	tail->prev = sentinel;
	tail->next = head;
	sentinel->next = tail;
	head->prev = tail;
	*subject = sentinel->next;
}

void	push_swap_rra(t_staccontent **a)
{
	*a = (*a)->prev;
	showchar("rra\n");
}

void	push_swap_rrb(t_staccontent **b)
{
	*b = (*b)->prev;
	showchar("rrb\n");
}

void	push_swap_rrr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	showchar("rrr\n");
}
