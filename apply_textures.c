#include "./cub3d.h"

void	init_texture_array(char	**paths)
{
	paths[0] = "./xpms/wall_1.xpm";
	paths[1] = "./xpms/wall_2.xpm";
	paths[2] = "./xpms/wall_3.xpm";
	paths[3] = "./xpms/wall_4.xpm";
	paths[4] = "./xpms/wall_5.xpm";
	paths[5] = "./xpms/wall_6.xpm";
}

static int	count_textures(char	**paths)
{
	int	count;

	count = 0;
	while (paths[count])
		count++;
	return (count);
}

static void		free_textures(t_game *game, t_texture *textures, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (textures[i].img_ptr)
			mlx_destroy_image(GW.mlx_ptr, textures->img_ptr);
		i++;
	}
}

static	int	load_texture(t_game *game, t_texture *textures, char *path)
{
	textures->img_ptr = mlx_xpm_file_to_image(GW.mlx_ptr, path,
		&GW.bpp, &GW.bpp);
	if (!textures->img_ptr)
		return (0);
	textures->addr = mlx_get_data_addr(textures->img_ptr, &GW.bpp,
		&GW.line_len, &GW.endian);
	if (!textures->addr)
		return (0);
	return (1);
}

int		load_all_textures(t_game *game)
{
	char		*paths;
	t_texture 	*textures;
	int			count;
	int			i;

	init_texture_array(paths);
	paths = malloc(6 * sizeof(char *));
	count = count_textures(paths);
	textures = malloc(count * sizeof(t_texture));
	i = 0;
	while (paths[i])
	{
		if (!load_texture(game, &textures, paths[i]))
			free_textures(game, &textures, i);
		i++;
	}
	game->textures = textures;
	game->texture_count = count;
}
