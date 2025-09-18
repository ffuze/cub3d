#include "./cub3d.h"

void	draw_pixels(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	line_l;
	int		color;
	int		px, py;
	int		scale = 5;

	i = 0;
	j = 0;
	while (i < game->map.map_h)
	{
		j = 0;
		line_l = ft_strlen(game->map.grid[i]);
		while (j < line_l)
		{
			// Determina colore
			if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' \
				|| game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
				color = 0xFF0000;
			else if (game->map.grid[i][j] == '0')
				color = 0xFFFFFF;
			else if (game->map.grid[i][j] == '1')
				color = 0x000000;
			else
			{
				j++;
				continue;
			}

			// Riempe lo spazio intorno al pixel principale
			py = 0;
			while (py < scale)
			{
				px = 0;
				while (px < scale)
				{
					int pixel_index = ((i * scale + py) * game->win.line_length) + \
								((j * scale + px) * (game->win.bits_per_pixel / 8));// my_pixelput()
					*(unsigned int*)(game->win.addr + pixel_index) = color;
					px++;
				}
				py++;
			}
			j++;
		}
		i++;
	}
}


/* void	draw_pixels(t_game *game)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	size_t line_l = ft_strlen(game->map.grid[i]);
	while (i < game->map.map_h)
	{
		j = 0;
		// printf("h ; %d\n", h);/////////////////////////////////
		// printf("%s\n", game->map.grid[i]);///////////////////////////
		// printf("draw_pixel j: %zu\n", j);///////////////////////////////
		while (j < line_l)/
		{
			// printf("draw_pixel j: %zu\n", j);
			if (game->map.grid[i][j] == 'N'
				|| game->map.grid[i][j] == 'E'
				|| game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'W')
				mlx_pixel_put(game->win.mlx_ptr, game->win.win_ptr, j*10, i*10, 0xFF0000);
			else if (game->map.grid[i][j] == '0')
				mlx_pixel_put(game->win.mlx_ptr, game->win.win_ptr, j*10, i*10, 16777215);
			else if (game->map.grid[i][j] == '1')
				mlx_pixel_put(game->win.mlx_ptr, game->win.win_ptr, j*10, i*10, 0x000000);
			else
				perror("Invalid character detected in the map\n");
			j++;
		}
		// printf("draw_pixel i: %zu\n", i);///////////////////////////////
		i++;
	}
} */
