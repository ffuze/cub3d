#include "./cub3d.h"

int on_destroy(t_game *game)
{
	free_textures(game, game->textures, 4);
	mlx_destroy_image(GW.mlx_ptr, GW.nimg);
	mlx_destroy_window(GW.mlx_ptr, GW.win_ptr);
	mlx_destroy_display(GW.mlx_ptr);
	free(GW.mlx_ptr);
	free_mapstruct(&game->map);
	if (game->keys)
		free(game->keys);
	exit(0);
}

int	ft_game_loop(t_game *game)
{
	if (game->keys[XK_w])
		move_front(game);
	if (game->keys[XK_s])
		move_behind(game);
	if (game->keys[XK_a])
		strafe_left(game);
	if (game->keys[XK_d])
		strafe_right(game);
	if (game->keys[XK_Left])
		rotate_left(game);
	if (game->keys[XK_Right])
		rotate_right(game);
	execute_algorithm(game);
	render_minimap(game);
	mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
	return (0);
}

static int	on_key_press(int keysym, t_game *game)
{
	static int	m_set;

	if (keysym == XK_Escape)
		on_destroy(game);
	else if (keysym == XK_m)
	{
		if (!m_set)
		{
			game->scale = 10;
			m_set = 1;
		}
		else
		{
			game->scale = 20;
			m_set = 0;
		}
	}
	else if (keysym == XK_Shift_L)
		GP.move_speed = GP.default_move_speed * 1.61;
	if (keysym < 65535)
		game->keys[keysym] = true;
	return (0);
}

static int	on_key_release(int keysym, t_game *game)
{
	if (keysym == XK_Shift_L)
		GP.move_speed = GP.default_move_speed;
	if (keysym < 65535)
		game->keys[keysym] = false;
	return (0);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(GW.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, game);
	mlx_hook(GW.win_ptr, KeyPress, KeyPressMask,
		&on_key_press, game);
	mlx_hook(GW.win_ptr, KeyRelease, KeyReleaseMask,
		&on_key_release, game);
	mlx_loop_hook(GW.mlx_ptr, &ft_game_loop, game);
}
