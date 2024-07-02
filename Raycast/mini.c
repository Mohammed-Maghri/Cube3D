/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/02 16:27:26 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_draw_ray(t_data *data)
{
	t_coordinate ray;
	t_coordinate step;
	int pixel_count;

		ray.x = data->player->pos_in_pixels.x * UNITY;
		ray.y = data->player->pos_in_pixels.y * UNITY;
		step.x = cos(data->ray->angle) * (data->ray->distance) * UNITY;
		step.y = sin(data->ray->angle) * (data->ray->distance) * UNITY;
		pixel_count = data->ray->distance * UNITY;
		step.x /= data->ray->distance * UNITY;
		step.y /= data->ray->distance * UNITY;
		while (pixel_count >=0)
		{
			ft_mlx_put_pixel(data->mlx, ray.x, ray.y, 0xAAAAAAFF);
			ray.x += step.x;
			ray.y += step.y;;
			--pixel_count;
		}
}

void ft_draw_square(t_data *data, int tileSize, int y, int x, int color)
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

void    ft_draw_player(t_data *data)
{
	ft_draw_square(data, MSIZE / 3, \
					data->player->pos_in_pixels.x * UNITY - MSIZE / 6, \
					data->player->pos_in_pixels.y * UNITY - MSIZE / 6, \
					WALL_COLOR);
}
void ft_draw_map(t_data *data)
{
	int y;
	int x;
	int tilex;
	int tiley;

	y = -1;
	while (++y < data->map->map_height)
	{
		x = -1;
		while (++x < data->map->map_width)
		{
			tilex = x * MSIZE;
			tiley = y * MSIZE;
			if (data->map->map[y][x] == '1')
				ft_draw_square(data, MSIZE, tilex , tiley, WALL_COLOR);
			else
				ft_draw_square(data, MSIZE, tilex , tiley, 0xAAAAAABF);
		}
	}
}