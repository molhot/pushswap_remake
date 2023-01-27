/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:37:42 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 04:39:15 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	argment_checker_help(int char_num, char *subject)
{
	if (char_num > 11)
		return (false);
	if (char_num >= 10 && arg_intmaxcheck(subject, char_num) == false)
		return (false);
	return (true);
}
