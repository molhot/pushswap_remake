/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:27:49 by satushi           #+#    #+#             */
/*   Updated: 2023/01/13 16:08:28 by satushi          ###   ########.fr       */
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

t_staccontent	**insertelem_tostack(int counter, char **numstr, bool args_two)
{
	t_staccontent	**a;
	t_staccontent	*node;
	int				i;

	a = list_initialization();
	if (a == NULL)
		return (NULL);
	node = *a;
	if (args_two == true)
		i = 0;
	else
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

void	free_protect_args(char **args)
{
	size_t	args_position;

	args_position = 0;
	while (args[args_position] != NULL)
	{
		free(args[args_position]);
		args_position++;
	}
	free(args);
}

bool	pt_argnum_sortpart(char **num_args_arrange)
{
	t_staccontent	**a;
	t_staccontent	**b;
	size_t			arg_counter;

	arg_counter = 0;
	while (num_args_arrange[arg_counter] != NULL)
		arg_counter++;
	a = insertelem_tostack(arg_counter, num_args_arrange, true);
	if (duplication_checker(a) == false)
		return (false);
	if ((*a)->next == (*a) || sortcheck(a) == true)
		return (free_all_a(a));
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	if (grasp_listlen(a) == 4 || grasp_listlen(a) == 5)
		return (pt_less_five(a, b));
	else
		quick_sort_main(a, b);
	free(b);
	return (free_all_a(a));
}

bool	pt_argnum_2(char *num_args)
{
	char 			**num_args_arrange;
	bool			result;

	num_args_arrange = ft_split(num_args, ' ');
	result = pt_argnum_sortpart(num_args_arrange);
	free_protect_args(num_args_arrange);
	return (result);
}

bool	push_swap(int arg_num, char **num_ch)
{
	t_staccontent	**a;
	t_staccontent	**b;

	if (arg_num == 1 || argument_checker(arg_num, num_ch) == false)
		return (false);
	if (arg_num == 2 && ft_strchr(num_ch[1], ' ') != NULL)
		return (pt_argnum_2(num_ch[1]));
	a = insertelem_tostack(arg_num, num_ch, false);
	if (duplication_checker(a) == false)
		return (false);
	if ((*a)->next == (*a) || sortcheck(a) == true)
		return (free_all_a(a));
	b = list_initialization();
	free(*b);
	(*b) = NULL;
	if (grasp_listlen(a) == 4 || grasp_listlen(a) == 5)
		return (pt_less_five(a, b));
	else
		quick_sort_main(a, b);
	free(b);
	return (free_all_a(a));
}

int	main(int argc, char **argv)
{
	t_staccontent	*node;
	bool			check;

	if (false == push_swap(argc, argv))
		printf("Error\n");
	return (1);
}
