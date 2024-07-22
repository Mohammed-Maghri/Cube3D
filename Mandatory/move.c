/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 10:18:41 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_key_move(mlx_key_data_t keydata, void *d)
{
	t_data	*data;
	int		key;
	int		action;

	data = d;
	key = keydata.key;
	action = keydata.action;
	if (key == ESC)
		ft_close(data);
	(action == 2) && (action = 1);
	(key == 'W') && (data->player->up_down = action);
	(key == 'S') && (data->player->up_down = -action);
	(key == 'D') && (data->player->left_right = action);
	(key == 'A') && (data->player->left_right = -action);
	(key == LEFT) && (data->player->rotation = -action);
	(key == RIGHT) && (data->player->rotation = action);
}

void	ft_move_player(t_data *data)
{
	t_player	*player;
	t_position	pos;

	player = data->player;
	player->angle += player->rotation * ROTATION_SPEED;
	if (player->up_down || player->left_right)
	{
		player->move.x = PLAYER_SPEED * cos(player->angle + player->left_right \
							* (M_PI / 2) + (player->up_down < 0) * M_PI);
		player->move.y = PLAYER_SPEED * sin(player->angle + player->left_right \
							* (M_PI / 2) + (player->up_down < 0) * M_PI);
		pos.x = roundf(player->pos_in_pixels.x + player->move.x);
		pos.y = roundf(player->pos_in_pixels.y + player->move.y);
		player->move = (t_coordinate){0, 0};
		if (!ft_near_wall(data->map, pos.x, pos.y) \
			&& !ft_near_wall(data->map, player->pos_in_pixels.x, pos.y) \
			&& !ft_near_wall(data->map, pos.x, player->pos_in_pixels.y))
		{
			player->pos_in_pixels.x = pos.x;
			player->pos_in_pixels.y = pos.y;
		}
	}
}

void	ft_update_window(void *d)
{
	t_data	*data;
	t_mlx	*mlx;

	data = d;
	mlx = data->mlx;
	mlx_delete_image(mlx->pointer, mlx->image);
	mlx->image = mlx_new_image(mlx->pointer, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_move_player(data);
	ft_draw_minimap(data);
	ft_cast_rays(data);
	ft_draw_miniplayer(data);
	mlx_image_to_window(mlx->pointer, mlx->image, 0, 0);
}
