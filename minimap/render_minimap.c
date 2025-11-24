/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:26:51 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:26:52 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	my_pixelput(t_game *game, t_pix *pix)
{
	int	pixel_index;
	int	pixel_x;
	int	pixel_y;

	pixel_x = (pix->y * game->scale + pix->px);
	pixel_y = (pix->x * game->scale + pix->py);
	if (pixel_x >= 0 && pixel_x < WINWIDTH && \
				pixel_y >= 0 && pixel_y < WINHEIGHT)
	{
		pixel_index = ((int)(pix->x * game->scale + pix->py) * \
			game->win.line_len) + ((int)(pix->y * game->scale + pix->px) * \
														(game->win.bpp / 8));
		*(unsigned int *)(game->win.addr + pixel_index) = pix->color;
	}
}

// Colors the main pixel and fills the space around it.
void	ft_padding(t_game *game, int color, float x, float y)
{
	t_pix	pix;

	pix.x = x;
	pix.y = y;
	pix.color = color;
	if (x < 0 || x >= game->map.map_h || y < 0 || y >= game->map.map_l)
		return ;
	pix.py = -game->scale / 2;
	while (pix.py < game->scale / 2)
	{
		pix.px = -game->scale / 2;
		while (pix.px < game->scale / 2)
		{
			my_pixelput(game, &pix);
			pix.px++;
		}
		pix.py++;
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
	game->minimap.pos_x = game->plr.pos_x;
	game->minimap.pos_y = game->plr.pos_y;
	ft_padding_player(game, 0xFF0000, game->minimap.pos_x, game->minimap.pos_y);
}
