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

void	move_on_minimap(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		// if (near_wall(game, NORTH))
		// 	return ;
		move_front(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		game->plr.pos_x -= 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_s)
	{
		// if (near_wall(game, SOUTH))
		// 	return ;
		move_behind(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		game->plr.pos_x += 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_x);/////////////////////////////
	}
	else if (keysym == XK_a)
	{
		// if (near_wall(game, WEST))
		// 	return ;
		move_left(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		game->plr.pos_y -= 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
	else if (keysym == XK_d)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		move_right(game);
		ft_padding(game, 0xFFFFFF, game->plr.pos_x, game->plr.pos_y);
		game->plr.pos_y += 0.2;
		ft_padding(game, 0xFF0000, game->plr.pos_x, game->plr.pos_y);
		// mlx_do_sync(game->win.mlx_ptr);
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
		printf(YELLOW"%f\n"NO_ALL, game->plr.pos_y);/////////////////////////////
	}
}
