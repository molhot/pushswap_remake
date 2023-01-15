/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:34:12 by satushi           #+#    #+#             */
/*   Updated: 2023/01/15 22:34:42 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	digit_or_not(char *arg)
{
	size_t	position;
	char	sub;

	position = 0;
	while (arg[position] != '\0')
	{
		sub = arg[position];
		if (same_argcomp_check(sub, position) == false)
			return (false);
		position++;
	}
	if (position > 11)
		return (false);
	if (position >= 10 && arg_intmaxcheck(arg, position) == false)
		return (false);
	return (true);
}
