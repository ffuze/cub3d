#include "../cub3d.h"

// Colors the main pixel and fills the space around it.
void	ft_padding(t_game *game, int color, float x, float y)
{
	int	px;
	int	py;
	int	pixel_index;
	int	pixel_x;
	int	pixel_y;

	pixel_x = 0;
	pixel_y = 0;
	py = 0;
	// Add bounds checking
	if (x < 0 || x >= GM.map_h || y < 0 || y >= GM.map_l)
		return;
	while (py < game->scale)
	{
		px = 0;
		while (px < game->scale)
		{
			pixel_x = (int)(y * game->scale + px);  // Prima non facevamo cast a int
			pixel_y = (int)(x * game->scale + py);

			// Check if within window bounds
			if ((int)(y * game->scale + px) >= 0 && (int)(y * game->scale + px) < WINWIDTH && (int)(x * game->scale + py) >= 0 && (int)(x * game->scale + py) < WINHEIGHT)
			{
				pixel_index = ((int)(x * game->scale + py) * game->win.line_len) + \
							((int)(y * game->scale + px) * (game->win.bits_per_pixel / 8));
				*(unsigned int*)(game->win.addr + pixel_index) = color;
			}
			px++;
		}
		py++;
	}
}

// Determines the pixel's color.
static int	pick_color(t_game *game, size_t i, size_t j)
{
	if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' \
				|| game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
		return (0xFFFFFF);//0xFF0000 red
	else if (game->map.grid[i][j] == '0')
		return (0xFFFFFF);
	else if (game->map.grid[i][j] == '1')
		return (0x000000);
	else
		return (-1);
}

void	render_minimap(t_game *game)
{
	size_t	i;
	size_t	j;
	int		color;

	i = 10;
	j = 10;
	while (i < game->map.map_h)
	{
		j = 0;
		while (j < ft_strlen(game->map.grid[i]))
		{
			color = pick_color(game, i, j);
			if (color < 0)
			{
				j++;
				continue ;
			}
			ft_padding(game, color, (float)i, (float)j);
			j++;
		}
		i++;
	}
	GMM.pos_x = GP.pos_x;
	GMM.pos_y = GP.pos_y;
	ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
}
