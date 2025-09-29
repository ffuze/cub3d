#include "./cub3d.h"

void    get_wall_height(t_game *game)
{
	game->map.wall_height = WINHEIGHT / game->plr.perp_wall_dist;
	game->map.draw_start = (-game->map.wall_height / 2) + (WINHEIGHT / 2);
	if (game->map.draw_start < 0)
		game->map.draw_start = 0;
	game->map.draw_end = (game->map.wall_height / 2) + (WINHEIGHT / 2);
	if (game->map.draw_end >= WINHEIGHT)
		game->map.draw_end = WINHEIGHT - 1;
}

void draw_ver_line(t_game *game, int x)
{
    int		y;
    char	*dest;

    get_wall_height(game);
    if (game->map.grid[game->map.map_x][game->map.map_y])
    {
        if (game->map.grid[game->map.map_x][game->map.map_y] == '1')
            game->map.hex_color = 0x32CD32;
        else if (game->map.grid[game->map.map_x][game->map.map_y] == '0')
            game->map.hex_color = 0x000000;
        else
            game->map.hex_color = 0x32CD32;
    }
    if (game->map.side == 1)
        game->map.hex_color = game->map.hex_color / 2;
    y = -1;
    while (++y < game->map.draw_start)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = game->win.addr + (y * game->win.line_length + x * (game->win.bits_per_pixel / 8));
            *(unsigned int*)dest = 0xD3D3D3;
        }
    }
    y = game->map.draw_start - 1;
    while (++y <= game->map.draw_end)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = game->win.addr + (y * game->win.line_length + x * (game->win.bits_per_pixel / 8));
            *(unsigned int*)dest = game->map.hex_color;
        }
    }
    y = game->map.draw_end;
    while (++y < WINHEIGHT)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = game->win.addr + (y * game->win.line_length + x * (game->win.bits_per_pixel / 8));
            *(unsigned int*)dest = 0x222222;
        }
    }
}
