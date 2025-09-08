/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:54 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/08 20:40:04 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

// static void    get_map_height(int fd, t_game *game)
// {
//     char    *line;

//     while (1)
//     {
//         line = get_next_line(fd);
//         if (!line)
//             break ;
//         game->map.height++;
//     }
// }

void    load_map(t_game *game, const char *filename)
{
	int     fd;
	size_t     i;
	char    *temp_line;
	
	i = 0;
	fd = open(filename, O_RDONLY);
	if (!fd)
	{
		printf("--------------------\n");
		return ;
	}
	while (++i < game->map.height)
	{
		temp_line = get_next_line(fd);
		if (!temp_line)
			break ;
		game->map.grid[i] = temp_line;
	}
}

/* void    get_total_map_width(int fd, t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while ()
} */

void    print_map(t_game *game)
{
	int i;
	while (++i < game->map.height)
	{
		while  (++j < )
	}
}

void    check_player_pos(t_game *game)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		while (j < ft_strlen(game->map.grid[i]))
		{
			/* if (game->map.grid[i][j] == 'N')
				// generate player north direction
			else if (game->map.grid[i][j] == 'S')
				// generate player south direction
			else if (game->map.grid[i][j] == 'W')
				// generate player west direction
			else if (game->map.grid[i][j] == 'E')
				// generate player east direction */
		}
	}
}