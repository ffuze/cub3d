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
# include <sys/time.h>
# include <readline/readline.h>
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

/*~~~~~~~~~~~~~~~~MORE~~~~~~~~~~~~~~~~*/
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
# define WINWIDTH 1820
# define WINHEIGHT 920

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*+++++++++++++++++++++++++++++++++++STRUCTS+++++++++++++++++++++++++++++++++*/

typedef enum s_dir
{
	MISSING,
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

// Struct forpassing variables to my_pixelput()
//  (F*ck you norminette)
//	agreed, I hope you step on a huge pile of shit
typedef struct s_pix
{
	float	x;
	float	y;
	int		color;
	int		py;
	int		px;
}	t_pix;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*nimg;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_win;

typedef struct s_player
{
	int		p_dir;//	Players starting facing direction.
	float	pos_x;//	Current player position(line)
	float	pos_y;// 	Current player position (column)
	float	ray_x;
	float	ray_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_x;
	float	delta_y;
	float	dist_x;
	float	dist_y;
	float	perp_wall_dist;
	float	move_speed;
	float	default_move_speed;
	float	rot_speed;
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
	int		n_players;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	float	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		wall_height;
	int		x;
	int		draw_start;
	int		draw_end;
	int		draw_start_real;
	int		draw_end_real;
	int		hex_color;
	int		tex_num;
	int		tex_x;
	int		tex_y;
}	t_map;

typedef struct s_minimap
{
	int		pos_x;
	int		pos_y;
	float	ray_x;
	float	ray_y;
	float	move_speed;
	float	rot_speed;
	bool	sync_with_player;
}	t_minimap;

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	int		tex_x;
}	t_texture;

typedef struct s_game
{
	t_win		win;
	t_map		map;
	t_player	plr;
	t_minimap	minimap;
	t_texture	*txtrs;
	int			texture_count;
	int			scale;
	bool		*keys;
	float		old_time;
}	t_game;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void	execute_algorithm(t_game *game);

/*____________________________________hooks.c________________________________*/
void	ft_hooks(t_game	*game);
int		on_destroy(t_game *game);

/*____________________________________parsing________________________________*/
bool	parse_map_file(char *mapfile, t_map *map, t_player *plr);
bool	parse_textures(t_map *map, char **str, int fd);
bool	set_map_textures(t_map *map, char *str);
int		get_color(char *str);
int		rgb_to_int(int r, int g, int b);
bool	check_getcolor_fail(t_map *map, char *str);
bool	isprint_iter(char *str);
bool	parse_map(t_map *map, char **str, int fd);
bool	isvalid_chr(char *str);
bool	copy_map(t_map *map, char *str, int fd);
bool	valid_map(t_map *map, char **grid);
bool	check_map_struct(t_map *map);

/*___________________________________minimap.c_______________________________*/
void	render_minimap(t_game *game);
void	ft_padding(t_game *game, int color, float x, float y);

/*_______________________________move_on_minimap.c___________________________*/
void	rotate_right_minimap(t_game *game);
void	rotate_left_minimap(t_game *game);

/*___________________________________free_mem________________________________*/
void	free_mapstruct(t_map *map);
void	free_textures(t_game *game, t_texture *textures, int count);
void	free_mlx(t_game *game);

/*___________________________________time_calc_______________________________*/
float	get_current_time(void);
void	get_fps(t_game *game);

/*_________________________________wall_calc_________________________________*/
void	get_wall_height(t_game *game);
void	draw_ver_line(t_game *game, int x);

/*_________________________________ray_calc__________________________________*/
void	get_next_position(t_game *game);
void	calculate_nearest_coords(t_game *game);
void	get_ray_derivates(t_game *game);

/*___________________________________init____________________________________*/
void	initialize_all(t_game *game);
void	initialize_minimap(t_game *game);
void	initialize_player(t_game *game);
void	check_plr_dir(t_game *game);

/*_________________________________movement__________________________________*/
void	move_front(t_game *game);
void	move_behind(t_game *game);
void	strafe_right(t_game *game);
void	strafe_left(t_game *game);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);
int		check_collision(t_game *game, float x, float y);

/*_________________________________textures__________________________________*/
bool	load_all_textures(t_game *game);
void	get_texture_coords(t_game *game);

#endif