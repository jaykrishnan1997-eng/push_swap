/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:01:17 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/05/18 08:49:13 by gvoelkne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *src)
{
	int		idx;
	char	*copy;

	idx = 0;
	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy)
		return (NULL);
	while (src[idx])
	{
		copy[idx] = src[idx];
		idx++;
	}
	copy[idx] = '\0';
	return (copy);
}
