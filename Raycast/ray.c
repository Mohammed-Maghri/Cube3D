/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/28 17:23:50 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_render_all(t_data *data)
{
    double	wall_height;
    int     pixel;

	data->ray->distance *= cos(data->ray->angle - data->player->angle); // fix the fisheye
	wall_height = (TSIZE / data->ray->distance) * DISTANCE_PLAN; // get the wall height
	(wall_height > WINDOW_HEIGHT) && (wall_height = WINDOW_HEIGHT);
    pixel = 0;
    while (pixel < HEIGHT_CENTER - (wall_height / 2))
	{
		ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, CEILING_COLOR); // ceiling
		ft_mlx_put_pixel(data->mlx, data->ray->index, HEIGHT_CENTER + (wall_height / 2) + pixel++, FLOOR_COLOR); // floor
		// ft_mlx_put_pixel(data->mlx, data->ray->index, WINDOW_HEIGHT - pixel++, FLOOR_COLOR); // floor with border
	}
	// pixel += 2; // add border to ceiling
    while (pixel <= HEIGHT_CENTER)
	{
        ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, data->ray->color);//wall
        ft_mlx_put_pixel(data->mlx, data->ray->index, WINDOW_HEIGHT - pixel++, data->ray->color);//wall
	}
}

void    ft_cast_rays(t_data *data)
{
    double    distance;

	data->ray->index = 0;
	data->ray->start = data->player->angle - (FOV / 2);
	data->ray->angle = data->ray->start;
	while (data->ray->angle < data->ray->start + FOV)
	{
		ft_normalize(data);
		data->ray->distance = ft_horizont_intersect(data);
		distance = ft_vertical_intersect(data);
		data->ray->color = WALL_SHADE + (distance <= data->ray->distance) * (WALL_COLOR - WALL_SHADE);
		data->ray->distance += (distance <= data->ray->distance) * (distance - data->ray->distance);
		ft_render_all(data); // render the wall, floor and ceiling
		data->ray->angle = data->ray->start + ++data->ray->index * ANGLE_STEP; // next angle
	}
}
