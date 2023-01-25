/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_listinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:10:52 by satushi           #+#    #+#             */
/*   Updated: 2023/01/25 21:12:19 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	average_helper(t_staccontent **list, int sub)
{
	size_t			listlen;
	int				overaverage_counter;
	t_staccontent	*node;
	t_staccontent	*n_f_node;

	listlen = (int)grasp_listlen(list);
	node = *list;
	n_f_node = *list;
	overaverage_counter = 0;
	while (listlen != 0)
	{
		if (node->num >= sub)
			overaverage_counter++;
		node = node->next;
		listlen--;
	}
	*list = n_f_node;
	return (overaverage_counter);
}

int	average(t_staccontent **sublist)
{
	t_staccontent	**sublist_alt;
	t_staccontent	*node;
	t_staccontent	*f_node;
	size_t			listlen;

	sublist_alt = sublist;
	listlen = (int)grasp_listlen(sublist_alt);
	node = (*sublist_alt)->next;
	f_node = *sublist_alt;
	while (node != f_node)
	{
		if ((listlen % 2 == 0 && average_helper(sublist, node->num) == \
		(int)listlen / 2) || (listlen % 2 == 1 \
		&& average_helper(sublist, node->num) == (int)(listlen + 1) / 2))
		{
			*sublist = f_node;
			return (node->num);
		}
		node = node->next;
	}
	*sublist = f_node;
	return ((*sublist)->num);
}