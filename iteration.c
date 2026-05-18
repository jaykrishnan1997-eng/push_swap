/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jay-k <jay-k@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:02:17 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/18 22:25:50 by jay-k            ###   ########.fr       */
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
		return (free(newn), NULL) ;
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

int	find_min(t_node *a)
{
	t_node	*current;
	int		min;
	int		min_index;
	int		current_index;

	if (!a)
		return (0);
	current = a;
	min = *current->content;
	min_index = 0;
	current_index = 0;
	while (current != NULL )
	{
		if (*current->content < min)
		{
			min = *current->content;
			min_index = current_index;
		}
		current_index++;
		current = current->next;
	}
	return (min_index);
}

void	rotation(t_node *a, int index, int stash_size)
{
	if (index <= stash_size / 2)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
	else
	{
		while (stack_size(a) - index > 0)
		{
			rra(a);
			index--;
		}
	}
	return;
}

void	inserion_sort(t_node **a, t_node **b)
{
	int	index;
	
 	if (!a || is_sorted(*a))
		return;
	if (stack_size(*a) == 1)
		return;
	if (stack_size(*a) == 2)
		s(a);
	while(stack_size(*a) > 2)
	{
			index = find_min(*a);
			rotation(*a, index, stack_size(*a));
			pa(b);
	}
	if (*(*a)->content > *(*a)->next->content)
		sa(a);
	while (*b != NULL)
		pa(a);
	return;
}

