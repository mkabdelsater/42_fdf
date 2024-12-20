/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:11:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/20 14:52:20 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX_READ_SIZE 500000

static void	map_size(t_map *map);
static void	map_get_points(t_map *map);
static char	*parse_map(int fd);

void	load_map(t_map *map, char *path)
{

}


// ? when bytes_read is less than the MAX_READ_SIZE, that means we've reached
// ? the end of the file

static char	*parse_map(int fd)
{
	static int	bytes_read = MAX_READ_SIZE;
	static int	bytes_total = 0;
	char		*buffer;
	char		*temp;
	char		*map;

	buffer = malloc(MAX_READ_SIZE * sizeof(char));
	if (buffer == NULL)
		error_out("Failed Allocating Memory while parsing map)");
	map = ft_strdup("");
	ft_printf("\nLoading Map...\n\n");
	while (bytes_read == MAX_READ_SIZE)
	{
		ft_bzero(buffer, MAX_READ_SIZE);
		bytes_read = read(fd, buffer, MAX_READ_SIZE);
		temp = map;
		map = ft_strjoin(map, buffer);
		bytes_total += bytes_read;
		ft_printf("\r Reading... %d Kb", bytes_total / 1024);
		free(temp);
	}
	ft_printf("\r 🟢 %d Kb Read", bytes_total / 1024);
	free(buffer);
	return (map);
}

