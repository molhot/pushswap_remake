/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wedge_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:35:14 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 20:58:11 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	obtain_wedgeposition(t_staccontent **list)
{
	size_t			counter;
	t_staccontent	*node;
	t_staccontent	*f_node;

	counter = 0;
	node = *list;
	f_node = *list;
	while (node->wedge != true)
	{
		counter++;
		node = node->next;
	}
	*list = f_node;
	return (counter + 1);
}
