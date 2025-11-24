/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_walk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:29:55 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_front(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr.pos_x + (game->plr.ray_x * game->plr.move_speed);
	new_y = game->plr.pos_y + (game->plr.ray_y * game->plr.move_speed);
	if (!check_collision(game, new_x, game->plr.pos_y))
		game->plr.pos_x = new_x;
	if (!check_collision(game, game->plr.pos_x, new_y))
		game->plr.pos_y = new_y;
}

void	move_behind(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr.pos_x - (game->plr.ray_x * game->plr.move_speed);
	new_y = game->plr.pos_y - (game->plr.ray_y * game->plr.move_speed);
	if (!check_collision(game, new_x, game->plr.pos_y))
		game->plr.pos_x = new_x;
	if (!check_collision(game, game->plr.pos_x, new_y))
		game->plr.pos_y = new_y;
}

void	strafe_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr.pos_x + (game->plr.ray_y * game->plr.move_speed);
	new_y = game->plr.pos_y - (game->plr.ray_x * game->plr.move_speed);
	if (!check_collision(game, new_x, game->plr.pos_y))
		game->plr.pos_x = new_x;
	if (!check_collision(game, game->plr.pos_x, new_y))
		game->plr.pos_y = new_y;
}

void	strafe_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->plr.pos_x - (game->plr.ray_y * game->plr.move_speed);
	new_y = game->plr.pos_y + (game->plr.ray_x * game->plr.move_speed);
	if (!check_collision(game, new_x, game->plr.pos_y))
		game->plr.pos_x = new_x;
	if (!check_collision(game, game->plr.pos_x, new_y))
		game->plr.pos_y = new_y;
}
