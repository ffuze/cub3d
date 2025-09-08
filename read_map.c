/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:54 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/08 18:25:34 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int    get_map_height(int fd, t_game *game)
{
    int     found_height;
    char    *line;

    found_height = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        found_height++;
    }
    return (found_height);
}

void    load_map(t_game *game, const char *filename)
{
    int     fd;
    int     i;
    char    *temp_line;
    
    i = 0;
    fd = open(filename, O_RDONLY);
    if (!fd)
    {
        printf("--------------------\n");
        return (0);
    }
    while (++i < get_map_height(fd, game))
    {
        temp_line = get_next_line(fd);
        if (!temp_line)
            break ;
        game->map.grid[i] = temp_line;
    }
}

