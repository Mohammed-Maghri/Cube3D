/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:06:13 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/12 11:16:43 by cmasnaou         ###   ########.fr       */
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
	while (!ft_wall(data->map, point.x, point.y - data->ray->up))
		(point.x += step.x) && (point.y += step.y);
	data->ray->x_distance = point.x;
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
	while (!ft_wall(data->map, point.x - data->ray->left, point.y))
		(point.x += step.x) && (point.y += step.y);
	data->ray->y_distance = point.y;
	point.x -= data->player->pos_in_pixels.x;
	point.y -= data->player->pos_in_pixels.y;
	return (hypot(point.x, point.y));
	// return (ft_distance(point, data->player->pos_in_pixels));
}

void    ft_draw_all(t_data *data)
{
    double	wall_height;
    int     pixel;
	double distance;

	data->texture = (uint32_t *)data->wall->pixels;
	distance = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	wall_height = (int)((TSIZE / data->ray->distance) * distance); // get the wall height
	int top = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	(top < 0) && (top = 0);
	int bot = (WINDOW_HEIGHT / 2) + (wall_height / 2);
	(bot > WINDOW_HEIGHT) && (bot = WINDOW_HEIGHT);
    pixel = 0;
	int start;
	int wall_start;
	int step;
	if (data->ray->view == 'v')
		start = (int)(data->ray->y_distance * data->wall->height / TSIZE) % data->wall->height;
	else
		start = (int)(data->ray->x_distance * data->wall->width / TSIZE) % data->wall->width;
    while (pixel < top)
	{
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)// fixed
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, data->ceiling_color); // ceiling
		ft_mlx_put_pixel(data->mlx, data->ray->index, bot + pixel++, data->floor_color); // floor
	}
    while (pixel < bot)
	{
		wall_start = pixel + (wall_height / 2) - (WINDOW_HEIGHT / 2);
		step = wall_start * ((double)data->wall->height / wall_height);
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)// fixed
        	ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, ft_texture_color(data->texture[data->wall->width * step + start]));//wall
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
		if (distance >= data->ray->distance)
		{
			data->ray->view = 'v';
			data->wall = data->mlx->ea_wall;
			if (data->ray->left)
				data->wall = data->mlx->we_wall;
		}
		if (distance < data->ray->distance)
		{
			data->ray->view = 'h';
			data->ray->distance = distance;
			data->wall = data->mlx->so_wall;
			if (data->ray->up)
				data->wall = data->mlx->no_wall;
		}
		ft_draw_ray(data); // mini map
		data->ray->distance *= cos(data->ray->angle - data->player->angle); // fix the fisheye
		ft_draw_all(data); // render the wall, floor and ceiling
		data->ray->angle = data->ray->start + ++data->ray->index * ANGLE_STEP; // next angle
	}

}
