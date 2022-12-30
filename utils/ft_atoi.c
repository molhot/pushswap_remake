/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:43:55 by satushi           #+#    #+#             */
/*   Updated: 2022/12/30 03:44:17 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	for_longmax(int pm)
{
	if (pm == 0)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

static int	sub_num(const char *first, int counter, int p_m)
{
	long	digit;
	long	sum;
	long	sum_before;

	digit = 1;
	sum = 0;
	while (counter-- != 0)
		digit = digit * 10;
	while (digit != 0)
	{
		sum_before = sum;
		sum = sum + (*first - 48) * digit;
		if (sum_before > sum)
			return (for_longmax(p_m));
		digit = digit / 10;
		first = first + 1;
	}
	if ((sum > 2147483647) && (p_m % 2 == 0))
		return ((int)sum);
	else if ((sum > 2147483648) && (p_m % 2 == 1))
		return ((int)(-sum));
	if (p_m % 2 == 1)
		sum = sum * (-1);
	return (sum);
}

int	ft_atoi(const char *str)
{
	int		plus_or_minus;
	int		counter;

	counter = 0;
	plus_or_minus = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str = str + 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			plus_or_minus = 1;
		str = str + 1;
	}
	while (*str == '0')
		str = str + 1;
	while ('0' <= *str && *str <= '9')
	{
		counter = counter + 1;
		if (counter >= 20)
			return (for_longmax(plus_or_minus));
		str = str + 1;
	}
	if (counter == 0)
		return (0);
	return (sub_num(str - counter, counter - 1, plus_or_minus));
}