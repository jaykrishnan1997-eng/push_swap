// THIS IS CLAUDE GENERATED !!!
// to run
// cc -Wall -Wextra -Werror AI_main.c helper_fun1.c helper_fun2.c iteration.c operators1.c operators2.c push_swap.h
#include "push_swap.h"

void	append(t_node **head, int value)
{
	t_node	*current;
	t_node	*new;

	new = new_node(value);
	if (!*head)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->content);
		free(head);
		head = tmp;
	}
}

static void	print_list(t_node *head)
{
	while (head)
	{
		printf("%d ", *head->content);
		head = head->next;
	}
	printf("\n");
}

int	main(void)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	append(&a, 3);
	append(&a, 1);
	append(&a, 2);
	append(&a, 8);
	append(&a, 5);
	append(&a, 6);

	printf("before: ");
	print_list(a);
	printf("sorted before: %s\n", is_sorted(a) ? "YES" : "NO");

	insertion_sort(&a, &b);

	printf("after:  ");
	print_list(a);
	printf("sorted after:  %s\n", is_sorted(a) ? "YES" : "NO");

	free_list(a);
	free_list(b);
	return (0);
}