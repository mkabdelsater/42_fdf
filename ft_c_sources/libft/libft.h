/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:24:55 by moabdels          #+#    #+#             */
/*   Updated: 2024/11/05 12:26:10 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# define ERR_TAG "\033[31;1mError\033[0m : "
# define AC_RED "\033[31;1m"
# define AC_GREEN "\033[32;1m"
# define AC_YELLOW "\033[33;1m"
# define AC_BLUE "\033[34;1m"
# define AC_MAGENTA "\033[35;1m"
# define AC_CYAN "\033[36;1m"
# define AC_RESET "\033[0m"
# define RESET_TAG "\033[0m"

/***********************************************
** 	STRUCTS                                   **
***********************************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/***********************************************
** 	          BOOLEANS                        **
***********************************************/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

/***********************************************
** 	          MEMORY                          **
***********************************************/

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

/***********************************************
** 	STRINGS - PROCESSING                      **
***********************************************/

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_count_words(char const *str, char delimiter);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strmatch(const char *s1, const char *s2);

/**********************************************
**	STRINGS - CONVERSIONS                    **
**********************************************/

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

/**********************************************
** 	STRINGS - MAPPINGS                       **
**********************************************/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**********************************************
** 	STRINGS - I/O                            **
**********************************************/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/**********************************************
** 	LIST STRUCT FUNCTIONS                    **
**********************************************/

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_lstsize(t_list *lst);

#endif
