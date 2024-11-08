/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:28:27 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/29 14:46:58 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * 1. malloc for a new node
 * 2. copy chars after '\n' from last node to cleaned_node
 * 3. free all nodes and make list point to new node
 * when gnl is called again we start from where we left off thanks to the
 * read function
 */

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*cleaned_node;
	int		i_index;
	int		j_index;
	char	*new_str;

	new_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	cleaned_node = malloc(sizeof(t_list));
	if (new_str == NULL || cleaned_node == NULL)
		return ;
	last_node = get_last_node(*list);
	i_index = 0;
	j_index = 0;
	while (last_node->str_buf[i_index] && last_node->str_buf[i_index] != '\n')
		i_index++;
	while (last_node->str_buf[i_index] && last_node->str_buf[++i_index])
		new_str[j_index++] = last_node->str_buf[i_index];
	new_str[j_index] = '\0';
	cleaned_node->str_buf = new_str;
	cleaned_node->next = NULL;
	reset_list(list, cleaned_node, new_str);
}

char	*get_line_from_node(t_list *list_node)
{
	int		line_len;
	char	*next_line;

	if (list_node == NULL)
		return (NULL);
	line_len = len_to_next_line(list_node);
	next_line = malloc(sizeof(char) * (line_len + 1));
	if (next_line == NULL)
		return (NULL);
	copy_str_to_node(list_node, next_line);
	return (next_line);
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = get_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	populate_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append_node(list, buffer);
	}
}

// read will return -1 if the file can't be opened
// the check is there to see if we have permission to read

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	populate_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line_from_node(list);
	polish_list(&list);
	return (next_line);
}
