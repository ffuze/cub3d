#include "./cub3d.h"

void    get_ray_derivates(t_game *game)
{
	gm.map_x = (int)gp.pos_x;
	gm.map_y = (int)gp.pos_y;
	gm.camera_x = 2 * gm.x / (double)WINWIDTH - 1;
	gp.ray_dir_x = gp.ray_x + gm.plane_x * gm.camera_x;
	gp.ray_dir_y = gp.ray_y + gm.plane_y * gm.camera_x;
	if (gp.ray_dir_x == 0)
		gp.delta_x = 1e30;
	else
		gp.delta_x = fabs(1 / gp.ray_dir_x);
		
	if (gp.ray_dir_y == 0)
		gp.delta_y = 1e30;
	else
		gp.delta_y = fabs(1 / gp.ray_dir_y);
}

void	calculate_nearest_coords(t_game *game)
{
	if (gp.ray_dir_x < 0)
	{
		gm.step_x = -1;
		gp.dist_x = (gp.pos_x - gm.map_x) * gp.delta_x;
	}
	else
	{
		gm.step_x = 1;
		gp.dist_x = ((float)gm.map_x + 1.0 - gp.pos_x) * gp.delta_x;
	}
	if (gp.ray_dir_y < 0)
	{
		gm.step_y = -1;
		gp.dist_y = (gp.pos_y - gm.map_y) * gp.delta_y;
	}
	else
	{
		gm.step_y = 1;
		gp.dist_y = ((float)gm.map_y + 1.0 - gp.pos_y) * gp.delta_y;
	}
}

void	get_next_position(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (gp.dist_x < gp.dist_y)
		{
			if ((gm.map_x + gm.step_x) < 0 || (gm.map_x + gm.step_x) >= (int)gm.map_h)/* || (gm.map_y) < 0 || (gm.map_y) >= (int)gm.map_l */
			{
				return ;
			}
			gm.map_x += gm.step_x;
			gp.dist_x += gp.delta_x;
			gm.side = 0;
		}
		else
		{
			if ((gm.map_y + gm.step_y) < 0 || (gm.map_y + gm.step_y) >= (int)gm.map_l)
			{
				return ;
			}
			gm.map_y += gm.step_y;
			gp.dist_y += gp.delta_y;
			gm.side = 1;
		}
		if (gm.grid[gm.map_y] && gm.grid[gm.map_y][gm.map_x] == '1')
		{
			hit = 1;
		}
	}
}

void    execute_algorithm(t_game *game)
{
	int     i;
	double  time;

	i = -1;
	time = get_current_time();
	while (++i < WINWIDTH)
	{
		gm.x = i;
		get_ray_derivates(game);
		calculate_nearest_coords(game);
		get_next_position(game);
		if (gm.side)
			gp.perp_wall_dist = gp.dist_y - gp.delta_y;
		else
			gp.perp_wall_dist = gp.dist_x - gp.delta_x;
		draw_ver_line(game, i);
	}
	mlx_put_image_to_window(gw.mlx_ptr, gw.win_ptr, gw.nimg, 0, 0);
}