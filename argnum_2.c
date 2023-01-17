/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argnum_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <sakata19991214@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:05:57 by satushi           #+#    #+#             */
/*   Updated: 2023/01/17 22:59:57 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

bool	pt_argnum_2(char *num_args)
{
	char	**num_args_arrange;
	bool	result;

	num_args_arrange = ft_split(num_args, ' ');
	result = pt_argnum_sortpart(num_args_arrange);
	free_protect_args(num_args_arrange);
	return (result);
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
	if (grasp_listlen(a) == 2 || grasp_listlen(a) == 3)
		return (pt_less_three(a, b));
	if (grasp_listlen(a) == 4 || grasp_listlen(a) == 5)
		return (pt_less_five(a, b));
	else
		quick_sort_main(a, b);
	free(b);
	return (free_all_a(a));
}
