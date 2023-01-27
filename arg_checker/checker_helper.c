/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:37:42 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 08:10:07 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// bool	argment_checker_help(int char_num, char *subject)
// {
// 	if (char_num > 11)
// 		return (false);
// 	if (char_num >= 10 && arg_intmaxcheck(subject, char_num) == false)
// 		return (false);
// 	return (true);
// }

bool	arg_intmax_help(char *sub, char *num_string, int position)
{
	int	itoa_position;

	if (num_string[0] == '-' || num_string[0] == '+')
		itoa_position = 1;
	else
		itoa_position = 0;
	while (sub[position] != '\0')
	{
		if (sub[position] != num_string[itoa_position])
		{
			free (num_string);
			return (false);
		}
		position++;
		itoa_position++;
	}
	free(num_string);
	return (true);
}
