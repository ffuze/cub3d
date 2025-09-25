#include "./cub3d.h"

int main(int argc, char **argv)
{
	t_game  game;
	int		i;
	
	i = 0;
	if (argc != 2)
		return (0);
	game = (t_game){0};
	game.scale = 10;// Fattore di distanziamento dei pixel della minimappa
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
		return (0);
	game.win.win_ptr = mlx_new_window(game.win.mlx_ptr,
		400, 400, "cub3D");
	if (!game.win.win_ptr)
			return (0);
	initialize_all(&game);
	game.win.nimg = mlx_new_image(game.win.mlx_ptr, WINWIDTH, WINHEIGHT);
	game.win.addr = mlx_get_data_addr(game.win.nimg, &game.win.bits_per_pixel, \
		&game.win.line_length, &game.win.endian);
		//alek gooo fuck ur self and dont play valorant at all u r so bad hahaha ur aim is like iron 1 -0 RR
		//bro if i actually played valorant 100% locked in all this time id be immortal
	if (parse_map_file(argv[1], &game.map, &game.plr) == 0)
	{
		mlx_destroy_image(game.win.mlx_ptr, game.win.nimg);
		mlx_destroy_window(game.win.mlx_ptr, game.win.win_ptr);
		mlx_destroy_display(game.win.mlx_ptr);
		free(game.win.mlx_ptr);
		return (1);
	}
    mlx_put_image_to_window(game.win.mlx_ptr, game.win.win_ptr, game.win.nimg, 0, 0);
    setup_player_direction(&game);
    execute_algorithm(&game);
    printf("Execute algorithm completato\n"); // Debug
	render_minimap(&game);
	printf("Minimap renderizzata\n"); // Debug
    ft_hooks(&game);
    printf("Hooks impostati\n"); // Debug
	mlx_loop(game.win.mlx_ptr);
}
