/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:13:11 by maria-ol          #+#    #+#             */
/*   Updated: 2025/09/25 18:15:19 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
int		ft_isalpha(int chr);
int		ft_isalnum(int chr);
int		ft_isdigit(int chr);
int		ft_isprint(int chr);
int		ft_isascii(int chr);
char	*ft_itoa(int n);
int		ft_tolower(int chr);
int		ft_toupper(int chr);
void	*ft_memset(void *str, int chr, size_t num);
void	ft_bzero(void *str, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memchr(const void *src, int chr, size_t num);
int		ft_memcmp(const void *s1, const void *s2, size_t num);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
char	*ft_strchr(const char *str, int chr);
char	*ft_strrchr(const char *str, int chr);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t amount, size_t bytes_size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
long	ft_atol(const char *str);
void	ft_error(void);
size_t	count_words(const char *str, char delimit);
int		ft_isspace(int chr);
void	ft_free_arr(char **arr, size_t limit);

//printf
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_print_hex(unsigned long n, char specifier);
int		ft_printptr(unsigned long n);

//get next line
char	*get_next_line(int fd);
void	ft_memdel(void **address_ptr);

#endif