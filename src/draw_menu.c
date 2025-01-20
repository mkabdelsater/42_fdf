/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:22 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:26 by moabdels         ###   ########.fr       */
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
	draw_string(global_state, MENU_TAB_SIZE, line, "+/- Z Divisor");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "B : Blending");
	line += LINE_SIZE;
	draw_string(global_state, MENU_TAB_SIZE, line, "I,F,C: Isometric/Fit/Center");
	line += LINE_SIZE;
}

void	draw_menu(t_globals *global_state)
{
	draw_controls(global_state);
	draw_info(global_state);
	draw_settings(global_state);
	draw_color_controls(global_state);
}
