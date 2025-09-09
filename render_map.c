/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:19:25 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/09 19:02:04 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void    draw_pixels(t_game *game)
{
	size_t i;
	size_t j;
	//char	*hex_code;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		int h = ft_strlen(game->map.grid[i]);
		printf("h ; %d\n", h);
		printf("%s\n", game->map.grid[i]);
		printf("draw_pixel j: %zu\n", j);
		while (j < ft_strlen(game->map.grid[i]))
		{
			printf("draw_pixel j: %zu\n", j);
			if (game->map.grid[i][j] == 'N'
				|| game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'W')
				mlx_pixel_put(game->window.mlx_ptr, game->window.win_ptr, i, j, 0xFFDE21);
			else if (game->map.grid[i][j] == '0')
				mlx_pixel_put(game->window.mlx_ptr, game->window.win_ptr, i, j, 0x808080);
			else if (game->map.grid[i][j] == '1')
				mlx_pixel_put(game->window.mlx_ptr, game->window.win_ptr, i, j, 0x000000);
			else
				perror("Invalid character detected in the map\n");
			// mlx_put_image_to_window(game->window.mlx_ptr,
			// 	game->window.win_ptr, NULL, i * 32, j * 32);
			j++;
		}
		printf("draw_pixel i: %zu\n", i);
		i++;
	}
}