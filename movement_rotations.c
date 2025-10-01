#include "./cub3d.h"

/*
	MOVIMENTO DEL PLAYER MANCANTE
*/

void    move_front(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x + (gp.ray_x * gp.move_speed);
	new_y = gp.pos_y + (gp.ray_y * gp.move_speed);
	if (!(new_x >= 0 && new_x < gm.map_h && 
		(int)gp.pos_y >= 0 && (int)gp.pos_y < (int)gm.map_l &&
		gm.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < gm.map_l &&
		(int)gp.pos_x >= 0 && (int)gp.pos_x < (int)gm.map_h &&
		gm.grid[(int)gp.pos_x]))
	{
		return ;
	}
	if (gm.grid[(int)new_x][(int)gp.pos_y] != '1')
		gp.pos_x = new_x;
	if (gm.grid[(int)gp.pos_x][(int)new_y] != '1')
		gp.pos_y = new_y;
	printf("Move front: pos(%.2f, %.2f)\n", gp.pos_x, gp.pos_y);
}

void	move_behind(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x - (gp.ray_x * gp.move_speed);
	new_y = gp.pos_y - (gp.ray_y * gp.move_speed);
	if (!(new_x >= 0 && new_x < gm.map_h && 
		(int)gp.pos_y >= 0 && (int)gp.pos_y < (int)gm.map_l &&
		gm.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < gm.map_l &&
		(int)gp.pos_x >= 0 && (int)gp.pos_x < (int)gm.map_h &&
		gm.grid[(int)gp.pos_x]))
	{
		return ;
	}
	if (gm.grid[(int)new_x][(int)gp.pos_y] != '1')
		gp.pos_x = new_x;
	if (gm.grid[(int)gp.pos_x][(int)new_y] != '1')
		gp.pos_y = new_y;
	printf("Move behind: pos(%.2f, %.2f)\n", gp.pos_x, gp.pos_y);
}

void	strafe_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x - (gp.ray_y * gp.move_speed);
	new_y = gp.pos_y + (gp.ray_x * gp.move_speed);
	if (!(new_x >= 0 && new_x < gm.map_h && 
		(int)gp.pos_y >= 0 && (int)gp.pos_y < (int)gm.map_l &&
		gm.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < gm.map_l &&
		(int)gp.pos_x >= 0 && (int)gp.pos_x < (int)gm.map_h &&
		gm.grid[(int)gp.pos_x]))
	{
		return ;
	}
	if (gm.grid[(int)new_x][(int)gp.pos_y] != '1')
		gp.pos_x = new_x;
	if (gm.grid[(int)gp.pos_x][(int)new_y] != '1')
		gp.pos_y = new_y;
	printf("Strafe right: pos(%.2f, %.2f)\n", gp.pos_x, gp.pos_y);
}

void	strafe_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = gp.pos_x + (gp.ray_y * gp.move_speed);
	new_y = gp.pos_y - (gp.ray_x * gp.move_speed);
	if (!(new_x >= 0 && new_x < gm.map_h && 
		(int)gp.pos_y >= 0 && (int)gp.pos_y < (int)gm.map_l &&
		gm.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < gm.map_l &&
		(int)gp.pos_x >= 0 && (int)gp.pos_x < (int)gm.map_h &&
		gm.grid[(int)gp.pos_x]))
	{
		return ;
	}
	if (gm.grid[(int)new_x][(int)gp.pos_y] != '1')
		gp.pos_x = new_x;
	if (gm.grid[(int)gp.pos_x][(int)new_y] != '1')
		gp.pos_y = new_y;
	printf("Strafe left: pos(%.2f, %.2f)\n", gp.pos_x, gp.pos_y);
}

void	rotate_right(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = gp.ray_x;
	old_plane_x = gm.plane_x;
	gp.ray_x = gp.ray_x * cos(gp.rot_speed) - gp.ray_y * sin(gp.rot_speed);
	gp.ray_y = old_ray_x * sin(gp.rot_speed) + gp.ray_y * cos(gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(gp.rot_speed) - gm.plane_y * sin(gp.rot_speed);
	gm.plane_y = old_plane_x * sin(gp.rot_speed) + gm.plane_y * cos(gp.rot_speed);
	printf("Rotate left: ray(%.2f, %.2f)\n", gp.ray_x, gp.ray_y);
}

void	rotate_left(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = gp.ray_x;
	old_plane_x = gm.plane_x;
	gp.ray_x = gp.ray_x * cos(-gp.rot_speed) - gp.ray_y * sin(-gp.rot_speed);
	gp.ray_y = old_ray_x * sin(-gp.rot_speed) + gp.ray_y * cos(-gp.rot_speed);
	gm.plane_x = gm.plane_x * cos(-gp.rot_speed) - gm.plane_y * sin(-gp.rot_speed);
	gm.plane_y = old_plane_x * sin(-gp.rot_speed) + gm.plane_y * cos(-gp.rot_speed);
	printf("Rotate right: ray(%.3f, %.3f)\n", gp.ray_x, gp.ray_y);
}
