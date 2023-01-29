/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:28:43 by satushi           #+#    #+#             */
/*   Updated: 2023/01/29 14:32:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	argument_checker(int arg_num, char **argument)
{
	int		char_num;
	int		arg_counter;
	char	*subject;

	char_num = 0;
	arg_counter = 1;
	if (arg_num == 2)
		return (split_or_return(arg_num, argument));
	while (arg_counter != arg_num)
	{
		subject = argument[arg_counter];
		if (itoa_checker(subject) == false)
			return (false);
		if (arg_overintmaxcheck(subject) == false)
			return (false);
		arg_counter++;
		char_num = 0;
	}
	return (true);
}

static	bool	check_overintmax_free(char *numstring, bool judge)
{
	free (numstring);
	return (judge);
}

bool	arg_overintmaxcheck(char *sub_arg)
{
	char	*num_string;
	int		position;
	int		itoa_position;

	num_string = ft_itoa(ft_atoi(sub_arg));
	position = 0;
	itoa_position = 0;
	if (special_casecheck(sub_arg) == true)
		return (check_overintmax_free(num_string, true));
	if ((sub_arg[0] == '-' && num_string[0] != '-') || \
	(sub_arg[0] == '+' && ft_isdigit(num_string[0]) == 0))
		return (check_overintmax_free(num_string, false));
	if (sub_arg[0] == '-')
		itoa_position++;
	while (*sub_arg == '+' || *sub_arg == '-' || *sub_arg == '0')
		sub_arg++;
	while (sub_arg[position] != '\0')
	{
		if (sub_arg[position] != num_string[itoa_position])
			return (check_overintmax_free(num_string, false));
		position++;
		itoa_position++;
	}
	return (check_overintmax_free(num_string, true));
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
