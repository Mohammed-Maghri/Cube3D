/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/01 08:25:16 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void  ft_normalize(t_data *data)
{
    data->ray->angle = data->ray->angle + ((data->ray->angle < 0) - (data->ray->angle > (2 * M_PI))) * (2 * M_PI);
    data->ray->down = (data->ray->angle > 0 && data->ray->angle < M_PI);//up = 1 down = 0
	data->ray->left = (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * M_PI / 2);//left = 1 right = 0
    data->ray->up = !data->ray->down;
    data->ray->right = !data->ray->left;
}

void    ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	    mlx_put_pixel(mlx->image, x, y, color);
}

