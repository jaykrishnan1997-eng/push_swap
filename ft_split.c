/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:14:36 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/05/18 09:26:38 by gvoelkne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	contains(const char *heystack, char needle)
{
	int	idx;

	idx = 0;
	while (heystack[idx])
	{
		if (heystack[idx] == needle)
			return (1);
		idx += 1;
	}
	return (0);
}

static int	calc_splits(const char *s, char *targets)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (s[idx])
	{
		if (!contains(targets, s[idx]) && (idx == 0 || contains(targets, s[idx
					- 1])))
			res += 1;
		idx += 1;
	}
	return (res);
}

static void	*free_res(char **res, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		free(res[idx]);
		idx += 1;
	}
	free(res);
	return (NULL);
}

static char	**split(char const *s, char *targets, char **res)
{
	int	idx;
	int	start;
	int	res_idx;

	idx = 0;
	start = 0;
	res_idx = 0;
	while (s[idx])
	{
		if (!contains(targets, s[idx]) && (idx == 0 || contains(targets, s[idx
					- 1])))
			start = idx;
		if (!contains(targets, s[idx]) && (s[idx + 1] == '\0'
				|| contains(targets, s[idx + 1])))
		{
			res[res_idx] = ft_substr(s, start, idx - start + 1);
			if (!res[res_idx++])
				return (free_res(res, res_idx));
		}
		idx += 1;
	}
	res[res_idx] = NULL;
	return (res);
}

char	**ft_split(char const *s, char *targets)
{
	char	**res;

	if (!s || !targets)
		return (NULL);
	res = malloc(sizeof(char *) * (calc_splits(s, targets) + 1));
	if (!res)
		return (NULL);
	return (split(s, targets, res));
}
