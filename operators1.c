/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:49:55 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/19 17:18:48 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	rotate_a(t_node **a)
{
	t_node	*old_head;
	t_node	*new_head;
	t_node	*tail;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	old_head = *a;
	new_head = (*a)->next;
	tail = old_head;
	while (tail->next)
		tail = tail->next;
	tail->next = old_head;
	old_head->prev = tail;
	old_head->next = NULL;
	new_head->prev = NULL;
	*a = new_head;
}
void	ra(t_node **a)
{
	rotate_a(a);
	write(1, "ra\n", 3);
}
static void	rotate_b(t_node **b)
{
	t_node	*old_head;
	t_node	*new_head;
	t_node	*tail;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	old_head = *b;
	new_head = (*b)->next;
	tail = old_head;
	while (tail->next)
		tail = tail->next;
	tail->next = old_head;
	old_head->prev = tail;
	old_head->next = NULL;
	new_head->prev = NULL;
	*b = new_head; 
}
void	rb(t_node **b)
{
	rotate_b(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
	return ;
}

static void	reverse_ra(t_node **a)
{
	t_node	*new_tail;
	t_node	*old_head;
	t_node	*head;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	old_head = *a;
	while (head->next)
		head = head->next;
	new_tail = head->prev;
	new_tail->next = NULL;
	*a = head;
	head->prev = NULL;
	head->next = old_head;
	old_head->prev = head;
}

void	rra(t_node **a)
{
	reverse_ra(a);
	write(1, "rra\n", 4);
}
static void	reverse_rb(t_node **b)
{
	t_node	*new_tail;
	t_node	*old_head;
	t_node	*head;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	head = *b;
	old_head = *b;
	while (head->next)
		head = head->next;
	new_tail = head->prev;
	new_tail->next = NULL;
	*b = head;
	head->prev = NULL;
	head->next = old_head;
	old_head->prev = head;
}
void	rrb(t_node **b)
{
	reverse_rb(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_ra(a);
	reverse_rb(b);
	write(1, "rrr\n", 4);
	return ;
}
