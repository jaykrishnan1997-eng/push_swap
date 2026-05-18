/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 08:43:16 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/04/27 09:17:47 by gvoelkne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*


#include <stdio.h>

int	main(void)
{
	char	str[] = "hello";

	printf("'%s' has length: %d", str, ft_strlen(str));
	return (0);
}
*/
