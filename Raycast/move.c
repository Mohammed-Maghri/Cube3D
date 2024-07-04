/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/04 16:08:23 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		player->move.x = PLAYER_SPEED;
		player->move.y = PLAYER_SPEED;
		player->move.x *= cos(player->angle + player->left_right * (M_PI / 2));
		player->move.y *= sin(player->angle + player->left_right * (M_PI / 2));
		if (player->up_down) //move up or down
		{
			player->move.x *= player->up_down;
			player->move.y *= player->up_down;
		}
		pos.x = roundf(player->pos_in_pixels.x + player->move.x); // get the new x position
		pos.y = roundf(player->pos_in_pixels.y + player->move.y); // get the new y position
		player->move = (t_coordinate){0, 0};
		if (!ft_wall(data->map, pos.x / TSIZE, pos.y / TSIZE)) // check the wall hit and the diagonal wall hit
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
	ft_draw_player(data); // 
	mlx_image_to_window(data->mlx->pointer, data->mlx->image, 0, 0); // put the image to the window
}
