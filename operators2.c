/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:45 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/19 17:19:57 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **a)
{
	int	*temp_content;
	int	temp_index;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp_content = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp_content;
	temp_index = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = temp_index;
}

void	sa(t_node **a)
{
	swap_a(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **b)
{
	int	*temp_content;
	int	temp_index;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp_content = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp_content;
	temp_index = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = temp_index;
}

void	sb(t_node **b)
{
	swap_b(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	int	value;
	int	index;

	if (!*a)
		return ;
	value = *(*a)->content;
	index = (*a)->index;
	del_front(a);
	add_front(b, value, index);
	write(1, "pb\n", 3);
}

void	pa(t_node **b, t_node **a)
{
	int	value;
	int	index;

	if (!*b)
		return ;
	value = *(*b)->content;
	index = (*b)->index;
	del_front(b);
	add_front(a, value, index);
	write(1, "pa\n", 3);
}
