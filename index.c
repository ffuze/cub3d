#include "./cub3d.h"

void	init_params(t_game	*game)
{
	game->map.grid = NULL;
	game->map.p_dir = 0;
	game->player.x = 20;
	game->player.y = 20;
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
	int		i;
	
	i = 0;
	if (argc != 2)
		return (0);
	game = (t_game){0};
	game.window.mlx_ptr = mlx_init();
	if (!game.window.mlx_ptr)
		return (0);
	init_params(&game);
	game.window.win_ptr = mlx_new_window(game.window.mlx_ptr,
		WWIDTH, WHEIGHT, "cub3D");
	if (!game.window.win_ptr)
		return (0);
	// load_map(&game, argv[1]);
	if (parse_map_file(argv[1], &game.map) == 0)
		return (1);
	draw_pixels(&game);
	free(game.map.grid);
	mlx_hook(game.window.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &game);
	mlx_hook(game.window.win_ptr, 2, 1L << 0,
		&on_keypress, &game);
	mlx_loop(game.window.mlx_ptr);
}
