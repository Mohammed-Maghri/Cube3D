/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/12 09:56:58 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	    mlx_put_pixel(mlx->image, x, y, color);
}

void    ft_draw_ray(t_data *data)
{
	t_coordinate start;
	t_coordinate step;
	t_coordinate diff;
	int pixel_count;
	
	start.x = data->player->pos_in_pixels.x * UNITY;
	start.y = data->player->pos_in_pixels.y * UNITY;
	diff.x = MINI_WIDTH / 2 - floor(start.x);
	diff.y = MINI_HEIGHT / 2 - floor(start.y);
	start.x += diff.x;
	start.y += diff.y;
	step.x = cos(data->ray->angle);
	step.y = sin(data->ray->angle);
	pixel_count = data->ray->distance * UNITY + 1;
	while (--pixel_count >= 0)
	{
		if (start.x + step.x * pixel_count < MINI_WIDTH && start.y + step.y * pixel_count < MINI_HEIGHT)
			ft_mlx_put_pixel(data->mlx, start.x + step.x * pixel_count, \
										start.y + step.y * pixel_count, \
										0xAAAAAAEE);
	}
}

void ft_draw_square(t_data *data, int tileSize, int color, int y, int x)
{
	int i;
	int j;

	i = -1;
	while (++i < tileSize)
	{
		j = -1;
		while (++j < tileSize)
				ft_mlx_put_pixel(data->mlx, (j + y), (i + x), color);
	}
}

void    ft_draw_miniplayer(t_data *data) // fixed player
{
	ft_draw_square(data, MSIZE / 3, MINI_COLOR, \
					MINI_WIDTH / 2 - MSIZE / 6, \
					MINI_HEIGHT / 2 - MSIZE / 6);
}

void ft_draw_minimap(t_data *data)// moving map
{
	int i;
	int j;
	t_coordinate diff;
	
	diff.x = MINI_WIDTH / 2 - floor(data->player->pos_in_pixels.x * UNITY);
	diff.y = MINI_HEIGHT / 2 - floor(data->player->pos_in_pixels.y * UNITY);
	i = -1;
	while (++i < data->map->map_height)
	{
		j = -1;
		while (++j < data->map->map_width)
		{
			if (data->map->map[i][j] == '1')
				ft_draw_square(data, MSIZE, MINI_COLOR, j * MSIZE + diff.x, i * MSIZE + diff.y);
			// else
			// 	ft_draw_square(data, MSIZE, MINI_COLOR, (j + diff.x) * MSIZE , (i + diff.y) * MSIZE);
		}
	}
}
