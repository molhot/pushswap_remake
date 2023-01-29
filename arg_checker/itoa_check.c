/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:58:00 by satushi           #+#    #+#             */
/*   Updated: 2023/01/29 14:33:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	itoa_checker(char *string)
{
	size_t	position;

	position = 0;
	if (ft_strlen(string) == 1 && (string[0] == '-' || string[0] == '+'))
		return (false);
	if (string[position] == '-' || string[position] == '+')
		position++;
	while (string[position] == '0')
		position++;
	while (string[position] != '\0')
	{
		if (string[position] == '-' || string[position] == '+' \
		|| ft_isdigit(string[position] == 0))
			return (false);
		position++;
	}
	return (true);
}

bool	special_casecheck(char *string)
{
	size_t	position;

	position = 0;
	if (string[position] != '-')
		return (false);
	position++;
	while (string[position] == '0' && string[position] != '\0')
		position++;
	if (string[position] == '\0' && ft_strlen(string) == position)
		return (true);
	return (false);
}
