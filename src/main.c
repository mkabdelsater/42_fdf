/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:55:14 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:42 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"

void	error_out(char *err_msg)
{
	ft_putstr_fd(ERR_TAG, 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int argv, char **argc)
{
	t_globals	global_state;

	if (argv != 2)
		error_out("Number of arguments not 1 - Usage : `./fdf <map file>`");
	load_map(&global_state.map, argc[1]);
	(void)global_state;
	(void)argc;
	exit(EXIT_SUCCESS);
}
