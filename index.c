#include "./cub3d.h"

void	init_params(t_game	*game)
{
	game->map.grid = NULL;
	game->map.p_dir = 0;
	game->player.x = 20;
	game->player.y = 20;
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
	if (parse_map_file(argv[1], &game.map) == 0)
		return (1);
	draw_pixels(&game);
	free(game.map.grid);

	ft_hooks(&game);

	mlx_loop(game.window.mlx_ptr);
	free_mapstruct(&game.map);
}
