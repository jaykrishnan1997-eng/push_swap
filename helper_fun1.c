/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:12:36 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/19 15:15:32 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*new_node(int value)
{
	t_node	*current;
	int		*content;

	current = malloc(sizeof(t_node));
	content = malloc(sizeof(int));
	if (!current || !content)
		return (free(current), free(content), NULL);
	*content = value;
	current->content = content;
	current->prev = NULL;
	current->next = NULL;
	return (current);
}

void	add_front(t_node **a, int value, int index)
{
	t_node	*current;
	t_node	*new;

	new = new_node(value);
	if (!*a)
	{
		*a = new;
		(*a)->index = index;
		return ;
	}
	current = *a;
	new->next = current;
	new->prev = NULL;
	current->prev = new;
	*a = new;
	new->index = index;
}