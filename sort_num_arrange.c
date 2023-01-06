/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num_arrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:22:20 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 18:51:07 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_sorted(t_staccontent **a, t_staccontent **b)
{
	(*b)->sorted = true;
	pa(a, b);
	push_swap_ra(a);
}

void	a_to_a_sorted(t_staccontent **a)
{
	if ((*a)->wedge == true)
		(*a)->wedge = false;
	(*a)->sorted = true;
	push_swap_ra(a);
}
