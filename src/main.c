/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:55:14 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/19 15:07:00 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
		error_out("Usage : `./fdf <map file>`");


}
