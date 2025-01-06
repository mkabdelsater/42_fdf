/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:11:01 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/06 13:24:53 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"

#define MAX_READ_SIZE 500000

static void	map_size(t_map *map);
static void	map_get_points(t_map *map);
static char	*parse_map(int fd);

void	load_map(t_map *map, char *path)
{
	int	fd;
	map_init(map, true);
	fd = open(path, O_RDONLY);
	if (fd < 2)
		error_out("Error Opening the Map File");
	map->memory = parse_map(fd);
	close(fd);
	map_size(map);
	map_get_points(map);
	
}


// ? when bytes_read is less than the MAX_READ_SIZE, that means we've reached
// ? the end of the file
// ! TODO: readability can be improved?

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

