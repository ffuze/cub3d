#include "../cub3d.h"

/////////////////////////////////////////////////////////////
void print_map_data(t_map *map, t_player *plr)
{
	ft_printf(BRCYAN"\n");
	ft_printf("n_txtr: %s\n", map->n_txtr);
	ft_printf("s_txtr: %s\n", map->s_txtr);
	ft_printf("e_txtr: %s\n", map->e_txtr);
	ft_printf("w_txtr: %s\n", map->w_txtr);
	ft_printf("fcol: %d\n", map->fcol);
	ft_printf("ccol: %d\n", map->ccol);
	ft_printf("map hight: %d\n", map->map_h);
	ft_printf("map width: %d\n", map->map_l);
	ft_printf("n_players: %d\n", map->n_players);
	if (!map->grid)
	{
		ft_printf(NO_ALL"No map found.\n");
		return ;
	}
	for (int i = 0; map->grid[i]; i++)
		ft_printf("%s\n", map->grid[i]);
	ft_printf("player x pos: %d\n", plr->x);
	ft_printf("player y pos: %d\n", plr->y);
	ft_printf("player direction: %d\n", plr->p_dir);
	ft_printf(NO_ALL"\n");
}
/////////////////////////////////////////////////////////////

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

static void	def_starting_direction(t_map *map, t_player *plr)
{
	ft_printf("maggggggggg\n");
	if (map->grid[plr->x][plr->y] == 'N')
		plr->p_dir = NORTH;
	else if (map->grid[plr->x][plr->y] == 'S')
		plr->p_dir = SOUTH;
	else if (map->grid[plr->x][plr->y] == 'E')
		plr->p_dir = EAST;
	else if (map->grid[plr->x][plr->y] == 'W')
		plr->p_dir = WEST;
}

static void	init_player(t_map *map, t_player *plr)
{
	plr->x = 0;
	plr->y = 0;
	plr->p_dir = MISSING;
	while (map->grid[plr->x])
	{
		while (map->grid[plr->x][plr->y])
		{
			if (map->grid[plr->x][plr->y] != '0' && \
					map->grid[plr->x][plr->y] != '1' && \
					map->grid[plr->x][plr->y] != ' ' && \
					map->grid[plr->x][plr->y] != '\n')
				return (def_starting_direction(map, plr));
			plr->y++;
		}
		plr->y = 0;
		plr->x++;
	}
}

// Reads the .ber file to parse it and save the data found in it.
bool	parse_map_file(char *mapfile, t_map *map, t_player *plr)
{
	int		fd;
	char	*str;

	str = NULL;
	init_mapvars(map);
	if (!ft_strrcmp(mapfile, ".cub", 4))// Parsing map file extension
		return (ft_printfd(2, RED"Error\nInvalid file extension\n"NO_ALL), 0);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (ft_printfd(2, RED"Error\nCan't read from file\n"NO_ALL), 0);

	// Parsing e salvataggio delle textures
	if (!parse_textures(map, &str, fd))
		return (0);

	// Parsing e salvataggio della mappa
	if (!parse_map(map, &str, fd))
		return (0);

	// Posizione del player
	init_player(map, plr);

	print_map_data(map, plr);////////////////////////////////
	return (close(fd), 1);
}
