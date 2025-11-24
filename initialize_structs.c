/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:21:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	initialize_map(t_game *game)
{
	game->map.plane_x = 0.0f;
	game->map.plane_y = 0.66f;
	game->map.camera_x = 0.0f;
	game->map.map_x = 0;
	game->map.map_y = 0;
	game->map.step_x = 0;
	game->map.step_y = 0;
	game->map.side = 0;
	game->map.wall_height = 0;
	game->map.x = 0;
	game->map.draw_start = 0;
	game->map.draw_end = 0;
	game->map.hex_color = 0;
}

void	initialize_minimap(t_game *game)
{
	game->minimap.pos_x = game->plr.pos_x;
	game->minimap.pos_y = game->plr.pos_y;
	game->minimap.ray_x = game->plr.ray_x;
	game->minimap.ray_y = game->plr.ray_y;
	game->minimap.move_speed = 0.15f;
	game->minimap.rot_speed = 0.12f;
}

void	initialize_all(t_game *game)
{
	int	i;

	game->old_time = 0;
	game->scale = 10;
	initialize_player(game);
	initialize_map(game);
	initialize_minimap(game);
	game->keys = calloc(65535, sizeof(bool));
	if (!game->keys)
		exit(1);
	i = 0;
	while (i < 65535)
	{
		game->keys[i] = false;
		i++;
	}
}
