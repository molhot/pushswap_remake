# include "../push_swap.h"

void show_node(t_staccontent **a)
{
	t_staccontent *node;
	t_staccontent *first;
	node = *a;
	first = *a;
	int i = 0;

	if (*a != NULL)
	{
		while (node -> next != *a)
		{
			printf("%d is %d and wedge is %d (0 is false) && sorted is %d\n", i, node->num, node->wedge, node->sorted);
			i++;
			node = node->next;
		}
		printf("%d is %d and wedge is %d (0 is false) && sorted is %d\n", i, node->num, node->wedge, node->sorted);
		*a = first;
	}
	else
		printf("this node is NULL");
}