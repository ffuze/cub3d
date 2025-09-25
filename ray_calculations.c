#include "./cub3d.h"

void    get_ray_derivates(t_game *game)
{
	game->map.map_x = (int)game->plr.pos_x;
	game->map.map_y = (int)game->plr.pos_y;
	game->map.camera_x = 2 * game->map.x / (double)WINWIDTH - 1;
	game->plr.ray_dir_x = game->plr.ray_x + game->map.plane_x * game->map.camera_x;
	game->plr.ray_dir_y = game->plr.ray_y + game->map.plane_y * game->map.camera_x;
	if (game->plr.ray_dir_x == 0 || game->plr.ray_dir_y == 0)
	{
		printf("Error: ray direction is zero\n");
		on_destroy(game);
	}
	game->plr.delta_x = 1 / game->plr.ray_dir_x;
	game->plr.delta_y = 1 / game->plr.ray_dir_y;
}

void	calculate_nearest_coords(t_game *game)
{
	if (game->plr.ray_dir_x < 0)
	{
		game->map.step_x = -1;
		game->plr.dist_x = (game->plr.pos_x - game->map.map_x) * game->plr.delta_x;
	}
	else
	{
		game->map.step_x = 1;
		game->plr.dist_x = ((float)game->map.map_x + 1.0 - game->plr.pos_x) * game->plr.delta_x;
	}
	if (game->plr.ray_dir_y < 0)
	{
		game->map.step_y = -1;
		game->plr.dist_y = (game->plr.pos_y - game->map.map_y) * game->plr.delta_y;
	}
	else
	{
		game->map.step_y = 1;
		game->plr.dist_y = ((float)game->map.map_y + 1.0 - game->plr.pos_y) * game->plr.delta_y;
	}
}

void	get_next_position(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (game->plr.dist_x < game->plr.dist_y)
		{
			game->map.map_x += game->map.step_x;
			game->plr.dist_x += game->plr.delta_x;
			game->map.side = 0;
		}
		else
		{
			game->map.map_y += game->map.step_y;
			game->plr.dist_y += game->plr.delta_y;
			game->map.side = 1;
		}
		if (game->map.grid[game->map.map_x][game->map.map_y] == '1')
			hit = 1;
	}
}

void    execute_algorithm(t_game *game)
{
	int     i;
	double  time;

	i = -1;
	time = get_current_time();
	while (++i < 501) // con WINWIDTH non funziona 
	{
		game->map.x = i;
		get_ray_derivates(game);
		calculate_nearest_coords(game);
		get_next_position(game);
		if (game->map.side)
			game->plr.perp_wall_dist = game->plr.dist_y - game->plr.delta_y;
		else
			game->plr.perp_wall_dist = game->plr.dist_x - game->plr.delta_x;
		draw_ver_line(game, i);
		get_fps(game);
	}
	// Put the rendered image to the window
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
}