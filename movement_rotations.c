#include "./cub3d.h"

/*
	MOVIMENTO DEL PLAYER MANCANTE
*/

void    move_front(t_game *game)
{
	if (gm.grid[(int)(gp.pos_x + gp.ray_dir_x * gp.move_speed)]
		[(int)(gp.pos_y)] == false)
	{
		gp.pos_x += gp.ray_dir_x  * gp.move_speed;
	}
	if (gm.grid[(int)gp.pos_x]
		[(int)(gp.pos_y + gp.ray_dir_y * gp.move_speed)] == false)
	{
		gp.pos_y += gp.ray_dir_y * gp.move_speed;
	}
}

void	move_behind(t_game *game)
{
	if (gm.grid[(int)(gp.pos_x + gp.ray_dir_x * gp.move_speed)]
		[(int)(gp.pos_y)] == false)
	{
		gp.pos_x -= gp.ray_dir_x  * gp.move_speed;
	}
	if (gm.grid[(int)gp.pos_x]
		[(int)(gp.pos_y + gp.ray_dir_y * gp.move_speed)] == false)
	{
		gp.pos_y -= gp.ray_dir_y * gp.move_speed;
	}
}

void	move_right(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;
	
	old_dir_x = gp.ray_dir_x;
	old_plane_x = gm.plane_x;
	gp.ray_dir_x = gp.ray_dir_x * cos(-gp.rot_speed) - gp.ray_dir_y * sin(-gp.rot_speed);
	gp.ray_dir_y = old_dir_x * sin(-gp.rot_speed) + gp.ray_dir_y * cos(-gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(-gp.rot_speed) - gm.plane_y * sin(-gp.rot_speed);
	gm.plane_y = old_plane_x * sin(-gp.rot_speed) + gm.plane_y * cos(-gp.rot_speed);
}

void	move_left(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;
	
	old_dir_x = gp.ray_dir_x;
	old_plane_x = gm.plane_x;
	gp.ray_dir_x = gp.ray_dir_x * cos(gp.rot_speed) - gp.ray_dir_y * sin(gp.rot_speed);
	gp.ray_dir_y = old_dir_x * sin(gp.rot_speed) + gp.ray_dir_y * cos(gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(gp.rot_speed) - gm.plane_y * sin(gp.rot_speed);
	gm.plane_y = old_plane_x * sin(gp.rot_speed) + gm.plane_y * cos(gp.rot_speed);
}