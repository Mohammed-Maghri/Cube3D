/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:15:39 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/02 10:55:44 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_key_press(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_ESCAPE) // exit the game
		ft_close(data);
	else if (keydata.key == MLX_KEY_W) // move up
		data->player->up_down_flag = 1;
	else if (keydata.key == MLX_KEY_S) // move down
		data->player->up_down_flag = -1;
	else if (keydata.key == MLX_KEY_D) // move right
		data->player->left_right_flag = 1;
	else if (keydata.key == MLX_KEY_A) // move left
		data->player->left_right_flag = -1;
	else if (keydata.key == MLX_KEY_RIGHT) // rotate right
		data->player->rotation_flag = 1;
	else if (keydata.key == MLX_KEY_LEFT) // rotate left
		data->player->rotation_flag = -1;
}

void    ft_key_release(mlx_key_data_t keydata, t_data *data)
{
    if (keydata.key == MLX_KEY_D)
		data->player->left_right_flag = 0;
	else if (keydata.key == MLX_KEY_A)
		data->player->left_right_flag = 0;
	else if (keydata.key == MLX_KEY_S)
		data->player->up_down_flag = 0;
	else if (keydata.key == MLX_KEY_W)
		data->player->up_down_flag = 0;
	else if (keydata.key == MLX_KEY_LEFT)
		data->player->rotation_flag = 0;
	else if (keydata.key == MLX_KEY_RIGHT)
		data->player->rotation_flag = 0;
}

void    ft_key_move(mlx_key_data_t keydata, void *d)
{
    	t_data	*data;

	data = d;
	if (keydata.action == MLX_PRESS)
    	ft_key_press(keydata, data);
	if (keydata.action == MLX_RELEASE)
	    ft_key_release(keydata, data);
}
