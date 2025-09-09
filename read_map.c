/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:54 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/09 18:33:00 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void    get_map_height(int fd, t_game *game)
{
    char    *line;

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        game->map.height++;
    }
	close(fd);
}

void    print_map(t_game *game)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	printf("dovrei aver stampato qualcosa ma sono down e non lo faccio: %zu\n", game->map.height);
	while (i < game->map.height)
	{
		j = 0;
		while (j < ft_strlen(game->map.grid[i]))
		{
			printf("%c", game->map.grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	allocate_map_grid(t_game *game)
{
	game->map.grid = malloc((game->map.height + 1) * sizeof(char *));
	if (!game->map.grid)
		exit(EXIT_FAILURE);
}

void    load_map(t_game *game, const char *filename)
{
	int     fd;
	size_t     i;
	char    *temp_line;
	
	i = -1;
	fd = open(filename, O_RDONLY);
	if (!fd)
		return ;
	get_map_height(fd, game);
	fd = open(filename, O_RDONLY);
	if (!fd)
		return ;
	allocate_map_grid(game);
	while (++i < game->map.height)
	{
		temp_line = get_next_line(fd);
		if (!temp_line)
			break ;
		if (temp_line[ft_strlen(temp_line) - 1] == '\n')
			temp_line[ft_strlen(temp_line) - 1] = '\0';
		game->map.grid[i] = temp_line;
	}
	print_map(game);
	close(fd);
}

/* void    get_total_map_width(int fd, t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while ()
} */


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