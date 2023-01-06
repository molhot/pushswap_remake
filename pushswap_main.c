/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:27:49 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 19:06:47 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_staccontent	**list_initialization(void)
{
	t_staccontent	**subject_list;

	subject_list = (t_staccontent **)malloc(sizeof(t_staccontent *) * 1);
	if (subject_list == NULL)
		return (NULL);
	*subject_list = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	if (*subject_list == NULL)
	{
		free(subject_list);
		return (NULL);
	}
	return (subject_list);
}

void	insert_info_tolist(t_staccontent *nowaddr, \
int n, int last, t_staccontent *f_addr)
{
	if (n == last)
		nowaddr->next = f_addr;
	else
		nowaddr->next = (t_staccontent *)malloc(sizeof(t_staccontent) * 1);
	nowaddr->next->prev = nowaddr;
	nowaddr->wedge = false;
	nowaddr->sorted = false;
}

t_staccontent	**insertelem_tostack(int counter, char **numstr)
{
	t_staccontent	**a;
	t_staccontent	*node;
	int				i;

	a = list_initialization();
	if (a == NULL)
		return (NULL);
	node = *a;
	i = 1;
	while (i != counter)
	{
		insert_info_tolist(node, i, counter - 1, *a);
		node->num = ft_atoi(numstr[i]);
		node = node->next;
		i++;
	}
	return (a);
}

bool	push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;
	bool			dupli_check;

	if (arg_num == 1)
		return (false);
	if (argument_checker(arg_num, num_ch) == false)
		return (false);
	a = insertelem_tostack(arg_num, num_ch);
	dupli_check = duplication_checker(a);
	if (dupli_check == false)
		return (false);
	if ((*a)->next == (*a) || sortcheck(a) == true)
	{
		free_all_a(a);
		return (true);
	}
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	quick_sort_main(a, b);
	free(b);
	free_all_a(a);
	return (true);
}

int	main(int argc, char **argv)
{
	t_staccontent	*node;
	bool			check;

	if (false == push_swap(argc, argv))
		printf("Error\n");
	return (1);
}
