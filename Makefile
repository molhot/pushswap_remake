NAME = push_swap

SRCS = arg_checker/checker.c\
		operation/push.c operation/rotation_reverse.c operation/rotation.c operation/swap.c\
		pattern_two_three/three_p.c pattern_two_three/three_p_help.c pattern_two_three/two_p.c\
		quicksort/quicksort.c quicksort/common_func.c quicksort/first_step.c quicksort/sort_to_wedge_helper.c\
		quicksort/second_step.c\
		sort_checker/sort_checker.c\
		wedge_checker/check_wedge_in_a.c wedge_checker/next_wedge_position.c\
		utils/grasp_listlen.c utils/show_char.c utils/ft_atoi.c utils/check_nodecontents.c\
		pushswap_main.c

OBJS = $(SRCS:.c=.o)

CC = gcc -fsanitize=address -fno-omit-frame-pointer

all : $(NAME)

$(NAME):$(OBJS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY:		all clean fclean re bonus