/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:15:39 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 09:28:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_key_press(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
		ft_close(data);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS)) // move left
		data->player->left_right_flag = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS)) // move right
		data->player->left_right_flag = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS)) // move down
		data->player->up_down_flag = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) // move up
		data->player->up_down_flag = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) // rotate left
		data->player->rotation_flag = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) // rotate right
		data->player->rotation_flag = 1;
}

void    ft_key_release(mlx_key_data_t keydata, t_data *data)
{
    	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		data->player->left_right_flag = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		data->player->left_right_flag = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		data->player->up_down_flag = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		data->player->up_down_flag = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		data->player->rotation_flag = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		data->player->rotation_flag = 0;
}

void    ft_key_move(mlx_key_data_t keydata, void *d)
{
    	t_data	*data;

	data = d;
    ft_key_press(keydata, data);
    ft_key_release(keydata, data);
}
