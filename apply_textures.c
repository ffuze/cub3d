#include "./cub3d.h"

void	init_texture_array(t_game *game, char	**paths)
{
	paths[0] = game->map.n_txtr;
	paths[1] = game->map.s_txtr;
	paths[2] = game->map.w_txtr;
	paths[3] = game->map.e_txtr;
	paths[4] = NULL;
}

static	int	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(game->win.mlx_ptr, path, \
										&tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, \
									&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

bool	load_all_textures(t_game *game)
{
	char		*paths[5];
	t_texture	*txtrs;
	int			i;

	init_texture_array(game, paths);
	txtrs = malloc(4 * sizeof(t_texture));
	if (!txtrs)
		return (0);
	i = 0;
	while (paths[i])
	{
		if (!load_texture(game, &txtrs[i], paths[i]))
		{
			free_textures(game, txtrs, i);
			return (0);
		}
		i++;
	}
	game->txtrs = txtrs;
	game->texture_count = 4;
	return (1);
}

static void	pick_texture(t_game *game)
{
	if (game->map.side == 0)
	{
		if (game->map.step_x > 0)
			game->map.tex_num = 0;
		else
			game->map.tex_num = 1;
	}
	else
	{
		if (game->map.step_y > 0)
			game->map.tex_num = 2;
		else
			game->map.tex_num = 3;
	}
}

void	get_texture_coords(t_game *game)
{
	float	wall_x;
	int		tex_width;

	if (game->map.side == 0)
		game->plr.perp_wall_dist = game->plr.dist_x - game->plr.delta_x;
	else
		game->plr.perp_wall_dist = game->plr.dist_y - game->plr.delta_y;
	pick_texture(game);
	if (game->map.side == 0)
	{
		wall_x = game->plr.pos_y + game->plr.perp_wall_dist * \
													game->plr.ray_dir_y;
	}
	else
	{
		wall_x = game->plr.pos_x + game->plr.perp_wall_dist * \
													game->plr.ray_dir_x;
	}
	wall_x -= floor(wall_x);
	tex_width = game->txtrs[game->map.tex_num].width;
	game->map.tex_x = (int)(wall_x * (double)tex_width);
	if (game->map.side == 0 && game->plr.ray_dir_x > 0)
		game->map.tex_x = tex_width - game->map.tex_x - 1;
	if (game->map.side == 1 && game->plr.ray_dir_y < 0)
		game->map.tex_x = tex_width - game->map.tex_x - 1;
}
