/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:02:17 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/19 17:01:50 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_node **a, int index, int stash_size)
{
	int	steps;

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
		steps = stash_size - index;
		while (steps > 0)
		{
			rra(a);
			steps--;
		}
	}
	return ;
}

void	insertion_sort(t_node **a, t_node **b)
{
	int	index;

	if (!a || is_sorted(*a))
		return ;
	if (stack_size(*a) == 1)
		return ;
	if (stack_size(*a) == 2)
	{
		sa(a);
		return ;
	}
	while (stack_size(*a) > 2)
	{
		index = find_min(*a);
		rotation(a, index, stack_size(*a));
		pb(a, b);
	}
	if (*(*a)->content > *(*a)->next->content)
		sa(a);
	while (*b != NULL)
		pa(b, a);
	return ;
}

