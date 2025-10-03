#include "../cub3d.h"

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


void	strafe_right_minimap(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x + gp.ray_y * gp.move_speed;
	new_y = gp.pos_y - gp.ray_x * gp.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gp.pos_x, gp.pos_y);
			gp.pos_x = new_x;
			gp.pos_y = new_y;
			ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
		}
	}
}

void	strafe_left_minimap(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x - gp.ray_y * gp.move_speed;
	new_y = gp.pos_y + gp.ray_x * gp.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gp.pos_x, gp.pos_y);
			gp.pos_x = new_x;
			gp.pos_y = new_y;
			ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
		}
	}
}

void	move_up_minimap(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x + gp.ray_x * gp.move_speed;
	new_y = gp.pos_y + gp.ray_y * gp.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gp.pos_x, gp.pos_y);
			gp.pos_x = new_x;
			gp.pos_y = new_y;
			ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
		}
	}
}

void	move_down_minimap(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x - gp.ray_x * gp.move_speed;
	new_y = gp.pos_y - gp.ray_y * gp.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gp.pos_x, gp.pos_y);
			gp.pos_x = new_x;
			gp.pos_y = new_y;
			ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
		}
	}
}

void	rotate_right_minimap(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;

	old_ray_x = gp.ray_x;
	old_plane_x = gm.plane_x;
	gp.ray_x = gp.ray_x * cos(-gp.rot_speed) - gp.ray_y * sin(-gp.rot_speed);
	gp.ray_y = old_ray_x * sin(-gp.rot_speed) + gp.ray_y * cos(-gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(-gp.rot_speed) - gm.plane_y * sin(-gp.rot_speed);
	gm.plane_y = old_plane_x * sin(-gp.rot_speed) + gm.plane_y * cos(-gp.rot_speed);
	ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
}

void	rotate_left_minimap(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;

	old_ray_x = gp.ray_x;
	old_plane_x = gm.plane_x;
	gp.ray_x = gp.ray_x * cos(gp.rot_speed) - gp.ray_y * sin(gp.rot_speed);
	gp.ray_y = old_ray_x * sin(gp.rot_speed) + gp.ray_y * cos(gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(gp.rot_speed) - gm.plane_y * sin(gp.rot_speed);
	gm.plane_y = old_plane_x * sin(gp.rot_speed) + gm.plane_y * cos(gp.rot_speed);
	ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
}

void	move_on_minimap(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		// if (near_wall(game, NORTH))
		// 	return ;
		move_front(game);
		move_up_minimap(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_x -= 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_s)
	{
		// if (near_wall(game, SOUTH))
		// 	return ;
		move_behind(game);
		move_down_minimap(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_x += 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_a)
	{
		// if (near_wall(game, WEST))
		// 	return ;
		strafe_left(game);
		strafe_left_minimap(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_y -= 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
	else if (keysym == XK_d)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		strafe_right(game);
		strafe_right_minimap(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_y += 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
}
