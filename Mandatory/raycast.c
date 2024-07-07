/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/07 16:21:59 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void  ft_normalize(t_data *data)
{
	data->ray->angle = fmod(data->ray->angle, 2 * M_PI);
	data->ray->angle += (data->ray->angle < 0) * 2 * M_PI;
    // while (data->ray->angle < 0)
    //     data->ray->angle += 2 * M_PI;
    // while (data->ray->angle  >= (2 * M_PI))
    //     data->ray->angle -= 2 * M_PI;
    data->ray->down = (data->ray->angle > 0 && data->ray->angle < M_PI);//up = 1 down = 0
	data->ray->left = (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * M_PI / 2);//left = 1 right = 0
    data->ray->up = !data->ray->down;
    data->ray->right = !data->ray->left;
}

double	ft_hdistance(t_data *data)
{
	t_coordinate    point;
    t_coordinate    step;
	
	point.y = (data->player->pos_in_pixels.y / TSIZE + data->ray->down) * TSIZE;
	point.x = data->player->pos_in_pixels.x + (point.y - data->player->pos_in_pixels.y) / tan(data->ray->angle);
	step.y = TSIZE * (2 * data->ray->down - 1);
	step.x = fabs(TSIZE / tan(data->ray->angle)) * (2 * data->ray->right - 1);
	while (!ft_wall(data->map, point.x / TSIZE, (point.y - data->ray->up) / TSIZE))
		(point.x += step.x) && (point.y += step.y);
	point.x -= data->player->pos_in_pixels.x;
	point.y -= data->player->pos_in_pixels.y;
	return (hypot(point.x, point.y));
	// return (ft_distance(point, data->player->pos_in_pixels));
}

double	ft_vdistance(t_data *data)
{
    t_coordinate    point;
    t_coordinate    step;
	
	point.x = (data->player->pos_in_pixels.x / TSIZE + data->ray->right) * TSIZE;
	point.y = data->player->pos_in_pixels.y + (point.x - data->player->pos_in_pixels.x) * tan(data->ray->angle);
	step.x = TSIZE * (2 * data->ray->right - 1);
	step.y = fabs(TSIZE * tan(data->ray->angle)) * (2 * data->ray->down - 1);
	while (!ft_wall(data->map, (point.x - data->ray->left)/ TSIZE, point.y / TSIZE))
		(point.x += step.x) && (point.y += step.y);
	point.x -= data->player->pos_in_pixels.x;
	point.y -= data->player->pos_in_pixels.y;
	return (hypot(point.x, point.y));
	// return (ft_distance(point, data->player->pos_in_pixels));
}

void    ft_draw_all(t_data *data)
{
	int			start;
	double			index;
	uint32_t		*texture;
	double			step;
    double	wall_height;//
    int     pixel;//

	wall_height = DISTANCE_PLAN / data->ray->distance; // get the wall height
	(wall_height > WINDOW_HEIGHT) && (wall_height = WINDOW_HEIGHT);//
	texture = (uint32_t *)data->wall->pixels;
	step = (double)data->wall->height / wall_height;
	data->ray->distance *= data->wall->width / TSIZE;
	start = fmod(data->ray->distance, data->wall->width);
	index = 0;
    pixel = 0;
    while (pixel < HALF_HEIGHT - (wall_height / 2))
	{
		if (data->ray->index >= MINI_WIDTH)// fixed
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, data->ceiling_color); // ceiling
		if (pixel >= MINI_HEIGHT)// fixed
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, data->ceiling_color); // ceiling
		ft_mlx_put_pixel(data->mlx, data->ray->index, HALF_HEIGHT + (wall_height / 2) + pixel++, data->floor_color); // floor
	}
    while (pixel <= HALF_HEIGHT + (wall_height / 2) - 1)
	{
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)// fixed
        	ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, texture[start + (int)index * data->wall->width]);//wall
		index += step;
		pixel++;
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
		/**** for a different color for each side: ***/
		// if ((distance > data->ray->distance) && data->ray->left)
		// 	data->ray->color = 0xFFE2FFFF;
		// if ((distance > data->ray->distance) && data->ray->right)
		// 	data->ray->color = 0xB0E2AAFF;
		// if ((distance <= data->ray->distance) &&  data->ray->up)
		// 	data->ray->color = 0xFFE255FF;
		// if ((distance <= data->ray->distance) &&  data->ray->down)
		// 	data->ray->color = 0xB112AAFF;
		(distance <= data->ray->distance) && (data->ray->color = WALL_SHADE);//
		/*******************************************/
		data->ray->distance = fmin(data->ray->distance, distance);
		ft_draw_ray(data); // mini map
		data->ray->distance *= cos(data->ray->angle - data->player->angle); // fix the fisheye
		ft_draw_all(data); // render the wall, floor and ceiling
		data->ray->angle = data->ray->start + ++data->ray->index * ANGLE_STEP; // next angle
	}
}
