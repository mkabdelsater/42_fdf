/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:11:01 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 13:06:45 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/utils.h"
#include "../inc/geometry.h"

#define MAX_READ_SIZE 500000

static void	set_map_limits(t_map *map);
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
	set_map_limits(map);
	map_get_points(map);
	color_map_points(map);
	set_polar_coords(map);
	ft_printf("\nLoading GUI...\n");
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

//go through the lines map->memory line by line and load the points
// free each line after loading it into `line`

static int	load_points(char *line, t_map *map, int lines)
{
	int			i;
	char		**lines_vector;
	static int	pnts = 0;

	i = 0;
	lines_vector = ft_split(line, ' ');
	while (lines_vector[i] && lines_vector[i][0] != '\n')
	{
		if (!is_valid_point(&lines_vector[i][0]))
			error_out("The File is empty or wrongly formatted");
		map->points[pnts].axis[Z_AXIS] = ft_atoi(&lines_vector[i][0]);
		map->points[pnts].axis[X_AXIS] = i - map->limits.axis[X_AXIS] / 2;
		map->points[pnts].axis[Y_AXIS] = lines - map->limits.axis[Y_AXIS] / 2;
		map->points[pnts].painted = true;
		map->points[pnts].color = DEFAULT_COLOR;
		map->points[pnts].color_hex = get_point_color(lines_vector[i]);
		if (map->limits.axis[Z_AXIS] < map->points[pnts].axis[Z_AXIS])
			map->limits.axis[Z_AXIS] = map->points[pnts].axis[Z_AXIS];
		if (map->z_min > map->points[pnts].axis[Z_AXIS])
			map->z_min = map->points[pnts].axis[Z_AXIS];
		i++;
		pnts++;
	}
	free_2d_vector(lines_vector);
	return (i);
}

static void	map_get_points(t_map *map)
{
	int			i;
	char		*line;
	char		*last_line;
	static int	point_count = 0;
	static int	line_count = 0;

	i = 0;
	line = NULL;
	last_line = map->memory;
	map->points = ft_calloc(map->len, sizeof(t_point));
	while (true)
	{
		i++;
		if (map->memory[i] != '\n' && map->memory[i] != '\0')
			continue ;
		free(line);
		line = ft_substr(last_line, 0, &map->memory[i] - last_line);
		last_line = &map->memory[i + 1];
		point_count += load_points(line, map, line_count++);
		ft_printf("\r 🔵 reading %d points...", point_count);
		if (map->memory[i] == '\0')
			break ;
	}
	free(line);
	ft_printf("\r 🟢 %d Points read successfully!\n", point_count);
}

// ! TO_REFACTOR : Readability

static void	set_map_limits(t_map *map)
{
	static int	i = -1;
	static int	elems = 0;

	while (map->memory[++i])
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->memory[i]) && \
			(map->memory[i + 1] == ' ' || map->memory[i + 1] == '\n' || \
			map->memory[i + 1] == '\0'))
			elems++;
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y_AXIS]++;
			if (get_lm(map, X_AXIS) != 0 && (get_lm(map, X_AXIS) != elems))
				error_out("Bad Map Format - Line Length inconsistent");
			else
				map->limits.axis[X_AXIS] = elems;
			elems = 0;
		}
	}
	if (elems > 0 && (map->limits.axis[X_AXIS] != elems))
		error_out("Bad Map Format - Line Length Inconsistent");
	map->limits.axis[Y_AXIS]++;
	map->len = map->limits.axis[X_AXIS] * map->limits.axis[Y_AXIS];
}
