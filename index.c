/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:28:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/05 21:40:17 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_params(t_game	*game)
{
	game->map.grid = NULL;
	game->map.player_pos = NULL;
	game->player.x = 2000;
	game->player.y = 2000;
}

int on_destroy(t_game *game)
{
	mlx_destroy_display(game->window.mlx_ptr);
	mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
	exit(0);
}

static int	on_keypress(int keysym, t_game *game)
{
	(void)game;
	if (keysym == XK_Escape)
		on_destroy(game);
	return (1);
}

int main(int argc, char **argv)
{
	t_game  game;
	
	(void)argv;
	if (argc != 1)
		return (0);
	game = (t_game){0};
	game.window.mlx_ptr = mlx_init();
	if (!game.window.mlx_ptr)
		return (0);
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr,
		WWIDTH, WHEIGHT, "cub3D");
	if (!game.window.win_ptr)
		return (0);
	mlx_pixel_put(game.window.mlx_ptr, game.window.win_ptr, game.player.x,
			game.player.x, 0xFFDE21);
	mlx_hook(game.window.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &game);
	mlx_hook(game.window.win_ptr, 2, 1L << 0,
		&on_keypress, &game);
	mlx_loop(game.window.mlx_ptr);
}