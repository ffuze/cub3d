#include "./cub3d.h"

int main(int argc, char **argv)
{
	t_game  game;
	int		i;
	
	(void)argv;
	i = 0;
	if (argc != 2)
		return (0);
	game = (t_game){0};
	initialize_all(&game);
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
		return (0);
	game.win.win_ptr = mlx_new_window(game.win.mlx_ptr,
		WINWIDTH, WINHEIGHT, "cub3D");
	if (!game.win.win_ptr)
		return (0);
	game.win.nimg = mlx_new_image(game.win.mlx_ptr, WINWIDTH, WINHEIGHT);
	game.win.addr = mlx_get_data_addr(game.win.nimg, &game.win.bits_per_pixel, \
		&game.win.line_length, &game.win.endian);
	if (parse_map_file(argv[1], &game.map, &game.plr) == 0)
	{
		mlx_destroy_image(game.win.mlx_ptr, game.win.nimg);
		mlx_destroy_window(game.win.mlx_ptr, game.win.win_ptr);
		mlx_destroy_display(game.win.mlx_ptr);
		free(game.win.mlx_ptr);
		return (1);
	}
    draw_pixels(&game);
    mlx_put_image_to_window(game.win.mlx_ptr, game.win.win_ptr, game.win.nimg, 0, 0);
    initialize_player(&game);  // Re-inizializza dopo il parsing
    execute_algorithm(&game);
    printf("Execute algorithm completato\n"); // Debug
    ft_hooks(&game);
    printf("Hooks impostati\n"); // Debug
	mlx_loop(game.win.mlx_ptr);
}
