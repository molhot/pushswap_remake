/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:27:49 by satushi           #+#    #+#             */
/*   Updated: 2023/01/06 13:43:14 by satushi          ###   ########.fr       */
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

void	free_all_a(t_staccontent **a)
{
	size_t			node_len;
	t_staccontent	*n_node;
	t_staccontent	*node;

	node_len = grasp_listlen(a);
	node = (*a);
	while (node_len != 1)
	{
		n_node = node->next;
		free(node);
		node = n_node;
		node_len--;
	}
	free(node);
	free(a);
}

void	push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;
	bool			argment_letimacy;
	bool			dupli_check;

	if (arg_num == 1)
		return ;
	argment_letimacy = argument_checker(arg_num, num_ch);
	if (argment_letimacy == false)
		return ;
	a = insertelem_tostack(arg_num, num_ch);
	dupli_check = duplication_checker(a);
	if (dupli_check == false)
		return ;
	if ((*a)->next == (*a))
		return ;
	if (sortcheck(a) == true)
	{
		printf("a len is %ld\n", grasp_listlen(a));
		free_all_a(a);
		return ;
	}
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	quick_sort_main(a, b);
	free(b);
	free_all_a(a);
}

int	main(int argc, char **argv)
{
	t_staccontent	*node;
	t_staccontent	**a;
	int				i;

	i = 0;
	push_swap(argc, argv);
	if (a == NULL && argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	else if (a == NULL && argc == 1)
	{
		//printf("\n");
		return (1);
	}
	node = (*a);
	while (node->next != *a)
	{
		//printf("|%d is %d && wedge is %d && sorted is %d|\n" ,i, node->num, node->wedge, node->sorted);
		node = node->next;
		i++;
	}
	//printf("|%d is %d && wedge is %d && sorted is %d|\n" ,i, node->num, node->wedge, node->sorted);
	return (1);
}
