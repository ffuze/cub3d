#include "./cub3d.h"

void	check_plr_dir(t_game *game)
{
	if (game->plr.p_dir == NORTH)
	{
		game->plr.ray_x = 0;
		game->plr.ray_y = -1;
	}
	else if (game->plr.p_dir == SOUTH)
	{
		game->plr.ray_x = 0;
		game->plr.ray_y = 1;
	}
	else if (game->plr.p_dir == EAST)
	{
		game->plr.ray_x = 1;
		game->plr.ray_y = 0;
	}
	else if (game->plr.p_dir == WEST)
	{
		game->plr.ray_x = -1;
		game->plr.ray_y = 0;
	}
}

void    initialize_player(t_game *game)
{
	game->plr.delta_x = 0;
	game->plr.delta_y = 0;
	game->plr.dist_x = 0;
	game->plr.dist_y = 0;
	game->plr.move_speed = 5.0;
	game->plr.perp_wall_dist = 0;
	game->plr.ray_dir_x = 0;
	game->plr.ray_dir_y = 0;
	game->plr.rot_speed = 3.0;
	check_plr_dir(game);
}

void    initialize_map(t_game *game)
{
	game->map.n_txtr = NULL;
	game->map.s_txtr = NULL;
	game->map.e_txtr = NULL;
	game->map.w_txtr = NULL;
	game->map.fcol = 0;
	game->map.ccol = 0;
	game->map.grid = NULL;
	game->map.map_h = 0;
	game->map.map_l = 0;
	game->map.n_players = 0;
	game->map.plane_x = 0.66f;
	game->map.plane_y = 0.0f;
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

void    initialize_all(t_game *game)
{
	initialize_player(game);
	initialize_map(game);
}