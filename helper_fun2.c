/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:16:12 by jkrishna          #+#    #+#             */
/*   Updated: 2026/05/19 15:17:03 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_front(t_node **a)
{
	t_node	*head;
	t_node	*new_head;

	if (!*a)
		return ;
	head = *a;
	new_head = (*a)->next;
	if (new_head)
		new_head->prev = NULL;
	head->next = NULL;
	*a = new_head;
	free(head->content);
	free(head);
}
