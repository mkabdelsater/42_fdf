/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:21 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/19 15:22:21 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

void	reset_list(t_list **list, t_list *clean_node, char *str);
int		found_newline(t_list *list_node);
void	polish_list(t_list **list);
t_list	*get_last_node(t_list *list_node);
void	copy_str_to_node(t_list *list_node, char *str);
int		len_to_next_line(t_list *list_node);
char	*get_line_from_node(t_list *list_node);
void	append_node(t_list **list, char *buffer);
void	populate_list(t_list **list, int fd);
char	*get_next_line(int fd);

#endif
