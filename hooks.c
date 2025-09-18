#include "./cub3d.h"

int on_destroy(t_game *game)
{
	mlx_destroy_image(game->win.mlx_ptr, game->win.nimg);
	mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	mlx_destroy_display(game->win.mlx_ptr);
	free(game->win.mlx_ptr);
	free_mapstruct(&game->map);
	exit(0);
}

static int	on_keypress(int keysym, t_game *game)
{
	(void)game;
	if (keysym == XK_Escape)
		on_destroy(game);
	return (1);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, game);
	mlx_hook(game->win.win_ptr, 2, 1L << 0,
		&on_keypress, game);
}
