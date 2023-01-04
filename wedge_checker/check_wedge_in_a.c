/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wedge_in_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:22:11 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 20:57:54 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	wedge_in_a(t_staccontent **a)
{
	t_staccontent	*f_node;
	t_staccontent	*node;

	f_node = *a;
	node = *a;
	while (node->next != f_node)
	{
		if (node->wedge == true)
		{
			*a = f_node;
			return (true);
		}
		node = node->next;
	}
	if (node->wedge == true)
	{
		*a = f_node;
		return (true);
	}
	*a = f_node;
	return (false);
}
