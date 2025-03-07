/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:12:52 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 16:21:16 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rendering.h"
#include "../inc/input_handling.h"

#define LMB 0
#define RMB 1

// !TODO : Make it possible to rotate diagonally

// ? returns the position of the last click
static int	click_pos(t_globals *fdf, int mouse_btn, int axis)
{
	if (mouse_btn == LMB)
		return ((int)fdf->keys.last_click_l.axis[axis]);
	else
		return ((int)fdf->keys.last_click_r.axis[axis]);
}

int	on_mouse_move(int x, int y, void *param)
{
	t_globals	*fdf;

	fdf = (t_globals *)param;
	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT || y < 0)
		return (0);
	if (fdf->keys.lmb)
	{
		modify_angle(&fdf->map.ang[X_AXIS], click_pos(fdf, LMB, Y_AXIS) - y);
		modify_angle(&fdf->map.ang[Y_AXIS], click_pos(fdf, LMB, X_AXIS) - x);
		fdf->keys.last_click_l.axis[X_AXIS] = x;
		fdf->keys.last_click_l.axis[Y_AXIS] = y;
		render_model(fdf, FREE);
	}
	if (fdf->keys.rmb)
	{
		fdf->map.source.axis[X_AXIS] -= (click_pos(fdf, RMB, X_AXIS) - x);
		fdf->map.source.axis[Y_AXIS] -= (click_pos(fdf, RMB, Y_AXIS) - y);
		fdf->map.source.axis[Z_AXIS] = 0;
		fdf->keys.last_click_r.axis[X_AXIS] = x;
		fdf->keys.last_click_r.axis[Y_AXIS] = y;
		render_model(fdf, FREE);
	}
	return (0);
}

int	on_mouse_btn_release(int button, int x, int y, void *param)
{
	t_globals	*fdf;

	(void)x;
	(void)y;
	fdf = (t_globals *)param;
	if (button == 1)
		fdf->keys.lmb = 0;
	if (button == 2 || button == 3)
		fdf->keys.rmb = 0;
	return (0);
}

int	on_mouse_btn_press(int button, int x, int y, void *param)
{
	t_globals	*fdf;

	fdf = (t_globals *)param;
	if (button == 1)
	{
		fdf->keys.lmb = true;
		fdf->keys.last_click_l.axis[X_AXIS] = x;
		fdf->keys.last_click_l.axis[Y_AXIS] = y;
	}
	if (button == 2 || button == 3)
	{
		fdf->keys.rmb = true;
		fdf->keys.last_click_r.axis[X_AXIS] = x;
		fdf->keys.last_click_r.axis[Y_AXIS] = y;
	}
	if (button == 4)
		fdf->map.scale *= 1.5;
	if (button == 5 && fdf->map.scale > 2)
		fdf->map.scale /= 1.5;
	render_model(fdf, FREE);
	return (0);
}
