/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/27 20:10:36 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_color(int r, int g, int b, int a)
{
	return ((((r * 256 + g) * 256) + b) * 256 + a);
}

int	ft_texture_color(unsigned int c)
{
	int	r;
	int	g;
	int	b;
	int	a;

	a = c % 256;
	c /= 256;
	b = c % 256;
	c /= 256;
	g = c % 256;
	c /= 256;
	r = c;
	return (ft_color(a, b, g, r));
}

int	ft_wall(t_map *map, double a, double b)
{
	int	x;
	int	y;

	x = a / TSIZE;
	y = b / TSIZE;
	if (x < 0 || y < 0 || y >= map->map_height || x >= map->map_width \
				|| (map->map[y][x] == '1'))
		return (1);
	return (0);
}

int	ft_near_wall(t_map *map, double a, double b)
{
	if (ft_wall(map, a, b) || ft_wall(map, a + PIXI, b) || \
		ft_wall(map, a - PIXI, b) || ft_wall(map, a, b + PIXI) || \
		ft_wall(map, a, b - PIXI) || ft_wall(map, a + PIXI, b + PIXI) || \
		ft_wall(map, a - PIXI, b - PIXI))
		return (1);
	return (0);
}

int	ft_door(t_data *data, double a, double b)
{
	int		x;
	int		y;

	x = a / TSIZE;
	y = b / TSIZE;
	if (x < 0 || x >= data->map->map_width || \
		y < 0 || y >= data->map->map_height)
		return (0);
	if (data->map->map[y][x] == 'D')
	{
		if (hypot(a - data->player->pos_in_pixels.x, b - \
		data->player->pos_in_pixels.y) > 1.5 * TSIZE)
		{
			if (data->ray->view == 'h')
				data->map->h_door = 1;
			if (data->ray->view == 'v')
				data->map->v_door = 1;
			return (1);
		}
	}
	return (0);
}
