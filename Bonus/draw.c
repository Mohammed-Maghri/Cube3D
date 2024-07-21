/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:56:44 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 18:00:41 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_door(t_data *data, double a, double b)
{
	int		x;
	int		y;

	x = a / TSIZE;
	y = b / TSIZE;
	if (x < 0 || x >= data->map->map_width || \
		y < 0 || y >= data->map->map_height)
		return (0);
	if (data->map->map[y][x] == 'D' && \
		hypot(a - data->player->pos_in_pixels.x, b - \
		data->player->pos_in_pixels.y) > 1.5 * TSIZE)
	{
		if (data->ray->view == 'h')
		{
			data->map->h_door = 1;
			data->map->v_door = 0;
		}
		else
		{
			data->map->v_door = 1;
			data->map->h_door = 0;
		}
		return (1);
	}
	return (0);
}

void	ft_wall_data(t_data *data, int *top, int *bot)
{
	data->wall_distance = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	data->wall_height = (int)((TSIZE / data->ray->distance) * \
							data->wall_distance);
	*top = (WINDOW_HEIGHT / 2) - (data->wall_height / 2);
	*bot = (WINDOW_HEIGHT / 2) + (data->wall_height / 2);
	(*bot > WINDOW_HEIGHT) && (*bot = WINDOW_HEIGHT);
	if (data->map->door == 1)
		data->wall = data->mlx->door;
	data->texture = (uint32_t *)data->wall->pixels;
	if (data->ray->view == 'v')
		data->wall_start = (int)(data->ray->v_distance.y * \
			data->wall->height / TSIZE) % data->wall->height;
	else
		data->wall_start = (int)(data->ray->h_distance.x * \
			data->wall->width / TSIZE) % data->wall->width;
}

void	ft_draw_all(t_data *data)
{
	int	pixel;
	int	top;
	int	bot;
	int	step;

	pixel = 0;
	ft_wall_data(data, &top, &bot);
	while (pixel < top)
	{
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)
			ft_mlx_put_pixel(data->mlx, data->ray->index, \
							pixel, data->ceiling_color);
		ft_mlx_put_pixel(data->mlx, data->ray->index, \
							bot + pixel++, data->floor_color);
	}
	while (pixel < bot)
	{
		step = (pixel - top) * ((double)data->wall->height / data->wall_height);
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, \
				ft_texture_color(data->texture[data->wall->width * \
					step + data->wall_start]));
		pixel++;
	}
	data->map->door = 0;
}
