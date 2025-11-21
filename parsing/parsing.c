#include "../cub3d.h"

static void	init_mapvars(t_map *map)
{
	map->n_players = 0;
	map->n_txtr = NULL;
	map->s_txtr = NULL;
	map->e_txtr = NULL;
	map->w_txtr = NULL;
	map->map_h = 0;
	map->map_l = 0;
	map->fcol = -1;
	map->ccol = -1;
	map->grid = NULL;
}

static void	def_starting_direction(t_map *map, t_player *plr, int i, int j)
{
	if (map->grid[i][j] == 'N')
		plr->p_dir = NORTH;
	else if (map->grid[i][j] == 'S')
		plr->p_dir = SOUTH;
	else if (map->grid[i][j] == 'E')
		plr->p_dir = EAST;
	else if (map->grid[i][j] == 'W')
		plr->p_dir = WEST;
	plr->pos_x = i + 0.5;
	plr->pos_y = j + 0.5;
}

// Player's spwaning position.
static void	init_player(t_map *map, t_player *plr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	plr->pos_x = 0;
	plr->pos_y = 0;
	plr->p_dir = MISSING;
	while (map->grid[i])
	{
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || \
					map->grid[i][j] == 'S' || \
					map->grid[i][j] == 'E' || \
					map->grid[i][j] == 'W')
				return (def_starting_direction(map, plr, i, j));
			j++;
		}
		j = 0;
		i++;
	}
}

// Reads the .ber file to parse it and save the data found in it.
bool	parse_map_file(char *mapfile, t_map *map, t_player *plr)
{
	int		fd;
	char	*str;

	str = NULL;
	init_mapvars(map);
	if (!ft_strrcmp(mapfile, ".cub", 4))
		return (ft_printfd(2, RED"Error\nInvalid file extension\n"NO_ALL), 0);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (ft_printfd(2, RED"Error\nCan't read from file\n"NO_ALL), 0);
	if (!parse_textures(map, &str, fd))
		return (close(fd), 0);
	if (!parse_map(map, &str, fd))
		return (0);
	init_player(map, plr);
	return (close(fd), 1);
}
