/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:31:10 by satushi           #+#    #+#             */
/*   Updated: 2023/01/13 15:32:01 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	char		src;
	char		*s_2;
	size_t		num;

	s_2 = (char *)s;
	num = ft_strlen(s_2);
	src = (char)c;
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	if (c == '\0')
		return (s_2 + num);
	while (num != 0)
	{
		if ((unsigned char)*s_2 == (unsigned char)src)
			return (s_2);
		num = num - 1;
		s_2 = s_2 + 1;
	}
	return (NULL);
}
