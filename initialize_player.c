#include "./cub3d.h"

static void	so_direction(t_game *game)
{
	game->plr.ray_x = 1;
	game->plr.ray_y = 0;
	game->map.plane_x = 0;
	game->map.plane_y = -0.66f;
}

static void	ea_direction(t_game *game)
{
	game->plr.ray_x = 0;
	game->plr.ray_y = 1;
	game->map.plane_x = 0.66f;
	game->map.plane_y = 0;
}

static void	we_direction(t_game *game)
{
	game->plr.ray_x = 0;
	game->plr.ray_y = -1;
	game->map.plane_x = -0.66f;
	game->map.plane_y = 0;
}

void	check_plr_dir(t_game *game)
{
	if (game->plr.p_dir == NORTH)
	{
		game->plr.ray_x = -1;
		game->plr.ray_y = 0;
		game->map.plane_x = 0;
		game->map.plane_y = 0.66f;
	}
	else if (game->plr.p_dir == SOUTH)
		so_direction(game);
	else if (game->plr.p_dir == EAST)
		ea_direction(game);
	else if (game->plr.p_dir == WEST)
		we_direction(game);
}

void	initialize_player(t_game *game)
{
	game->plr.pos_x = 0;
	game->plr.pos_y = 0;
	game->plr.delta_x = 0;
	game->plr.delta_y = 0;
	game->plr.dist_x = 0;
	game->plr.dist_y = 0;
	game->plr.move_speed = 0.013;
	game->plr.default_move_speed = 0.013;
	game->plr.perp_wall_dist = 0;
	game->plr.ray_dir_x = 0;
	game->plr.ray_dir_y = 0;
	game->plr.rot_speed = 0.02;
	check_plr_dir(game);
}
