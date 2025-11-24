/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:25:59 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	on_destroy(t_game *game)
{
	free_textures(game, game->txtrs, 4);
	mlx_destroy_image(game->win.mlx_ptr, game->win.nimg);
	mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	mlx_destroy_display(game->win.mlx_ptr);
	free(game->win.mlx_ptr);
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
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, \
												game->win.nimg, 0, 0);
	return (0);
}

/* Toggle minimap based on current scale instead of a static flag. */
static int	on_key_press(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		on_destroy(game);
	else if (keysym == XK_m || keysym == XK_M)
	{
		if (game->scale == 0)
			game->scale = 10;
		else
			game->scale = 0;
	}
	else if (keysym == XK_Shift_L)
		game->plr.move_speed = game->plr.default_move_speed * 1.61;
	if (keysym < 65535)
		game->keys[keysym] = true;
	return (0);
}

static int	on_key_release(int keysym, t_game *game)
{
	if (keysym == XK_Shift_L)
		game->plr.move_speed = game->plr.default_move_speed;
	if (keysym < 65535)
		game->keys[keysym] = false;
	return (0);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, game);
	mlx_hook(game->win.win_ptr, KeyPress, KeyPressMask,
		&on_key_press, game);
	mlx_hook(game->win.win_ptr, KeyRelease, KeyReleaseMask,
		&on_key_release, game);
	mlx_loop_hook(game->win.mlx_ptr, &ft_game_loop, game);
}
