#include "./cub3d.h"

float	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

void    get_fps(t_game *game)
{
	float	old_time;
	float	time;
	float	frame_time;
	char	fps_text[50];
	int		fps_value;

	old_time = 0;
	time = get_current_time();
	if (old_time > 0)
	{
		frame_time = (time - old_time) / 1000.0;
		if (frame_time > 0)
		{
			gp.move_speed = frame_time * 5.0;
			gp.rot_speed = frame_time * 3.0;
			fps_value = (int)(1.0 / frame_time);
			printf(fps_text, "FPS: %d", fps_value);
			mlx_string_put(gw.mlx_ptr, gw.win_ptr,
				10, 20, 0xFFFFFF, fps_text);
		}
	}
	old_time = time;
}
