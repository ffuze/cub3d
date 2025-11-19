#include "cub3d.h"

void	free_mapstruct(t_map *map)
{
	if (map->n_txtr)
		free(map->n_txtr);
	if (map->s_txtr)
		free(map->s_txtr);
	if (map->e_txtr)
		free(map->e_txtr);
	if (map->w_txtr)
		free(map->w_txtr);
	if (map->grid)
		free_dpc(map->grid);
}

void	free_textures(t_game *game, t_texture *textures, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (textures[i].img_ptr)
			mlx_destroy_image(game->win.mlx_ptr, textures[i].img_ptr);
		i++;
	}
	free(textures);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_image(game->win.mlx_ptr, game->win.nimg);
	mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	mlx_destroy_display(game->win.mlx_ptr);
	free(game->keys);
	free(game->win.mlx_ptr);
}
