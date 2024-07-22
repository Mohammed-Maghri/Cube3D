/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 15:21:32 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
	(key == 'R') && (data->check_reload = 1);
	(key == 'W') && (data->player->up_down = action);
	(key == 'S') && (data->player->up_down = -action);
	(key == 'D') && (data->player->left_right = action);
	(key == 'A') && (data->player->left_right = -action);
	(key == LEFT) && (data->player->rotation = -action);
	(key == RIGHT) && (data->player->rotation = action);
	(key == 'N') && (data->hide_mouse = 1);
	(key == 'M') && (data->hide_mouse = 0)
				&& (data->player->rotation = 0);
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

void	ft_check_reload(t_data *data)
{
	if (data->var_check == 0)
	{
		ft_background_sound("afplay ./Bonus/rel.mp3");
		data->var_check = 1;
	}
	if (data->check_reload == -1)
		ft_draw_image(data, data->bonus, 500, 586);
	else
	{
		ft_draw_image(data, \
			data->reload[data->check_reload / 5], 500, 585);
		data->check_reload++;
	}
		// if (data->check_reload >= 1 && data->check_reload < 5)
	// 	draw_image_on_image(data, data->reload[0], 500, 585);
	// else if (data->check_reload >= 5 && data->check_reload < 10)
	// 	draw_image_on_image(data, data->reload[1], 500, 585);
	// else if (data->check_reload >= 10 && data->check_reload < 15)
	// 	draw_image_on_image(data, data->reload[2], 500, 585);
	// else if (data->check_reload >= 15 && data->check_reload < 20)
	// 	draw_image_on_image(data, data->reload[3], 500, 585);
	// else if (data->check_reload >= 20 && data->check_reload < 25)
	// 	draw_image_on_image(data, data->reload[4], 500, 585);
	// else if(data->check_reload >= 25 && data->check_reload < 30)
	// 	draw_image_on_image(data, data->reload[5], 500, 585);
	// else if (data->check_reload >= 30 && data->check_reload < 35)
	// 	draw_image_on_image(data, data->reload[6], 500, 585);
	// else if (data->check_reload >= 35 && data->check_reload < 40)
	// 	draw_image_on_image(data, data->reload[7], 500, 585);
	// else if (data->check_reload >= 40 && data->check_reload < 45)
	// 	draw_image_on_image(data, data->reload[8], 500, 585);
	// else if (data->check_reload >= 45 && data->check_reload < 50)
	// 	draw_image_on_image(data, data->reload[9], 500, 585);
	// if (data->check_reload >= 1)
	// 	data->check_reload++;
	if (data->check_reload == 50)
	{
		data->var_check = 0;
		data->check_reload = -1;
	}
}

void	ft_update_window(void *d)
{
	t_data	*data;
	t_mlx	*mlx;

	data = d;
	mlx = data->mlx;
	mlx_delete_image(mlx->pointer, mlx->image);
	mlx->image = mlx_new_image(mlx->pointer, data->win_width, data->win_height);
	ft_background_sound("afplay ./Bonus/te.mp3");
	ft_move_player(data);
	ft_draw_minimap(data);
	ft_cast_rays(data);
	ft_draw_miniplayer(data);
	ft_check_reload(data);
	mlx_image_to_window(mlx->pointer, mlx->image, 0, 0);
}
