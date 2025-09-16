/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:59:03 by lemarino          #+#    #+#             */
/*   Updated: 2025/09/11 12:27:13 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*      /chars       */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
/*      /memory     */
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_realloc(void *ptr, size_t old_size, size_t size);
void			**free_dpc(char **double_pointer_char);
/*     /numbers     */
int				ft_atoi(const char *nptr);
int				ft_atol(const char *nptr);
int				ft_atoi_base(const char *str, int base);
char			*ft_itoa(int n);
int				ft_ipow(int nbr, int power);
int				ft_fpow(float nbr, int power);
/*      /strings     */
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strchr2(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_until_chr(const char *s, int c);
void			ft_until_chr_print(const char *s, int c);
char			*ft_before_chr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin2(char *s1, char *s2);
char			*ft_strjoin3(char *s1, char *s2);
char			*ft_strtrim(char *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				count_words(const char *str, char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strrcmp(const char *s1, const char *s2, size_t n);
/*      /print       */
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putendl_fd(char *s, int fd);
size_t			ft_putnbr_fd(int n, int fd);
int				ft_printf(const char *input, ...);
int				ft_print_p(intptr_t *p);
int				ft_print_hex(unsigned int nbr, const char input);
int				ft_print_u(unsigned int n);
int				ft_printfd(int fd, const char *input, ...);
int				fd_print_p(int fd, intptr_t *p);
int				fd_print_hex(int fd, unsigned int nbr, const char input);
int				fd_print_u(int fd, unsigned int n);
int				fd_print_n(int fd, int n);
/*      /lists       */
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
												void (*del)(void *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*get_next_line(int fd);

#endif
