/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/02 17:24:48 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_rotate_player(t_player *player)
{
	player->angle += player->rotation_flag * ROTATION_SPEED; // +ROTATION_SPEED or -ROTATION_SPEED
	player->angle += (player->angle < 0) * (2 * M_PI); // normalize
	player->angle += -(player->angle > (2 * M_PI)) * (2 * M_PI); // normalize
	if (player->left_right_flag) //move right or left
	{
		player->rotate.x = -1 * player->left_right_flag * sin(player->angle) * PLAYER_SPEED;
		player->rotate.y = player->left_right_flag * cos(player->angle) * PLAYER_SPEED;
	}
	if (player->up_down_flag) //move up or down
	{
		player->rotate.x = player->up_down_flag * cos(player->angle) * PLAYER_SPEED;
		player->rotate.y = player->up_down_flag * sin(player->angle) * PLAYER_SPEED;
	}
}

void	ft_move_player(t_data *data)
{
	t_position	index;
	t_position	pos;

	pos.x = roundf(data->player->pos_in_pixels.x + data->player->rotate.x); // get the new x position
	pos.y = roundf(data->player->pos_in_pixels.y + data->player->rotate.y); // get the new y position
	data->player->rotate = (t_coordinate){0, 0};
	index.x = (pos.x / TSIZE); // get the x position in the map
	index.y = (pos.y / TSIZE); // get the y position in the map
	if (data->map->map[index.y][index.x] != '1' && \
	(data->map->map[index.y][data->player->pos_in_pixels.x / TSIZE] != '1' && \
	data->map->map[data->player->pos_in_pixels.y / TSIZE][index.x] != '1')) // check the wall hit and the diagonal wall hit
	{
		data->player->pos_in_pixels.x = pos.x; // move the player
		data->player->pos_in_pixels.y = pos.y; // move the player
	}
}

void    ft_update_window(void *d)
{
	t_data			*data;

	data = d;
	mlx_delete_image(data->mlx->pointer, data->mlx->image);	// delete the image
	data->mlx->image = mlx_new_image(data->mlx->pointer, WINDOW_WIDTH, WINDOW_HEIGHT);	// create new image
	ft_rotate_player(data->player);
	ft_move_player(data);
	ft_draw_map(data); // 
	ft_cast_rays(data);	// cast the rays
	ft_draw_player(data); // 
	mlx_image_to_window(data->mlx->pointer, data->mlx->image, 0, 0); // put the image to the window
}