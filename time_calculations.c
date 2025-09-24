#include "./cub3d.h"

float	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

void    get_fps(t_game *game)
{
	float  old_time;
	float  time;
	float  frame_time;

	time = 0.0;
	old_time = time;
	time = get_current_time();
	frame_time = (time - old_time) / 1000.0;
	if (frame_time > 0)
		printf("FPS: %.1f\n", 1.0 / frame_time);
	game->plr.move_speed = frame_time * 5.0;
	game->plr.rot_speed = frame_time * 3.0;
}
