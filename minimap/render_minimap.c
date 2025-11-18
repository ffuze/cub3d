#include "../cub3d.h"

// static void	my_pixelput(t_game *game, int color, float x, float y)
// {}

// Colors the main pixel and fills the space around it.
void	ft_padding(t_game *game, int color, float x, float y)
{
	int	px;
	int	py;
	int	pixel_index;
	int	pixel_x;
	int	pixel_y;

	if (x < 0 || x >= GM.map_h || y < 0 || y >= GM.map_l)
		return;
	py = -game->scale/2;
	while (py < game->scale/2)
	{
		px = -game->scale/2;
		while (px < game->scale/2)
		{
			pixel_x = (y * game->scale + px);//center_x = (int)(x * game->scale);
			pixel_y = (x * game->scale + py);//center_y = (int)(y * game->scale);
			if (pixel_x >= 0 && pixel_x < WINWIDTH && pixel_y >= 0 && pixel_y < WINHEIGHT)
			{
				pixel_index = ((int)(x * game->scale + py) * GW.line_len) + \
							((int)(y * game->scale + px) * (GW.bpp / 8));
				*(unsigned int*)(GW.addr + pixel_index) = color;
			}
			px++;
		}
		py++;
	}
}

// Determines the pixel's color.
static int	pick_color(t_game *game, size_t i, size_t j)
{
	if (game->map.grid[i][j] == '1')
		return (0x000000);
	else if (game->map.grid[i][j] == '0')
		return (0xFFFFFF);
	else if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' \
				|| game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
		return (0xFFFFFF);
	else
		return (-1);
}

void	render_minimap(t_game *game)
{
	size_t	i;
	size_t	j;
	int		color;

	i = 0;
	j = 0;
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
