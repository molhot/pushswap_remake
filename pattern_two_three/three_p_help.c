/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_p_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:40:20 by user              #+#    #+#             */
/*   Updated: 2023/01/15 22:47:06 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_pt_helper(t_staccontent **a)
{
	int	i;

	i = 0;
	if ((*a)->num < (*a)->next->next->num && (*a)->next->num)
	{
		push_swap_ra(a);
		push_swap_sa(a);
		push_swap_ra(a);
		push_swap_ra(a);
	}
	else if ((*a)->next->num < (*a)->num && (*a)->num < (*a)->next->next->num)
	{
		push_swap_sa(a);
		while (i != 3)
		{
			push_swap_ra(a);
			i++;
		}
	}
	three_pt_helper_2(a);
}

void	three_pt_helper_2(t_staccontent **a)
{
	if ((*a)->next->num < (*a)->next->next->num && \
	(*a)->next->next->num < (*a)->num)
	{
		push_swap_sa(a);
		push_swap_ra(a);
		push_swap_sa(a);
		push_swap_ra(a);
		push_swap_ra(a);
	}
}
