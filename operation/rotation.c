/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:03:18 by satushi           #+#    #+#             */
/*   Updated: 2022/12/03 19:56:51 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotation(t_staccontent **sub)
{
	*sub = (*sub)->next;
}

void	push_swap_ra(t_staccontent **a)
{
	rotation(a);
	showchar("ra\n");
}

void	push_swap_rb(t_staccontent **b)
{
	rotation(b);
	showchar("rb\n");
}

void	push_swap_rr(t_staccontent **a, t_staccontent **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	showchar("rr\n");
}
