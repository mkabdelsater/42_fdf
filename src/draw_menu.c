/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:22 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 15:12:23 by moabdels         ###   ########.fr       */
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
	print
}

void	draw_menu(t_globals *global_state)
{
	draw_controls(global_state);
	draw_info(global_state);
	draw_settings(global_state);
	draw_color_controls(global_state);
}
