/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:21:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 12:45:18 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	sync_minimap_player(t_game *game)
{
	game->minimap.pos_x = game->plr.pos_x;
	game->minimap.pos_y = game->plr.pos_y;
	game->minimap.ray_x = game->plr.ray_x;
	game->minimap.ray_y = game->plr.ray_y;
}

void	execute_algorithm(t_game *game)
{
	int	i;

	i = -1;
	while (++i < WINWIDTH)
	{
		game->map.x = i;
		get_ray_derivates(game);
		calculate_nearest_coords(game);
		get_next_position(game);
		get_texture_coords(game);
		draw_ver_line(game, i);
	}
}

static bool	init_mlx(t_game *game)
{
	game->win.mlx_ptr = mlx_init();
	if (!game->win.mlx_ptr)
		return (0);
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr, \
				WINWIDTH, WINHEIGHT, "cub3D");
	if (!game->win.win_ptr)
		return (0);
	game->win.nimg = mlx_new_image(game->win.mlx_ptr, WINWIDTH, WINHEIGHT);
	game->win.addr = mlx_get_data_addr(game->win.nimg, &game->win.bpp, \
		&game->win.line_len, &game->win.endian);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	if (argc != 2)
		return (1);
	game = (t_game){0};
	if (parse_map_file(argv[1], &game.map, &game.plr) == 0)
		return (1);
	if (!init_mlx(&game))
		return (1);
	initialize_all(&game);
	get_fps(&game);
	check_plr_dir(&game);
	sync_minimap_player(&game);
	load_all_textures(&game);
	execute_algorithm(&game);
	mlx_put_image_to_window(game.win.mlx_ptr, game.win.win_ptr, \
											game.win.nimg, 0, 0);
	render_minimap(&game);
	ft_hooks(&game);
	mlx_loop(game.win.mlx_ptr);
}
//Alek u are preciuos and we love you a lot <3
//if this was you leo, lets kis
// (づ ￣ ³￣)づ
// uwu
