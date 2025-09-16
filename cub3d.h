#ifndef CUB3D_H
# define CUB3D_H


# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MACROS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~*/
# define NO_ALL "\033[0m"

# define NO_COLOR "\e[39m"
# define BLACK "\e[30m"
# define RED "\033[31m"
# define GREEN "\e[32m"
# define BRGREEN "\033[32;1m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define BRCYAN "\033[96m"

/*~~~~~~~~~~~~BACKGROUNDS~~~~~~~~~~~~~*/
# define BGMAGENTA "\033[45m"
# define BLACK_ON_WHITE "\e[107;30m"
# define NO_BG "\e[49m"

/*~~~~~~~~~~~~~~~MORE~~~~~~~~~~~~~~~*/
# define BOLD "\e[1m"// "\e[1;4m" Bold and Underlined
# define NO_BOLD "\e[21m"

# define UNDERLINE "\e[4m"
# define NO_UNDERLINE "\e[24m"

# define BLINK "\e[5m"
# define NO_BLINK "\e[25m"

# define HIDE "\e[8m"
# define NO_HIDE "\e[28m"

/*~~~~~~~~~~~~~~~~VARs~~~~~~~~~~~~~~~~*/
// to be switched with dynamic map sizes
# define WWIDTH 400
# define WHEIGHT 400
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*+++++++++++++++++++++++++++++++++++STRUCTS+++++++++++++++++++++++++++++++++*/
typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_player
{
	int		x;
	int		y;
	// float	new_x;
	// float	new_y;
}	t_player;

typedef struct s_map
{
	char	*n_txtr;//	Path to North wall texture
	char	*s_txtr;//	Path to South wall texture
	char	*e_txtr;//	Path to East wall texture
	char	*w_txtr;//	Path to West wall texture
	int		fcol;//		Floor color
	int		ccol;//		Ceiling color
	char	**grid;
	size_t	map_h;//	Map hight
	size_t	map_l;//	Map width (longest line)
	int		p_dir;//	Players starting facing directionn.
	int		n_players;
}	t_map;

typedef struct s_game
{
	t_window    window;
	t_map		map;
	t_player	player;
}   t_game;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void    load_map(t_game *game, const char *filename);
void	draw_pixels(t_game *game);

/*____________________________________parsing________________________________*/
bool	parse_map_file(char *mapfile, t_map *txtr);
bool	parse_textures(t_map *txtr, char **str, int fd);
bool	set_map_textures(t_map *txtr, char *str);
int		get_color(char *str);
int		rgb_to_int(int r, int g, int b);
bool	check_getcolor_fail(t_map *txtr, char *str);
bool	isprint_iter(char *str);
bool	parse_map(t_map *txtr, char **str, int fd);
bool	isvalid_chr(char *str);
bool	copy_map(t_map *txtr, char *str, int fd);
bool	valid_map(t_map *txtr, char **map);
bool	check_map_struct(t_map *txtr);

/*____________________________________free_mem________________________________*/
void	free_mapstruct(t_map *txtr);

#endif