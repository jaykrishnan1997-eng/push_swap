/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrishna <jkrishna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:29:44 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/05/19 15:25:44 by jkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				index;
	int				*content;
	struct t_node	*prev;
	struct t_node	*next;
}					t_node;

typedef enum s_algo_config
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					e_algo_config;

typedef struct s_args
{
	int				*nums;
	e_algo_config	algo_config;
	int				benchmark_enabled;
}					t_args;

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char *targets);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
int					*ft_atoi(const char *nptr);
int					is_sorted(t_node *a);
int					stack_size(t_node *a);
int					find_min(t_node *a);
t_node				*new_node(int value);
void				add_front(t_node **a, int value, int index);
void				del_front(t_node **a);
void				insertion_sort(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				pa(t_node **b, t_node **a);


#endif

/*
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);

char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);

int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t nmemb, size_t size);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);

char				*ft_itoa(int n);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
*/
