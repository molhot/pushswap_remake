/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:25:16 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 06:18:00 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

void	patt_twonum_in_b(t_staccontent **list)
{
	int	f_num;
	int	s_num;

	f_num = (*list)->num;
	s_num = (*list)->next->num;
	if (f_num > s_num)
		push_swap_sb(list);
}
