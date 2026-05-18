# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 15:33:18 by gvoelkne          #+#    #+#              #
#    Updated: 2026/05/18 11:40:47 by gvoelkne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC := ft_split.c ft_substr.c ft_strlen.c ft_strdup.c ft_atoi.c

.PHONY: test
test:
	cc -Wall -Werror -Wextra -o test $(SRC) parser.c
