#include "./cub3d.h"

// x == pos_x --> new_x, y == pos_y --> new_y
static int	check_collision(t_game *game, float x, float y)
{
	float	margin;
	int		delta_x;
	int		delta_y;
	int		check_x;
	int		check_y;

	margin = 0.2;
	if (x - margin < 0 || x + margin >= GM.map_h)
		return (1);
	if (y - margin < 0 || y + margin >= GM.map_l)
		return (1);
	if (!GM.grid[(int)x] || !GM.grid[(int)x][(int)y])
		return (1);
	delta_x = -1;
	while (delta_x <= 1)
	{
		delta_y = -1;
		while (delta_y <= 1)
		{
			check_x = (int)(x + delta_x * margin);
			check_y = (int)(y + delta_y * margin);
			if (check_x >= 0 && check_x < (int)GM.map_h &&
				check_y >= 0 && check_y < (int)GM.map_l)
			{
				if (GM.grid[check_x][check_y] == '1')
					return (1);
			}
			delta_y++;
		}
		delta_x++;
	}
	return (0);
}

void    move_front(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x + (GP.ray_x * GP.move_speed);
	new_y = GP.pos_y + (GP.ray_y * GP.move_speed);
	if (!check_collision(game, new_x, GP.pos_y))
		GP.pos_x = new_x;
	if (!check_collision(game, GP.pos_x, new_y))
		GP.pos_y = new_y;
	printf("Move front: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	move_behind(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x - (GP.ray_x * GP.move_speed);
	new_y = GP.pos_y - (GP.ray_y * GP.move_speed);
	if (!check_collision(game, new_x, GP.pos_y))
		GP.pos_x = new_x;
	if (!check_collision(game, GP.pos_x, new_y))
		GP.pos_y = new_y;
	printf("Move behind: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	strafe_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x + (GP.ray_y * GP.move_speed);
	new_y = GP.pos_y - (GP.ray_x * GP.move_speed);
	if (!check_collision(game, new_x, GP.pos_y))
		GP.pos_x = new_x;
	if (!check_collision(game, GP.pos_x, new_y))
		GP.pos_y = new_y;
	printf("Strafe right: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	strafe_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x - (GP.ray_y * GP.move_speed);
	new_y = GP.pos_y + (GP.ray_x * GP.move_speed);
	if (!check_collision(game, new_x, GP.pos_y))
		GP.pos_x = new_x;
	if (!check_collision(game, GP.pos_x, new_y))
		GP.pos_y = new_y;
	printf("Strafe left: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	rotate_right(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = GP.ray_x;
	old_plane_x = GM.plane_x;
	GP.ray_x = GP.ray_x * cos(-GP.rot_speed) - GP.ray_y * sin(-GP.rot_speed);
	GP.ray_y = old_ray_x * sin(-GP.rot_speed) + GP.ray_y * cos(-GP.rot_speed);
	GM.plane_x = GM.plane_x * cos(-GP.rot_speed) - GM.plane_y * sin(-GP.rot_speed);
	GM.plane_y = old_plane_x * sin(-GP.rot_speed) + GM.plane_y * cos(-GP.rot_speed);
	printf("Rotate left: ray(%.2f, %.2f)\n", GP.ray_x, GP.ray_y);
}

void	rotate_left(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = GP.ray_x;
	old_plane_x = GM.plane_x;
	GP.ray_x = GP.ray_x * cos(GP.rot_speed) - GP.ray_y * sin(GP.rot_speed);
	GP.ray_y = old_ray_x * sin(GP.rot_speed) + GP.ray_y * cos(GP.rot_speed);
	GM.plane_x = GM.plane_x * cos(GP.rot_speed) - GM.plane_y * sin(GP.rot_speed);
	GM.plane_y = old_plane_x * sin(GP.rot_speed) + GM.plane_y * cos(GP.rot_speed);
	printf("Rotate right: ray(%.2f, %.2f)\n", GP.ray_x, GP.ray_y);
}
