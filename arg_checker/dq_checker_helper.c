/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_checker_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:34:12 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 07:05:04 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	bool	digit_or_not_helper(size_t *position, bool c_n_f, char *arg)
{
	char	sub;

	while (arg[*position] != '\0')
	{
		if ((arg[*position] == '-' || \
		arg[*position] == '+') && c_n_f == false)
			return (false);
		while (*arg == '0' || *arg == '+' || *arg == '-')
			arg++;
		sub = arg[*position];
		if (same_argcomp_check(arg, sub, (int)*position) == false)
			return (false);
		*position = *position + 1;
	}
	return (true);
}

bool	digit_or_not(char *arg)
{
	size_t	position;
	bool	checker_notf;
	size_t	zero_p;
	char	sub;

	position = 0;
	checker_notf = true;
	while (*arg == '0')
	{
		arg++;
		checker_notf = false;
	}
	if (digit_or_not_helper(&position, checker_notf, arg) == false)
		return (false);
	if (position > 11)
		return (false);
	if (position >= 10 && arg_intmaxcheck(arg, position) == false)
		return (false);
	return (true);
}
