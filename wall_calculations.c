/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:37:45 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	get_wall_height(t_game *game)
{
	if (game->plr.perp_wall_dist < 0.001)
		game->plr.perp_wall_dist = 0.001;
	game->map.wall_height = WINHEIGHT / game->plr.perp_wall_dist;
	game->map.draw_start_real = (-game->map.wall_height / 2) + (WINHEIGHT / 2);
	game->map.draw_end_real = (game->map.wall_height / 2) + (WINHEIGHT / 2);
	game->map.draw_start = game->map.draw_start_real;
	if (game->map.draw_start < 0)
		game->map.draw_start = 0;
	game->map.draw_end = game->map.draw_end_real;
	if (game->map.draw_end >= WINHEIGHT)
		game->map.draw_end = WINHEIGHT - 1;
}

static void	my_pixelput(t_game *game, int x, int y, int color)
{
	char	*dest;

	dest = game->win.addr + (y * game->win.line_len + x * (game->win.bpp / 8));
	*(unsigned int *)dest = color;
}

static void	my_calculate(t_game *game, int x, int y)
{
	game->map.tex_y = (int)((y - game->map.draw_start_real) * \
			game->txtrs[game->map.tex_num].height / game->map.wall_height);
	game->map.hex_color = \
		*(unsigned int *)(game->txtrs[game->map.tex_num].addr + \
			(game->map.tex_y * game->txtrs[game->map.tex_num].line_len + \
				game->map.tex_x * (game->txtrs[game->map.tex_num].bpp / 8)));
	if (game->map.side == 1)
		game->map.hex_color = (game->map.hex_color >> 1) & 8355711;
	my_pixelput(game, x, y, game->map.hex_color);
}

void	draw_ver_line(t_game *game, int x)
{
	int		y;

	get_wall_height(game);
	y = -1;
	while (++y < game->map.draw_start)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
			my_pixelput(game, x, y, game->map.ccol);
	}
	y = game->map.draw_start - 1;
	while (++y <= game->map.draw_end)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
			my_calculate(game, x, y);
	}
	y = game->map.draw_end;
	while (++y < WINHEIGHT)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
			my_pixelput(game, x, y, 0x222222);
	}
}
