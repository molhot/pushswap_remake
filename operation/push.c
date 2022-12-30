/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:05:43 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 19:56:34 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_subfunc(t_staccontent **push, \
t_staccontent *newcontent, t_staccontent **inserted)
{
	newcontent->num = (*push)->num;
	if ((*push)->sorted == true)
		newcontent->sorted = true;
	else
		newcontent->sorted = false;
	newcontent->next = (*inserted);
	newcontent->prev = (*inserted)->prev;
	(*inserted)->prev = newcontent;
	(*inserted)->prev->prev->next = newcontent;
	*push = (*push)->next;
	*inserted = newcontent;
}

void	pushfunc(t_staccontent **inserted, t_staccontent **push)
{
	t_staccontent	*newcontent;
	t_staccontent	*freeaddr;
	size_t			pushlen;

	pushlen = grasp_listlen(push);
	freeaddr = *push;
	newcontent = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	if (newcontent == NULL)
		return ;
	if (freeaddr->wedge)
		newcontent->wedge = true;
	else
		newcontent->wedge = false;
	if (*inserted == NULL)
		*inserted = newcontent;
	if (grasp_listlen(push) != 1)
	{
		(*push)->prev->next = (*push)->next;
		(*push)->next->prev = (*push)->prev;
	}
	push_subfunc(push, newcontent, inserted);
	if (pushlen == 1)
		*push = NULL;
	free(freeaddr);
}

void	pa(t_staccontent **a, t_staccontent **b)
{
	pushfunc(a, b);
	showchar("pa\n");
}

void	pb(t_staccontent **a, t_staccontent **b)
{
	pushfunc(b, a);
	showchar("pb\n");
}
