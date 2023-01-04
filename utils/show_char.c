/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:40:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 21:03:20 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	size_t	obtain_strlen(char *sub)
{
	size_t	strlen;

	strlen = 0;
	while (sub[strlen] != '\0')
		strlen++;
	return (strlen);
}

void	showchar(char *sub)
{
	size_t	char_len;

	char_len = obtain_strlen(sub);
	write(1, sub, char_len);
}

void	error_show(void)
{
	char	*error_message;

	error_message = "Error\n";
	write(1, error_message, 7);
}
