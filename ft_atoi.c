/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:20:46 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/05/18 11:39:27 by gvoelkne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_number(char c)
{
	return (c >= '0' && c <= '9')
}

static int	is_space(char c)
{
	return (c == '+' || c == '-' || c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	calc_pow(int base, int power)
{
	if (power == 0)
		return (1);
	return (base * calc_pow(base, power - 1));
}

static int	str_to_int(int *nums, int nums_len, int is_neg)
{
	int	idx;
	int	rev_idx;
	int	res;

	idx = 0;
	res = 0;
	rev_idx = nums_len - 1;
	while (rev_idx >= 0)
	{
		res += nums[rev_idx] * calc_pow(10, idx);
		idx++;
		rev_idx--;
	}
	if (is_neg)
		return (-res);
	return (res);
}

int	*ft_atoi(const char *str)
{
	int	idx;
	int	minus_count;
	int	nums_idx;
	int	nums[64];

	idx = 0;
	nums_idx = 0;
	minus_count = 0;
	while (str[idx] && !is_number(str[idx]))
	{
		if (!is_space(str[idx]))
			return (NULL);
		if (idx > 0 && (str[idx - 1] == '+' || str[idx - 1] == '-'))
			return (NULL);
		if (str[idx] == '-')
			minus_count++;
		idx++;
	}
	while (str[idx] && is_number(str[idx]))
	{
		nums[nums_idx] = str[idx] - 48;
		nums_idx++;
		idx++;
	}
	return (str_to_int(nums, nums_idx, (minus_count % 2 != 0)));
}
