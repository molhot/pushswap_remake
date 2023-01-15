/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:48:37 by user              #+#    #+#             */
/*   Updated: 2023/01/15 13:50:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	counter_digit(long num)
{
	int	digit;

	digit = 0;
	if (num < 0)
	{
		digit = digit + 1;
		num = -(num);
	}
	while (num != 0)
	{
		digit = digit + 1;
		num = num / 10;
	}
	return (digit);
}

static char	*insertfunc(long num, char (*box), int counternum)
{
	long	num_c;

	num_c = num;
	if (num < 0)
	{
		counternum = counternum - 1;
		num_c = -(num);
	}
	*box = '\0';
	box = box - 1;
	while (counternum-- != 0)
	{
		*box = num_c % 10 + '0';
		box = box - 1;
		num_c = num_c / 10;
	}
	if (num < 0)
		*box = '-';
	else
		box = box + 1;
	return (box);
}

char	*ft_itoa(int n)
{
	int		counter_num;
	char	*c_b;
	char	*firstaddress;
	long	long_num;

	long_num = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	counter_num = counter_digit(long_num);
	c_b = (char *)malloc(sizeof(char) * (counter_num + 1));
	if (c_b == NULL)
		return (NULL);
	firstaddress = insertfunc(long_num, c_b + counter_num, counter_num);
	return (firstaddress);
}
