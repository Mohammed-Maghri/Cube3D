/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 19:28:55 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_normalize(t_ray *ray)
{
	ray->angle = fmod(ray->angle, 2 * M_PI);
	ray->angle += (ray->angle < 0) * 2 * M_PI;
	ray->down = (ray->angle > 0 && ray->angle < M_PI);
	ray->left = (ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2);
	ray->up = !ray->down;
	ray->right = !ray->left;
}

double	ft_hdistance(t_data *data)
{
	t_coordinate	point;
	t_coordinate	step;

	data->ray->view = 'h';
	point.y = (data->player->pos_in_pixels.y / TSIZE + data->ray->down) * TSIZE;
	point.x = data->player->pos_in_pixels.x + \
		(point.y - data->player->pos_in_pixels.y) / tan(data->ray->angle);
	step.y = TSIZE * (2 * data->ray->down - 1);
	step.x = fabs(TSIZE / tan(data->ray->angle)) * (2 * data->ray->right - 1);
	while (!ft_wall(data->map, point.x, point.y - data->ray->up) \
			&& !ft_door(data, point.x, point.y - data->ray->up))
		(1) && (point.x += step.x) && (point.y += step.y);
	data->ray->h_distance = point.x;
	point.x -= data->player->pos_in_pixels.x;
	point.y -= data->player->pos_in_pixels.y;
	return (hypot(point.x, point.y));
}

double	ft_vdistance(t_data *data)
{
	t_coordinate	point;
	t_coordinate	step;

	data->ray->view = 'v';
	point.x = (data->player->pos_in_pixels.x / TSIZE + \
				data->ray->right) * TSIZE;
	point.y = data->player->pos_in_pixels.y + (point.x - \
				data->player->pos_in_pixels.x) * tan(data->ray->angle);
	step.x = TSIZE * (2 * data->ray->right - 1);
	step.y = fabs(TSIZE * tan(data->ray->angle)) * (2 * data->ray->down - 1);
	while (!ft_wall(data->map, point.x - data->ray->left, point.y) \
			&& !ft_door(data, point.x - data->ray->left, point.y))
		(1) && (point.x += step.x) && (point.y += step.y);
	data->ray->v_distance = point.y;
	point.x -= data->player->pos_in_pixels.x;
	point.y -= data->player->pos_in_pixels.y;
	return (hypot(point.x, point.y));
}

void	ft_min_distance(t_data *data, double distance)
{
	if (distance >= data->ray->distance)
	{
		data->ray->view = 'v';
		data->wall = data->mlx->ea_wall;
		data->map->door = data->map->v_door;
		if (data->ray->left)
			data->wall = data->mlx->we_wall;
	}
	if (distance < data->ray->distance)
	{
		data->ray->view = 'h';
		data->ray->distance = distance;
		data->map->door = data->map->h_door;
		data->wall = data->mlx->so_wall;
		if (data->ray->up)
			data->wall = data->mlx->no_wall;
	}
}

void	ft_cast_rays(t_data *data)
{
	double	distance;

	data->ray->index = 0;
	data->ray->start = data->player->angle - (FOV / 2);
	data->ray->angle = data->ray->start;
	while (data->ray->angle < data->ray->start + FOV)
	{
		data->map->v_door = 0;
		data->map->h_door = 0;
		ft_normalize(data->ray);
		distance = ft_hdistance(data);
		data->ray->distance = ft_vdistance(data);
		ft_min_distance(data, distance);
		ft_draw_ray(data);
		data->ray->distance *= cos(data->ray->angle - data->player->angle);
		ft_draw_all(data);
		data->ray->angle = data->ray->start + ++data->ray->index * ANGLE_STEP;
	}
}
