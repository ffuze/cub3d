#include "./cub3d.h"

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

void	ft_hooks(t_game *game)
{
	mlx_hook(game->window.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &game);
	mlx_hook(game->window.win_ptr, 2, 1L << 0,
		&on_keypress, &game);
}
