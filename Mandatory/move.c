/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/07 10:24:39 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_wall(t_map *map, int x, int y)
{
	return ((x < 0 || y < 0 || y >= map->map_height || x >= map->map_width || (map->map[y][x] == '1')));
}

// double  ft_distance(t_coordinate a, t_position b)
// {
//     // return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
//     return (hypot(a.x - b.x, a.y - b.y));
// }

void    ft_key_move(mlx_key_data_t keydata, void *d)
{
    t_data	*data;
	int	key;
	int action;

	data = d;
	key = keydata.key;
	action = keydata.action; // 1 for key_press // 0 for key_release // 2 for key_repeat 
	if (key == ESC)
		ft_close(data);
	(action == 2) && (action = 1);
	(key == R) && (data->player->rotation = action); // right
	(key == L) && (data->player->rotation = -action); // left
	(key == 'W') && (data->player->up_down = action);
	(key == 'S') && (data->player->up_down = -action);
	(key == 'D') && (data->player->left_right = action);
	(key == 'A') && (data->player->left_right = -action);
}

void	ft_move_player(t_data *data)
{
	t_player *player;
	t_position	pos;

	player = data->player;
	player->angle += player->rotation * ROTATION_SPEED; // +ROTATION_SPEED or -ROTATION_SPEED
	if (player->up_down || player->left_right) //move
	{
		player->move.x = PLAYER_SPEED * cos(player->angle + player->left_right * (M_PI / 2) + (player->up_down < 0) * M_PI);
		player->move.y = PLAYER_SPEED * sin(player->angle + player->left_right * (M_PI / 2) + (player->up_down < 0) * M_PI);
		pos.x = rint(player->pos_in_pixels.x + player->move.x); // get the new x position
		pos.y = rint(player->pos_in_pixels.y + player->move.y); // get the new y position
		player->move = (t_coordinate){0, 0};
		if (!ft_wall(data->map, pos.x / TSIZE, pos.y / TSIZE) \
			&& data->map->map[pos.y / TSIZE][data->player->pos_in_pixels.x / TSIZE] != '1' \
			&& data->map->map[data->player->pos_in_pixels.y / TSIZE][pos.x / TSIZE] != '1')
		{
			player->pos_in_pixels.x = pos.x; // move the player
			player->pos_in_pixels.y = pos.y; // move the player
		}
			
	}
}


void    ft_update_window(void *d)
{
	t_data			*data;

	data = d;
	mlx_delete_image(data->mlx->pointer, data->mlx->image);	// delete the image
	data->mlx->image = mlx_new_image(data->mlx->pointer, WINDOW_WIDTH, WINDOW_HEIGHT);	// create new image
	ft_move_player(data);
	ft_draw_minimap(data); // 
	ft_cast_rays(data);	// cast the rays
	ft_draw_miniplayer(data); // 
	mlx_image_to_window(data->mlx->pointer, data->mlx->image, 0, 0); // put the image to the window
}
