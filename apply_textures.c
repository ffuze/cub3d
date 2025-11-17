#include "./cub3d.h"

void	init_texture_array(t_game *game, char	**paths)
{
	paths[0] = game->map.n_txtr;
	paths[1] = game->map.s_txtr;
	paths[2] = game->map.e_txtr;
	paths[3] = game->map.w_txtr;
	paths[4] = NULL;
}

static	int	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(GW.mlx_ptr, path, \
										&tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, \
									&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

bool	load_all_textures(t_game *game)// mettere a bool
{
	char		*paths[5];
	t_texture	*textures;
	int			i;

	init_texture_array(game, paths);
	textures = malloc(4 * sizeof(t_texture));
	if (!textures)
		return (0);
	i = 0;
	while (paths[i])
	{
		if (!load_texture(game, &textures[i], paths[i]))
		{
			free_textures(game, textures, i);
			return (0);
		}
		i++;
	}
	game->textures = textures;
	game->texture_count = 4;
	return (1);
}
