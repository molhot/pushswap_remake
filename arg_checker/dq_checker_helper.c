/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_checker_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:34:12 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 02:36:32 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	digit_or_not(char *arg)
{
	size_t	position;
	char	sub;

	position = 0;
	while (*arg == '0')
		arg++;
	while (arg[position] != '\0')
	{
		sub = arg[position];
		if (same_argcomp_check(arg, sub, position) == false)
			return (false);
		position++;
	}
	if (position > 11)
		return (false);
	if (position >= 10 && arg_intmaxcheck(arg, position) == false)
		return (false);
	return (true);
}
