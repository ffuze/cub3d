/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:30:31 by adegl-in          #+#    #+#             */
/*   Updated: 2025/09/05 21:34:18 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// to be switched with dynamic map sizes
# define WWIDTH 400
# define WHEIGHT 400

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_player
{
	float	x;
	float	y;
	// float	new_x;
	// float	new_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	char	**player_pos;
}	t_map;

typedef struct s_game
{
	t_window    window;
	t_map		map;
	t_player	player;
}   t_game;

#endif