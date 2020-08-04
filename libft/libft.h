/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:34:13 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/26 18:30:18 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define __INT_MIN__ -2147483648
# define __SIZE_T_MAXI__ 18446744073709551615UL
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					*ft_map(int *tab, int length, int (*f)(int));
int					ft_match(char *s1, char *s2);
int					*ft_range(int min, int max);
void				ft_foreach(int *tab, int length, void (*f)(int));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int nb);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *s));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(char const *s, int c);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
char				*ft_strstr(const char *str1, const char *str2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
int					ft_isascii(int c);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
void				*ft_memccpy(void *dest, const void *src, int n, size_t s);
void				*ft_memchr(const void *arr, int ch, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *str, int a, size_t num);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *str);
unsigned long		ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int f);

#endif
