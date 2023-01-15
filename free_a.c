/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:57:35 by satushi           #+#    #+#             */
/*   Updated: 2023/01/15 11:24:57 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	free_all_a(t_staccontent **a)
{
	size_t			node_len;
	t_staccontent	*n_node;
	t_staccontent	*node;

	node_len = grasp_listlen(a);
	node = (*a);
	while (node_len != 1)
	{
		n_node = node->next;
		free(node);
		node = n_node;
		node_len--;
	}
	free(node);
	free(a);
	return (true);
}

bool	free_all_a_false(t_staccontent **a)
{
	size_t			node_len;
	t_staccontent	*n_node;
	t_staccontent	*node;

	node_len = grasp_listlen(a);
	node = (*a);
	while (node_len != 1)
	{
		n_node = node->next;
		free(node);
		node = n_node;
		node_len--;
	}
	free(node);
	free(a);
	return (false);
}
