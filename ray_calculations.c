/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:21:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	get_ray_derivates(t_game *game)
{
	game->map.map_x = (int)game->plr.pos_x;
	game->map.map_y = (int)game->plr.pos_y;
	game->map.camera_x = 2 * game->map.x / (double)WINWIDTH - 1;
	game->plr.ray_dir_x = game->plr.ray_x + game->map.plane_x * \
												game->map.camera_x;
	game->plr.ray_dir_y = game->plr.ray_y + game->map.plane_y * \
												game->map.camera_x;
	if (game->plr.ray_dir_x == 0)
		game->plr.delta_x = 1e30;
	else
		game->plr.delta_x = fabs(1 / game->plr.ray_dir_x);
	if (game->plr.ray_dir_y == 0)
		game->plr.delta_y = 1e30;
	else
		game->plr.delta_y = fabs(1 / game->plr.ray_dir_y);
}

void	calculate_nearest_coords(t_game *game)
{
	if (game->plr.ray_dir_x < 0)
	{
		game->map.step_x = -1;
		game->plr.dist_x = (game->plr.pos_x - game->map.map_x) * \
												game->plr.delta_x;
	}
	else
	{
		game->map.step_x = 1;
		game->plr.dist_x = ((float)game->map.map_x + 1.0 - game->plr.pos_x) * \
												game->plr.delta_x;
	}
	if (game->plr.ray_dir_y < 0)
	{
		game->map.step_y = -1;
		game->plr.dist_y = (game->plr.pos_y - game->map.map_y) * \
												game->plr.delta_y;
	}
	else
	{
		game->map.step_y = 1;
		game->plr.dist_y = ((float)game->map.map_y + 1.0 - game->plr.pos_y) * \
												game->plr.delta_y;
	}
}

static void	on_x(t_game *game)
{
	game->map.map_x += game->map.step_x;
	game->plr.dist_x += game->plr.delta_x;
	game->map.side = 0;
}

static void	on_y(t_game *game)
{
	game->map.map_y += game->map.step_y;
	game->plr.dist_y += game->plr.delta_y;
	game->map.side = 1;
}

void	get_next_position(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->plr.dist_x < game->plr.dist_y)
		{
			if ((game->map.map_x + game->map.step_x) < 0 || \
				(game->map.map_x + game->map.step_x) >= (int)game->map.map_h)
				return ;
			on_x(game);
		}
		else
		{
			if ((game->map.map_y + game->map.step_y) < 0 || \
				(game->map.map_y + game->map.step_y) >= (int)game->map.map_l)
				return ;
			on_y(game);
		}
		if (game->map.grid[game->map.map_x] && \
					game->map.grid[game->map.map_x][game->map.map_y] == '1')
			hit = 1;
	}
}
