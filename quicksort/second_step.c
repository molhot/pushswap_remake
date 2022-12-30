/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:38:45 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 15:09:56 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t not_sorted_num(t_staccontent **a)
{
	size_t			counter;
	t_staccontent	*f_node;
	t_staccontent	*node;

	f_node = *a;
	node = *a;
	counter = 0;
	while (node->sorted == false)
	{
		counter++;
		node = node->next;
	}
	return (counter);
}

void quicksort_secondstep(t_staccontent **a, t_staccontent **b)
{
	size_t	counter;

	counter = not_sorted_num(a);
}