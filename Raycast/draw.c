/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:57:52 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 12:09:17 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_hit_wall(t_map *map, double x, double y)	// check the wall hit
{
    t_position  pos;

	pos.x = x / TILE_SIZE; // get the x position in the map
	pos.y = y / TILE_SIZE; // get the y position in the map
	if (pos.x < 0 || pos.y < 0)
		return (0);
	if (pos.y >= map->map_height || pos.x >= map->map_width)
		return (0);
	if (map->map[pos.y][pos.x] == '1')
			return (0);
	return (1);
}

double	ft_horizont_intersect(t_data *data, double angle)	// get the horizontal intersection
{
	t_coordinate    point;
    t_coordinate    step;
	int				ray_down;
	int				ray_left;

	ray_down = (angle > 0 && angle < M_PI);//up = 1 down = 0
	ray_left = (angle > M_PI / 2 && angle < 3 * M_PI / 2);//left = 1 right = 0
	point.y = (data->player->pos_in_pixels.y / TILE_SIZE + ray_down) * TILE_SIZE;
	point.x = data->player->pos_in_pixels.x + (point.y - data->player->pos_in_pixels.y) / tan(angle);
	step.y = TILE_SIZE * (2 * ray_down - 1);
	step.x = TILE_SIZE / tan(angle);
	step.x *= 1 - 2 * (ray_left && step.x > 0);
	step.x *= 1 - 2 * (!ray_left && step.x < 0);
	while (ft_hit_wall(data->map, point.x, point.y - !ray_down)) // check if ray hit wall
		((point.x += step.x) && (point.y += step.y));
	return (ft_distance(point, data->player->pos_in_pixels)); // get the distance
}

double	ft_vertical_intersect(t_data *data, double angle)	// get the vertical intersection
{
    t_coordinate    point;
    t_coordinate    step;
	int				ray_down;
	int				ray_left;

	ray_down = (angle > 0 && angle < M_PI);//up = 1 down = 0
	ray_left = (angle > M_PI / 2 && angle < 3 * M_PI / 2);//left = 1 right = 0
	point.x = (data->player->pos_in_pixels.x / TILE_SIZE + !ray_left) * TILE_SIZE;
	point.y = data->player->pos_in_pixels.y + (point.x - data->player->pos_in_pixels.x) * tan(angle);
	step.x = TILE_SIZE * (1 - 2 * ray_left);
	step.y = TILE_SIZE * tan(angle);
	step.y *= 1 - 2 * (!ray_down && step.y > 0);
	step.y *= 1 - 2 * (ray_down && step.y < 0);
	while (ft_hit_wall(data->map, point.x - ray_left, point.y)) // check if ray hit wall
		((point.x += step.x) && (point.y += step.y));
	return (ft_distance(point, data->player->pos_in_pixels)); // get the distance
}
