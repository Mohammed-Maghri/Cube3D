/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 21:59:58 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_close(t_data *data)
{
	mlx_delete_image(data->mlx->pointer, data->mlx->image);
	mlx_close_window(data->mlx->pointer);
	mlx_terminate(data->mlx->pointer);
	write(1, "GAME OVER!\n", 12);
	exit(0);
}
