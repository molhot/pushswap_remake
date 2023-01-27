/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:29:17 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 08:41:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	space_checker(char *arg)
{
	if (ft_strchr(arg, ' ') == NULL)
		return (false);
	else
		return (true);
}

bool	same_argcomp_check2(int sub, int position)
{
	if (position == 0 && (sub != '-' && \
	!('0' <= sub && sub <= '9') && sub != '+'))
		return (false);
	else if (position != 0)
	{
		if (!('0' <= sub && sub <= '9'))
			return (false);
	}
	return (true);
}

bool	same_argchecker(char **arg)
{
	size_t	argposition;

	argposition = 0;
	while (arg[argposition] != NULL)
	{
		if (digit_or_not(arg[argposition]) == false)
			return (false);
		argposition++;
	}
	return (true);
}

bool	checker_argnum(char *arg)
{
	size_t	arg_position;
	bool	digit_check;
	char	**splited_arg;

	arg_position = 0;
	digit_check = true;
	if (arg[0] == '\0')
		return (false);
	if (space_checker(arg) == false)
		return (digit_or_not(arg));
	splited_arg = ft_split(arg, ' ');
	if (same_argchecker(splited_arg) == false)
		digit_check = false;
	while (splited_arg != NULL && splited_arg[arg_position] != NULL)
	{
		free(splited_arg[arg_position]);
		arg_position++;
	}
	free(splited_arg);
	return (digit_check);
}

bool	split_or_return(int argc, char **argnum)
{
	if (argc == 2)
	{
		if (checker_argnum(argnum[1]) == false)
			return (false);
		else
			return (true);
	}
	else
		return (false);
}
