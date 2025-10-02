#include "./cub3d.h"

void    get_wall_height(t_game *game)
{
	if (game->plr.perp_wall_dist < 0.001)
		game->plr.perp_wall_dist = 0.001;
	gm.wall_height = WINHEIGHT / game->plr.perp_wall_dist;
	gm.draw_start = (-gm.wall_height / 2) + (WINHEIGHT / 2);
	if (gm.draw_start < 0)
		gm.draw_start = 0;
	gm.draw_end = (gm.wall_height / 2) + (WINHEIGHT / 2);
	if (gm.draw_end >= WINHEIGHT)
		gm.draw_end = WINHEIGHT - 1;
}

void    draw_ver_line(t_game *game, int x)
{
    int		y;
    char	*dest;

    get_wall_height(game);
    if (gm.grid[gm.map_y] && gm.grid[gm.map_y][gm.map_x])
    {
        if (gm.grid[gm.map_y][gm.map_x] == '1')
            gm.hex_color = 0x32CD32;
        else if (gm.grid[gm.map_y][gm.map_x] == '0')
            gm.hex_color = 0xFF0000;
        else
            gm.hex_color = 0x32CD32;
    }
    else
        gm.hex_color = 0x000000;
    if (gm.side == 1)
        gm.hex_color = gm.hex_color / 2;
    y = -1;
    while (++y < gm.draw_start)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = gw.addr + (y * gw.line_len + x * (gw.bits_per_pixel / 8));
            *(unsigned int*)dest = 0xD3D3D3;
        }
    }
    y = gm.draw_start - 1;
    while (++y <= gm.draw_end)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = gw.addr + (y * gw.line_len + x * (gw.bits_per_pixel / 8));
            *(unsigned int*)dest = gm.hex_color;
        }
    }
    y = gm.draw_end;
    while (++y < WINHEIGHT)
    {
        if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
        {
            dest = gw.addr + (y * gw.line_len + x * (gw.bits_per_pixel / 8));
            *(unsigned int*)dest = 0x222222;
        }
    }
}
