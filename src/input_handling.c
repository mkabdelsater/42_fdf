/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:56:38 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/21 15:03:17 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	rotation_control(int key, t_globals *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.b_key_ctrl)
		ang = 90;
	
}

// ? the signature is based on the prototypes found in the MLX library

int	on_key_down(int key, void *param)
{
	t_globals *fdf;

	fdf = (t_globals *)param;
	rotation_control(key, fdf);
}
