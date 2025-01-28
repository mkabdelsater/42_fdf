/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:22 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/28 15:43:41 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

#define DRAWINFO_BOX	40
#define MAPINFO_BOX		280
#define COLORSCHEME_BOX	480
#define CONTROL_BOX		650
#define LINE_SIZE		30
#define MENU_TAB_SIZE	30

static void	draw_controls(t_globals *global_state)
{
	int	line;

	line = CONTROL_BOX;
	render_string(global_state, MENU_TAB_SIZE, line, "---- CONTROLS ----");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "Scroll: ZoomIn/Out");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "LMB: Rotate X/Y axis");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "Arrows: Rotate X/Y");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "RMB: Translate Model");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "Q,E: Rotate Z Axis");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "W,S: Rotate Y Axis");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "A,D: Rotate X Axos");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "+,- Z Divisor");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "B : Blending");
	line += LINE_SIZE;
	render_string(global_state, MENU_TAB_SIZE, line, "I,F,C: Iso, Fit, Center");
	line += LINE_SIZE;
}

static void	draw_info(t_globals *fdf)
{
	int	line;

	line = DRAWINFO_BOX;
	render_string(fdf, MENU_TAB_SIZE, line, "---- INFO ----");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "Renders: ");
	render_number(fdf, MENU_TAB_SIZE + 100, line, fdf->map.renders);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "Performance(ms): ");
	render_number(fdf, MENU_TAB_SIZE + 170, line, fdf->map.performance * 1000);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "X, Y, Z: [   ] [   ] [   ]");
	render_number(fdf, MENU_TAB_SIZE + 100, line, fdf->map.ang[X_AXIS]);
	render_number(fdf, MENU_TAB_SIZE + 160, line, fdf->map.ang[Y_AXIS]);
	render_number(fdf, MENU_TAB_SIZE + 220, line, fdf->map.ang[Z_AXIS]);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "Zoom:");
	render_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.scale);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "Z Divisor:");
	render_number(fdf, MENU_TAB_SIZE + 110, line, fdf->map.b_range * 10000);
}

static void	draw_settings(t_globals *fdf)
{
	int	line;

	line = MAPINFO_BOX;
	render_string(fdf, MENU_TAB_SIZE, line, "---- MAP INFO ----");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "Size:");
	render_number(fdf, MENU_TAB_SIZE + 40, line, fdf->map.len);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "MaxX:");
	render_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[X_AXIS]);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "MaxY:");
	render_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[Y_AXIS]);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "MaxZ:");
	render_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.limits.axis[Z_AXIS]);
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "MinZ:");
	render_number(fdf, MENU_TAB_SIZE + 80, line, fdf->map.z_min);
	line += LINE_SIZE;
}

static void	draw_color_controls(t_globals *fdf)
{
	int	line;

	line = COLORSCHEME_BOX;
	render_string(fdf, MENU_TAB_SIZE, line, "---- COLORSCHEME ----");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "1: Default");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "2: Black on White");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "3: White on Black");
	line += LINE_SIZE;
	render_string(fdf, MENU_TAB_SIZE, line, "4: Terrain");
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
