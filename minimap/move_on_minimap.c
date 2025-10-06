#include "../cub3d.h"

void	sync_minimap_player(t_game *game)
{
	gmm.pos_x = gp.pos_x;
	gmm.pos_y = gp.pos_y;
	gmm.ray_x = gp.ray_x;
	gmm.ray_y = gp.ray_y;
}

void	sync_player_minimap(t_game *game)
{
	gp.pos_x = gmm.pos_x;
	gp.pos_y = gmm.pos_y;
	gp.ray_x = gmm.ray_x;
	gp.ray_y = gmm.ray_y;
}

void	toggle_minimap_sync(t_game *game)
{
	gmm.sync_with_player = !gmm.sync_with_player;
	if (gmm.sync_with_player)	
		printf("Minimap sync enabled\n");
	else
		printf("Minimap sync dsiabled\n");
}

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

	new_x = gmm.pos_x + gmm.ray_y * gmm.move_speed;
	new_y = gmm.pos_y - gmm.ray_x * gmm.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gmm.pos_x, gmm.pos_y);
			gmm.pos_x = new_x;
			gmm.pos_y = new_y;
			ft_padding(game, 0xFF0000, gmm.pos_x, gmm.pos_y);
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
			ft_padding(game, 0xFFFFFF, gmm.pos_x, gmm.pos_y);
			gmm.pos_x = new_x;
			gmm.pos_y = new_y;
			ft_padding(game, 0xFF0000, gmm.pos_x, gmm.pos_y);
		}
	}
}

void	move_up_minimap(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gmm.pos_x + gmm.ray_x * gmm.move_speed;
	new_y = gmm.pos_y + gmm.ray_y * gmm.move_speed;
	if (new_x >= 0 && new_x < gm.map_h && new_y >= 0 && new_y < gm.map_l)
	{
		if (gm.grid[(int)new_x][(int)new_y] == '0')
		{
			ft_padding(game, 0xFFFFFF, gmm.pos_x, gmm.pos_y);
			gmm.pos_x = new_x;
			gmm.pos_y = new_y;
			ft_padding(game, 0xFF0000, gmm.pos_x, gmm.pos_y);
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
			ft_padding(game, 0xFFFFFF, gmm.pos_x, gmm.pos_y);
			gmm.pos_x = new_x;
			gmm.pos_y = new_y;
			ft_padding(game, 0xFF0000, gmm.pos_x, gmm.pos_y);
		}
	}
}

void	rotate_right_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = gmm.ray_x;
	gmm.ray_x = gmm.ray_x * cos(-gmm.rot_speed) - gmm.ray_y * sin(-gmm.rot_speed);
	gmm.ray_y = old_ray_x * sin(-gmm.rot_speed) + gmm.ray_y * cos(-gmm.rot_speed);
	ft_padding(game, 0xFF0000, gmm.pos_x, gmm.pos_y);
}

void	rotate_left_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = gmm.ray_x;
	gmm.ray_x = gmm.ray_x * cos(gmm.rot_speed) - gmm.ray_y * sin(gmm.rot_speed);
	gmm.ray_y = old_ray_x * sin(gmm.rot_speed) + gmm.ray_y * cos(gmm.rot_speed);
	ft_padding(game, 0xFF0000, gp.pos_x, gp.pos_y);
}

void	move_on_minimap(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		// if (near_wall(game, NORTH))
		// 	return ;
		move_up_minimap(game);
		move_front(game);
		// ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_x -= 0.2;
		// ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_s)
	{
		// if (near_wall(game, SOUTH))
		// 	return ;
		move_down_minimap(game);
		move_behind(game);
		// ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_x += 0.2;
		// ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_a)
	{
		// if (near_wall(game, WEST))
		// 	return ;
		strafe_left_minimap(game);
		strafe_left(game);
		// ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_y -= 0.2;
		// ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
	else if (keysym == XK_d)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		strafe_right_minimap(game);
		strafe_right(game);
		// ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		// game->plr.pos_y += 0.2;
		// ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
}
