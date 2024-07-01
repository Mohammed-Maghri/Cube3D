/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/01 18:06:07 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_player(t_player *player)
{
	if (player->rotation_flag == 1) //rotate right
	{
		player->angle += ROTATION_SPEED; // rotate right
		if (player->angle > 2 * M_PI)
			player->angle -= 2 * M_PI;
	}	
	if (player->rotation_flag == -1) //rotate left
	{
		player->angle -= ROTATION_SPEED; // rotate left
		if (player->angle < 0)
			player->angle += 2 * M_PI;
	}
}

void    ft_update_position(t_player *player, t_coordinate *move)
{
	if (player->left_right_flag == 1) //move right
	{
		move->x = -sin(player->angle) * PLAYER_SPEED;
		move->y = cos(player->angle) * PLAYER_SPEED;
	}
	if (player->left_right_flag == -1) //move left
	{
		move->x = sin(player->angle) * PLAYER_SPEED;
		move->y = -cos(player->angle) * PLAYER_SPEED;
	}
	if (player->up_down_flag == 1) //move up
	{
		move->x = cos(player->angle) * PLAYER_SPEED;
		move->y = sin(player->angle) * PLAYER_SPEED;
	}
	if (player->up_down_flag == -1) //move down
	{
		move->x = -cos(player->angle) * PLAYER_SPEED;
		move->y = -sin(player->angle) * PLAYER_SPEED;
	}
}

void	ft_move_player(t_data *data, t_coordinate move)
{
	t_position	index;
	t_position	pos;

	pos.x = roundf(data->player->pos_in_pixels.x + move.x); // get the new x position
	pos.y = roundf(data->player->pos_in_pixels.y + move.y); // get the new y position
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
	t_coordinate	move;

	data = d;
	mlx_delete_image(data->mlx->pointer, data->mlx->image);	// delete the image
	data->mlx->image = mlx_new_image(data->mlx->pointer, WINDOW_WIDTH, WINDOW_HEIGHT);	// create new image
	ft_rotate_player(data->player);
	ft_update_position(data->player, &move);
	ft_move_player(data, move);
	ft_draw_map(data); // 
	ft_cast_rays(data);	// cast the rays
	ft_draw_player(data); // 
	mlx_image_to_window(data->mlx->pointer, data->mlx->image, 0, 0); // put the image to the window
}