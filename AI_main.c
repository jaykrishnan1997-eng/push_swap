#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;
	int		*content;

	node = malloc(sizeof(t_node));
	content = malloc(sizeof(int));
	if (!node || !content)
		return (NULL);
	*content = value;
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

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

int	main(void)
{
	t_node *a;

	// test1, sorted
	a = NULL;
	append(&a, 1);
	append(&a, 2);
	append(&a, 3);
	append(&a, 4);
	append(&a, 5);
	append(&a, 6);
	printf("sorted [1,2,3,4,5,6] : %s\n", is_sorted(a) ? "YES" : "NO");
	free_list(a);

	// test2, unsorted
	a = NULL;
	append(&a, 1);
	append(&a, 2);
	append(&a, 3);
	append(&a, 8);
	append(&a, 5);
	append(&a, 6);
	printf("sorted [1,2,3,4,5,6] : %s\n", is_sorted(a) ? "YES" : "NO");
	free_list(a);

	// test3 traverse backward
	a = NULL;
	append(&a,10);
	append(&a,20);
	append(&a,30);
	t_node *tail = a;
	while (tail->next)
		tail = tail->next;
	printf("backwards [30,20,10]: ");
	while (tail)
	{
		printf("%d ", *tail->content);
		tail = tail->prev;
	}
	printf("\n");
	free_list(a);
	return (0);

}