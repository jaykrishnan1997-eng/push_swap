/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay-k <jay-k@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:02:17 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/18 21:25:53 by jay-k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// t_node creation function
t_node	*new_t_node(int num)
{
	t_node	*newn;

	newn = malloc(sizeof(t_node));
	if (!newn)
		return (NULL);
	newn->content = malloc(sizeof(int));
	if (!newn->content)
		return (free(newn),NULL);
	*newn->content = num;
	newn->index = 0;
	newn->next = NULL;
	newn->prev = NULL;
	return (newn);
}

int	is_sorted(t_node *a)
{
	t_node	*current;

	if (a == NULL)
		return (1);
	current = a;
	while (current != NULL && current->next != NULL)
	{
		if (*current->content > *current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
int	stack_size(t_node *a)
{
	int		size;
	t_node	*current;

	if (a == NULL)
		return (0);
	current = a;
	size = 0;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
int	find_max(t_node *b)
{
	int		max;
	t_node	*current;
	int		index;

	if (!b)
		return (0);
	current = b;
	max = *current->content;
	index = 1;
	while (current != NULL )
	{
		if (*current->content > max)
			max = *current->content;
		current = current->next;
		index++;
	}
	return (index);
}

int	find_min(t_node *b)
{
	int		min;
	t_node	*current;
	int		index;

	if (!b)
		return (0);
	current = b;
	min = *current->content;
	index = 1;
	while (current != NULL )
	{
		if (*current->content < min)
			min = *current->content;
		current = current->next;
		index++;
	}
	return (index);
}

void	
int	insertion_sort(t_node *b)
{
	int	i;

	i = 1;
	while()

}

//  void	inserion_sort(t_node **a, t_node **b)
// {

//  	if (!a || ft_sorted(a))
// 		return(a);
// 	while (a->next != NULL)
// 	{
// 		pb();
// 			while (*b->content > *a->content)
// 				ra();
// 		pa()
// 	}
// 	return (a);
// }
