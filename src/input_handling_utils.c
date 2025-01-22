/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:10:12 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 16:13:13 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/keycodes.h"
#include "../inc/input_handling.h"

// ! TO_REFACTOR

static void modify_angle(float *angle, float mod)
{
	*angle += mod;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >=360)
		*angle = *angle - 360;
}

// !TODO : Add wasdqe control scheme

void	rotation_control(int key, t_globals *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.b_key_ctrl)
		ang = 90;
	if (key == KEY_DOWN)
		modify_angle(&fdf->map.ang[X_AXIS], ang);
	if (key == KEY_UP)
		modify_angle(&fdf->map.ang[X_AXIS], -ang);
	if (key == KEY_LEFT)
		modify_angle(&fdf->map.ang[Y_AXIS], ang);
	if (key == KEY_RIGHT)
		modify_angle(&fdf->map.ang[Y_AXIS], -ang);
	if (key == KEY_Q)
		modify_angle(&fdf->map.ang[Z_AXIS], ang);
	if (key == KEY_W)
		modify_angle(&fdf->map.ang[Z_AXIS], -ang);
}
