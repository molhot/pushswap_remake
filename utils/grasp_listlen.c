/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_listlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:38:37 by satushi           #+#    #+#             */
/*   Updated: 2023/01/25 12:25:34 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	grasp_listlen(t_staccontent **sublist)
{
	t_staccontent	**sublist_alt;
	t_staccontent	*node;
	size_t			len;

	len = 1;
	if (*sublist == NULL)
		return (0);
	sublist_alt = sublist;
	if ((*sublist_alt)->next == *sublist_alt)
		return (1);
	node = (*sublist_alt)->next;
	while (node != *sublist_alt)
	{
		len++;
		if (len > INT_MAX)
			return (len);
		node = node->next;
	}
	return (len);
}

int	mediam(t_staccontent **sublist)
{
	t_staccontent	**sublist_alt;
	t_staccontent	*node;
	long long		sum;
	size_t			listlen;

	sublist_alt = sublist;
	listlen = (int)grasp_listlen(sublist_alt);
	node = (*sublist_alt)->next;
	sum = node->num;
	while (node != *sublist_alt)
	{
		node = node->next;
		sum += node->num;
	}
	return (sum / (int)listlen);
}

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
	return overaverage_counter;
}

int average(t_staccontent **sublist)
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
		if ((listlen % 2 == 0 && average_helper(sublist, node->num) == (int)listlen / 2) || (listlen % 2 == 1 && average_helper(sublist, node->num) == (int)(listlen + 1) / 2))
		{
			*sublist = f_node;
			return (node->num);
		}
		node = node->next;
	}
	*sublist = f_node;
	return ((*sublist)->num);
}

bool	obtain_minimumnum(t_staccontent **sublist)
{
	t_staccontent	*f_node;
	t_staccontent	*node;
	int				tmp;

	f_node = *sublist;
	node = (*sublist)->next;
	tmp = (*sublist)->num;
	while (node != f_node)
	{
		if (tmp > node->num)
			return (false);
		node = node->next;
	}
	return (true);
}

bool	obtain_minimumnum_nextnode(t_staccontent **sublist)
{
	t_staccontent	*f_node;
	t_staccontent	*node;
	int				tmp;

	f_node = *sublist;
	node = (*sublist)->next->next;
	tmp = (*sublist)->next->num;
	if (tmp > (*sublist)->num)
	{
		*sublist = f_node;
		return (false);
	}
	while (node != f_node)
	{
		if (tmp > node->num)
		{
			*sublist = f_node;
			return (false);
		}
		node = node->next;
	}
	return (true);
}