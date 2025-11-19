#include "../cub3d.h"

// rotate the player icon (WIP)
void	rotate_right_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = game->minimap.ray_x;
	game->minimap.ray_x = game->minimap.ray_x * \
			cos(-game->minimap.rot_speed) - game->minimap.ray_y * \
			sin(-game->minimap.rot_speed);
	game->minimap.ray_y = old_ray_x * \
			sin(-game->minimap.rot_speed) + game->minimap.ray_y * \
			cos(-game->minimap.rot_speed);
}

// rotate the player icon (WIP)
void	rotate_left_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = game->minimap.ray_x;
	game->minimap.ray_x = game->minimap.ray_x * \
			cos(game->minimap.rot_speed) - game->minimap.ray_y * \
			sin(game->minimap.rot_speed);
	game->minimap.ray_y = old_ray_x * \
			sin(game->minimap.rot_speed) + game->minimap.ray_y * \
			cos(game->minimap.rot_speed);
}
