/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:22 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 16:37:05 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

#define CONTROL_BOX		650
#define DRAWINFO_BOX	40
#define MAPINFO_BOX		280
#define COLORSCHEME_BOX	480
#define LINE_SIZE		30
#define MENU_TAB_SIZE	30

static void	draw_controls(t_globals *global_state)
{
	int	line;

	line = COLORSCHEME_BOX;
	draw_string(global_state, MENU_TAB_SIZE, line, "---- CONTROLS ----");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "Scroll: Zoom In/Out");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "LMB: Rotate Model (X/Y Axis)");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "Arrow Keys: Rotate along X/Y");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "RMB: Translate Model");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "Q,E: Rotate Z Axis");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "W,S: Rotate Y Axis");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "A,D: Rotate X Axos");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "+,- Z Divisor");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "B : Blending");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "I,F,C: Isometric,Fit,Center");
	line += LINE_SIZE;
}

static void	draw_info(t_globals *fdf)
{
	int	line;

	line = DRAWINFO_BOX;
	draw_string(fdf, MENU_TAB_SIZE, line, "---- INFO ----");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Renders: ");
	draw_number(fdf, MENU_TAB_SIZE + 100, line, fdf->map.renders);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Performance (ms): ");
	draw_number(fdf, MENU_TAB_SIZE + 170, line, fdf->map.performance * 1000);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "X, Y, Z: [   ] [   ] [   ]");
	draw_number(fdf, MENU_TAB_SIZE + 100, line, fdf->map.ang[X_AXIS]);
	draw_number(fdf, MENU_TAB_SIZE + 160, line, fdf->map.ang[Y_AXIS]);
	draw_number(fdf, MENU_TAB_SIZE + 220, line, fdf->map.ang[Z_AXIS]);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Zoom:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.scale);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Z Divisor:");
	draw_number(fdf, MENU_TAB_SIZE + 110, line, fdf->map.b_range * 10000);
}

static void	draw_settings(t_globals *fdf)
{
	int	line;

	line = MAPINFO_BOX;
	draw_string(fdf, MENU_TAB_SIZE, line, "---- SETTINGS ----");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Size:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.len);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Max X:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[X_AXIS]);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Max Y:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[Y_AXIS]);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Max Z:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[Z_AXIS]);
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "Min Z:");
	draw_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.z_min);
	line += LINE_SIZE;
}

static void	draw_color_controls(t_globals *fdf)
{
	int	line;
	line = COLORSCHEME_BOX;
	draw_string(fdf, MENU_TAB_SIZE, line, "---- COLOR SCHEME ----");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "0: Default");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "1: Terrain");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "2: Black on White");
	line += LINE_SIZE;
	draw_string(fdf, MENU_TAB_SIZE, line, "3: White on Black");
	line += LINE_SIZE;
}

// ! TO_REFACTOR : lots of things
void	draw_menu(t_globals *fdf)
{
	draw_controls(fdf);
	draw_info(fdf);
	draw_settings(fdf);
	draw_color_controls(fdf);
}
