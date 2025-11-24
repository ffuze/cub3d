/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:29:55 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;

	old_ray_x = game->plr.ray_x;
	old_plane_x = game->map.plane_x;
	game->plr.ray_x = game->plr.ray_x * \
		cos(-game->plr.rot_speed) - game->plr.ray_y * sin(-game->plr.rot_speed);
	game->plr.ray_y = old_ray_x * \
		sin(-game->plr.rot_speed) + game->plr.ray_y * cos(-game->plr.rot_speed);
	game->map.plane_x = game->map.plane_x * cos(-game->plr.rot_speed) - \
								game->map.plane_y * sin(-game->plr.rot_speed);
	game->map.plane_y = old_plane_x * sin(-game->plr.rot_speed) + \
								game->map.plane_y * cos(-game->plr.rot_speed);
}

void	rotate_left(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;

	old_ray_x = game->plr.ray_x;
	old_plane_x = game->map.plane_x;
	game->plr.ray_x = game->plr.ray_x * \
		cos(game->plr.rot_speed) - game->plr.ray_y * sin(game->plr.rot_speed);
	game->plr.ray_y = old_ray_x * \
		sin(game->plr.rot_speed) + game->plr.ray_y * cos(game->plr.rot_speed);
	game->map.plane_x = game->map.plane_x * \
		cos(game->plr.rot_speed) - game->map.plane_y * sin(game->plr.rot_speed);
	game->map.plane_y = old_plane_x * \
		sin(game->plr.rot_speed) + game->map.plane_y * cos(game->plr.rot_speed);
}
