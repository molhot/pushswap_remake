/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:26:24 by satushi           #+#    #+#             */
/*   Updated: 2023/01/28 02:12:53 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct stac
{
	int			num;
	bool		wedge;
	bool		sorted;
	struct stac	*prev;
	struct stac	*next;
}t_staccontent;

//utils
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *string_row);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
bool			arg_intmaxcheck(char *sub_arg, int num);
int				average(t_staccontent **sublist);

//reverserotation
void			reversrotation(t_staccontent **subject);
void			push_swap_rra(t_staccontent **a);
void			push_swap_rrb(t_staccontent **b);
void			push_swap_rrr(t_staccontent **a, t_staccontent **b);

//rotation
void			rotation(t_staccontent **sub);
void			push_swap_ra(t_staccontent **a);
void			push_swap_rb(t_staccontent **b);
void			push_swap_rr(t_staccontent **a, t_staccontent **b);

//swap
void			push_swap_sa(t_staccontent **a);
void			push_swap_sb(t_staccontent **b);
void			push_swap_ss(t_staccontent **a, t_staccontent **b);

//push
void			pushfunc(t_staccontent **inserted, t_staccontent **push);
void			pa(t_staccontent **a, t_staccontent **b);
void			pb(t_staccontent **a, t_staccontent **b);

//checker
bool			sortcheck(t_staccontent **sublist);
bool			duplication_checker(t_staccontent **a);
bool			argument_checker(int arg_num, char **argument);
bool			split_or_return(int argc, char **argnum);
bool			digit_or_not(char *arg);
bool			same_argcomp_check2(int sub, int position);
bool			same_argcomp_check(char *subject_s, int subject, int char_num);

//two_or_threepattern
void			patt_threenum_in_b(t_staccontent **list);
void			patt_twonum_in_b(t_staccontent **list);
void			three_pt_helper(t_staccontent **a);
void			three_pt_helper_2(t_staccontent **a);
void			patt_threenum_in_a(t_staccontent **a, t_staccontent **b);

//list's basic info
size_t			grasp_listlen(t_staccontent **sublist);
int				mediam(t_staccontent **sublist);

//showing message
void			showchar(char *sub);
void			error_show(void);

//atoi
int				ft_atoi(const char *str);

//initialization
t_staccontent	**list_initialization(void);
void			insert_info_tolist(t_staccontent *nowaddr, \
int n, int last, t_staccontent *f_addr);
t_staccontent	**insertelem_tostack(int counter, char **numstr, bool args_two);

//quicksort
void			quick_sort_main(t_staccontent **a, t_staccontent **b);
void			quicksort_firststep(t_staccontent **a, t_staccontent **b);
void			f_step_sort_towedge(t_staccontent **a, t_staccontent **b);
void			quicksort_secondstep(t_staccontent **a, t_staccontent **b);
void			divide_less_six(t_staccontent **a, t_staccontent **b);
void			less_threenum(t_staccontent **a, t_staccontent **b);
void			more_threenum(t_staccontent **a, \
t_staccontent **b, int b_mediam);
void			sort_to_wedge(t_staccontent **a, t_staccontent **b);
void			less_three_sort(t_staccontent **a, t_staccontent **b);
void			anum_twopt(t_staccontent **a, t_staccontent **b);
bool			obtain_minimumnum_by_wedge(t_staccontent **list);

//minimumsort
bool			pt_less_five(t_staccontent **a, t_staccontent **b);

//quicksort func for common
void			b_to_a_sorted(t_staccontent **a, t_staccontent **b);
void			a_to_a_sorted(t_staccontent **a);
void			sort_to_wedge_pt3(t_staccontent **a, \
t_staccontent **b, int s, int l);

//show_nodecontent errorhandling
void			show_node(t_staccontent **a);

//wedge_checker
bool			wedge_in_a(t_staccontent **a);
size_t			obtain_wedgeposition(t_staccontent **list);

//free
bool			free_all_a(t_staccontent **a);
bool			free_all_a_false(t_staccontent **a);

//special arg
bool			pt_argnum_sortpart(char **num_args_arrange);
bool			pt_argnum_2(char *num_args);
void			free_protect_args(char **args);

//less three
bool			pt_less_three(t_staccontent **a, t_staccontent **b);
bool			obtain_minimumnum(t_staccontent **sublist);
bool			obtain_minimumnum_nextnode(t_staccontent **sublist);

#endif