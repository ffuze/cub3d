/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:21:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	check_map_limits(t_game *game, float x, float y, float margin)
{
	if (x - margin < 0 || x + margin >= game->map.map_h)
		return (1);
	if (y - margin < 0 || y + margin >= game->map.map_l)
		return (1);
	if (!game->map.grid[(int)x] || !game->map.grid[(int)x][(int)y])
		return (1);
	return (0);
}

// x == pos_x --> new_x, y == pos_y --> new_y
// Returns 1 if a wall is found.
int	check_collision(t_game *game, float x, float y)
{
	int		delta_x;
	int		delta_y;
	int		check_x;
	int		check_y;

	if (check_map_limits(game, x, y, 0.2))
		return (1);
	delta_x = -2;
	while (++delta_x <= 1)
	{
		delta_y = -1;
		while (delta_y <= 1)
		{
			check_x = (int)(x + delta_x * 0.2);
			check_y = (int)(y + delta_y * 0.2);
			if (check_x >= 0 && check_x < (int)game->map.map_h && \
				check_y >= 0 && check_y < (int)game->map.map_l)
			{
				if (game->map.grid[check_x][check_y] == '1')
					return (1);
			}
			delta_y++;
		}
	}
	return (0);
}
