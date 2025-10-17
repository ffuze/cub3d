#include "../cub3d.h"

// VVV this shit now works almost properly. check function check_collision() VVV
//==================BROKEN==================-
/* // Returns 1 if next to a wall, 0 otherwise
bool	near_wall(t_game *game, t_dir dir)
{
	int	x;
	int	y;

	x = game->plr.pos_x;
	y = game->plr.pos_y;
	if (dir == NORTH)
		x = game->plr.pos_x - 0.1;
	else if (dir == SOUTH)
		x = game->plr.pos_x + 0.1;
	else if (dir == WEST)
		y = game->plr.pos_y - 0.1;
	else if (dir == EAST)
		y = game->plr.pos_y + 0.1;
	if (game->map.grid[x][y] == '1')
		return (1);
	return (0);
} */

// rotate the player icon (WIP)
void	rotate_right_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = GMM.ray_x;
	GMM.ray_x = GMM.ray_x * cos(-GMM.rot_speed) - GMM.ray_y * sin(-GMM.rot_speed);
	GMM.ray_y = old_ray_x * sin(-GMM.rot_speed) + GMM.ray_y * cos(-GMM.rot_speed);
	// ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
}

// rotate the player icon (WIP)
void	rotate_left_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = GMM.ray_x;
	GMM.ray_x = GMM.ray_x * cos(GMM.rot_speed) - GMM.ray_y * sin(GMM.rot_speed);
	GMM.ray_y = old_ray_x * sin(GMM.rot_speed) + GMM.ray_y * cos(GMM.rot_speed);
	// ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
}
