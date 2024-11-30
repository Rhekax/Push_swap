/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:32:34 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/28 13:08:58 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

char	**ft_split(const char *s, char c);
t_stack	*ft_lstmap(t_stack *lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
char	*ft_strnstr(const char *haystck, const char *needle, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
char	*ft_strrchr(const char *s, int c);

#endif