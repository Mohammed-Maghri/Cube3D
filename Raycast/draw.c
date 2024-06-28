/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:57:52 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/28 18:28:26 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	ft_horizont_intersect(t_data *data)	// get the horizontal intersection
{
	t_coordinate    point;
    t_coordinate    step;
	
	point.y = (data->player->pos_in_pixels.y / TSIZE + data->ray->down) * TSIZE;
	point.x = data->player->pos_in_pixels.x + (point.y - data->player->pos_in_pixels.y) / tan(data->ray->angle);
	step.y = TSIZE * (2 * data->ray->down - 1);
	step.x = fabs(TSIZE / tan(data->ray->angle)) * (2 * data->ray->right - 1);
	while (!ft_wall(data->map, point.x / TSIZE, (point.y - data->ray->up) / TSIZE)) // check if ray hit wall
		((point.x += step.x) && (point.y += step.y));
	return (ft_distance(point, data->player->pos_in_pixels)); // get the distance
}

double	ft_vertical_intersect(t_data *data)	// get the vertical intersection
{
    t_coordinate    point;
    t_coordinate    step;
	
	point.x = (data->player->pos_in_pixels.x / TSIZE + data->ray->right) * TSIZE;
	point.y = data->player->pos_in_pixels.y + (point.x - data->player->pos_in_pixels.x) * tan(data->ray->angle);
	step.x = TSIZE * (2 * data->ray->right - 1);
	step.y = fabs(TSIZE * tan(data->ray->angle)) * (2 * data->ray->down - 1);
	while (!ft_wall(data->map, (point.x - data->ray->left) / TSIZE, point.y / TSIZE)) // check if ray hit wall
		((point.x += step.x) && (point.y += step.y));
	return (ft_distance(point, data->player->pos_in_pixels)); // get the distance
}
