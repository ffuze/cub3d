/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_on_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:26:48 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:26:49 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	my_pixelput_player(t_game *game, t_pix *pix)
{
	int	pixel_index;
	int	pixel_x;
	int	pixel_y;

	pixel_x = (pix->y * game->scale + pix->px - 5);
	pixel_y = (pix->x * game->scale + pix->py - 5);
	if (pixel_x >= 0 && pixel_x < WINWIDTH && \
				pixel_y >= 0 && pixel_y < WINHEIGHT)
	{
		pixel_index = ((int)(pix->x * game->scale + pix->py - 5) * \
			game->win.line_len) + ((int)(pix->y * game->scale + pix->px - 5) * \
														(game->win.bpp / 8));
		*(unsigned int *)(game->win.addr + pixel_index) = pix->color;
	}
}

// Colors in red the main pixel and fills the space around it to indicate the
//  player's position on the minimap.
void	ft_padding_player(t_game *game, int color, float x, float y)
{
	t_pix	pix;

	pix.x = x;
	pix.y = y;
	pix.color = color;
	if (x < 0 || x >= game->map.map_h || y < 0 || y >= game->map.map_l)
		return ;
	pix.py = -game->scale / 3.5;
	while (pix.py < game->scale / 3.5)
	{
		pix.px = -game->scale / 3.5;
		while (pix.px < game->scale / 3.5)
		{
			my_pixelput_player(game, &pix);
			pix.px++;
		}
		pix.py++;
	}
}
