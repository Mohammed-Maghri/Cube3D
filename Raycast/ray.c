/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 11:51:54 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_render_all(t_data *data, int ray, int color)
{
    double	wall_height;
    int     pixel;

	data->ray->distance *= cos(data->ray->ray_angle - data->player->angle); // fix the fisheye
	wall_height = (TILE_SIZE / data->ray->distance) * DISTANCE_PLAN; // get the wall height
	(wall_height > WINDOW_HEIGHT) && (wall_height = WINDOW_HEIGHT);
    pixel = 0;
    while (pixel < HEIGHT_CENTER - (wall_height / 2))
	{
		ft_mlx_put_pixel(data->mlx, ray, pixel, CEILING_COLOR); // ceiling
		ft_mlx_put_pixel(data->mlx, ray, HEIGHT_CENTER + (wall_height / 2) + pixel++, FLOOR_COLOR); // floor
		// ft_mlx_put_pixel(data->mlx, ray, WINDOW_HEIGHT - pixel++, FLOOR_COLOR); // floor with border
	}
	// pixel += 2; // add border to ceiling
    while (pixel <= HEIGHT_CENTER)
	{
        ft_mlx_put_pixel(data->mlx, ray, pixel, color);//wall
        ft_mlx_put_pixel(data->mlx, ray, WINDOW_HEIGHT - pixel++, color);//wall
	}
}

void    ft_cast_rays(t_data *data)
{
    t_coordinate    intersection;
	double	        start_angle;
	int		        ray_index;

	ray_index = 0;
	start_angle = data->player->angle - (FOV / 2);
	data->ray->ray_angle = start_angle;
	while (data->ray->ray_angle < start_angle + FOV)
	{
		intersection.x = ft_horizont_intersect(data, ft_normalize(data->ray->ray_angle));
		intersection.y = ft_vertical_intersect(data, ft_normalize(data->ray->ray_angle));
		if (intersection.y <=intersection.x) // check the distance
		{
			data->ray->distance = intersection.y; // get the distance
			ft_render_all(data, ray_index++, WALL_COLOR); // render the wall, floor and ceiling
		}
		else
		{
			data->ray->distance =intersection.x; // get the distance
			ft_render_all(data, ray_index++, WALL_SHADE); // render the wall, floor and ceiling
		}
		data->ray->ray_angle = start_angle + ray_index * ANGLE_STEP; // next angle
	}
}
