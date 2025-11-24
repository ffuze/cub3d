/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_surroundings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:29:55 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	check_above(char **grid, size_t i, size_t j)
{
	if (j < 1 || \
			!grid[i][j] || \
			grid[i][j] == '\n' || \
			grid[i][j] == ' ')
	{
		return (0);
	}
	return (1);
}

static bool	check_below(char **grid, size_t i, size_t j)
{
	if (j < 1 || \
			!grid[i][j] || \
			grid[i][j] == '\n' || \
			grid[i][j] == ' ')
	{
		return (0);
	}
	return (1);
}

static bool	check_right(char **grid, size_t i, size_t j)
{
	if (j < 1 || \
			!grid[i][j] || \
			grid[i][j] == '\n' || \
			grid[i][j] == ' ')
	{
		return (0);
	}
	return (1);
}

static bool	check_left(char **grid, size_t i, size_t j)
{
	if (j < 0 || \
			grid[i][j] == '\n' || \
			grid[i][j] == ' ')
	{
		return (0);
	}
	return (1);
}

// Returns 0 if a wall is missing.  
bool	valid_surroundings(t_map *map, char **grid, size_t i, size_t j)
{
	map->n_players += is_player(grid[i][j]);
	if (check_above(grid, i - 1, j) == 0)
		return (0);
	else if (check_below(grid, i + 1, j) == 0)
		return (0);
	else if (check_right(grid, i, j + 1) == 0)
		return (0);
	else if (check_left(grid, i, j - 1) == 0)
		return (0);
	return (1);
}
