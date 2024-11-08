/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:21 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/29 15:12:55 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//! DELETE WHEN DONE
// # include <stdio.h>

typedef struct s_list
{
	char			*str_buf;
	int				node_fd;
	struct s_list	*next;
}	t_list;

void	reset_list(t_list **list, t_list *clean_node, char *str, int fd);
int		found_newline(t_list *list_node);
void	polish_list(t_list **list, int fd);
t_list	*get_last_node(t_list *list_node);
void	copy_str_to_node(t_list *list_node, char *str, int fd);
int		len_to_next_line(t_list *list_node, int fd);
char	*get_line_from_node(t_list *list_node, int fd);
void	append_node(t_list **list, char *buffer, int fd);
void	populate_list(t_list **list, int fd);
char	*get_next_line(int fd);

// !DELETE WHEN DONE
// void	print_list(t_list **list);

#endif
