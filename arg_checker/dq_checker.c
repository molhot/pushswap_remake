/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dq_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:29:17 by satushi           #+#    #+#             */
/*   Updated: 2023/01/16 20:39:36 by satushi          ###   ########.fr       */
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
	if (position == 0 && (sub != '-' && !('0' <= sub && sub <= '9') && sub != '+'))
		return (false);
	else if (position != 0)
	{
		if (!('0' <= sub && sub <= '9'))
			return (false);
	}
	return (true);
}

// bool	digit_or_not(char *arg)
// {
// 	size_t	position;
// 	char	sub;

// 	position = 0;
// 	while (arg[position] != '\0')
// 	{
// 		sub = arg[position];
// 		if (same_argcomp_check(sub, position) == false)
// 			return (false);
// 		position++;
// 	}
// 	if (position > 11)
// 		return (false);
// 	if (position >= 10 && arg_intmaxcheck(arg, position) == false)
// 		return (false);
// 	return (true);
// }

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
	if (space_checker(arg) == false)
	{
		if (digit_or_not(arg) == false)
			return (false);
		else
			return (true);
	}
	splited_arg = ft_split(arg, ' ');
	if (same_argchecker(splited_arg) == false)
		digit_check = false;
	while (splited_arg[arg_position] != NULL)
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
