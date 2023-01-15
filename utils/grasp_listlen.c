/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grasp_listlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:38:37 by satushi           #+#    #+#             */
/*   Updated: 2023/01/15 11:31:37 by satushi          ###   ########.fr       */
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
		if (len > (INT_MAX * 2))
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
