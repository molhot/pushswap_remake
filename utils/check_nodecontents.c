/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nodecontents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:42:01 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 21:03:45 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	show_node(t_staccontent **a)
{
	t_staccontent	*node;
	t_staccontent	*first;
	int				i;

	node = *a;
	first = *a;
	i = 0;
	if (*a != NULL)
	{
		while (node -> next != *a)
		{
			printf("%d is %d and wedge is %d (0 is false) && sorted is \
			%d\n", i, node->num, node->wedge, node->sorted);
			i++;
			node = node->next;
		}
		printf("%d is %d and wedge is %d (0 is false) && sorted is \
		%d\n", i, node->num, node->wedge, node->sorted);
		*a = first;
	}
	else
		printf("this node is NULL");
}
