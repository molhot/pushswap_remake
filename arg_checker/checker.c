/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:28:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/04 21:05:58 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	argument_checker(int arg_num, char **argument)
{
	int		char_num;
	int		arg_counter;
	char	subject;

	char_num = 0;
	arg_counter = 1;
	while (arg_counter != arg_num)
	{
		while (argument[arg_counter][char_num] != '\0')
		{
			subject = argument[arg_counter][char_num];
			if (char_num == 0 && ('0' > subject || \
			'9' < subject) && subject != '-')
				return (false);
			else if (char_num != 0 && ('0' > subject || '9' < subject))
				return (false);
			char_num++;
		}
		arg_counter++;
		char_num = 0;
	}
	return (true);
}

static	bool	dupli_or_not(int arrange_num, t_staccontent *a)
{
	int				subject_num;
	int				i;
	t_staccontent	*a_contain;

	i = 0;
	a_contain = a;
	while (a->next != a_contain)
	{
		subject_num = a->num;
		while (i != arrange_num)
		{
			a = a->next;
			if (subject_num == a->num && i != arrange_num - 1)
				return (false);
			i++;
		}
		a = a->next;
		i = 0;
	}
	return (true);
}

bool	duplication_checker(t_staccontent **a)
{
	size_t			stac_len;
	t_staccontent	*a_checked_node;
	int				*node_arrangement;
	int				arrangement_num;
	bool			dupli;

	stac_len = grasp_listlen(a);
	node_arrangement = (int *)malloc(sizeof(int) * stac_len);
	a_checked_node = (*a);
	arrangement_num = 0;
	while (a_checked_node->next != *a)
	{
		node_arrangement[arrangement_num] = a_checked_node->num;
		a_checked_node = a_checked_node->next;
		arrangement_num++;
	}
	node_arrangement[arrangement_num] = a_checked_node->num;
	a_checked_node = a_checked_node->next;
	dupli = dupli_or_not(stac_len, *a);
	free(node_arrangement);
	return (dupli);
}
