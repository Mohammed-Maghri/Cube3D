/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/04 18:00:28 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_draw_all(t_data *data)
{
    double	wall_height;
    int     pixel;

	wall_height = DISTANCE_PLAN / data->ray->distance; // get the wall height
	(wall_height > WINDOW_HEIGHT) && (wall_height = WINDOW_HEIGHT);
    pixel = 0;
    while (pixel < HALF_HEIGHT - (wall_height / 2))
	{
		// if (data->ray->index > data->map->map_width * MSIZE)// depand on map size
		if (data->ray->index >= MINI_WIDTH)// fixed
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, CEILING_COLOR); // ceiling
		// if (pixel > data->map->map_height * MSIZE)// depand on map size
		if (pixel >= MINI_HEIGHT)// fixed
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, CEILING_COLOR); // ceiling
		ft_mlx_put_pixel(data->mlx, data->ray->index, HALF_HEIGHT + (wall_height / 2) + pixel++, FLOOR_COLOR); // floor
	}
    while (pixel <= HALF_HEIGHT)
	{
		// if (data->ray->index > data->map->map_width * MSIZE)// depand on map size
		if (data->ray->index >= MINI_WIDTH)// fixed
        	ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, data->ray->color);//wall
		// if (pixel > data->map->map_height * MSIZE)// depand on map size
		if (pixel >= MINI_HEIGHT)// fixed
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
		distance = ft_hdistance(data);
		data->ray->distance = ft_vdistance(data);
		data->ray->color = WALL_COLOR;//
		(distance <= data->ray->distance) && (data->ray->color = WALL_SHADE);//
		(distance <= data->ray->distance) && (data->ray->distance = distance);//
		ft_draw_ray(data); // mini map
		data->ray->distance *= cos(data->ray->angle - data->player->angle); // fix the fisheye
		ft_draw_all(data); // render the wall, floor and ceiling
		data->ray->angle = data->ray->start + ++data->ray->index * ANGLE_STEP; // next angle
	}
}
