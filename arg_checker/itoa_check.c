/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:58:00 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 09:16:48 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool itoa_checker(char *string)
{
    size_t  position;

    position = 0;
    if (ft_strlen(string) == 1 && (string[0] == '-' || string[0] == '+'))
        return (false);
    if (string[position] == '-' || string[position] == '+')
        position++;
    while (string[position] == '0')
        position++;
    while (string[position] != '\0')
    {
        if (string[position] == '-' || string[position] == '+' || ft_isdigit(string[position] == 0))
            return (false);
        position++;
    }
    return (true);
}