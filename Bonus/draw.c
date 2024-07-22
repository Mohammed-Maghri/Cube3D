/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:56:44 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 15:21:16 by cmasnaou         ###   ########.fr       */
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

int	ft_wall_data(t_data *data, int *top, int *bot)
{
	data->wall_distance = (data->win_width / 2) / tan(M_PI / 6);
	data->wall_height = (int)((TSIZE / data->ray->distance) * \
							data->wall_distance);
	*top = (data->win_height / 2) - (data->wall_height / 2);
	*bot = (data->win_height / 2) + (data->wall_height / 2);
	(*bot > data->win_height) && (*bot = data->win_height);
	if (data->map->door == 1)
		data->texture = data->mlx->door;
	data->color = (uint32_t *)data->texture->pixels;
	if (data->ray->view == 'v')
		data->wall_start = (int)(data->ray->v_distance * \
			data->texture->height / TSIZE) % data->texture->height;
	else
		data->wall_start = (int)(data->ray->h_distance * \
			data->texture->width / TSIZE) % data->texture->width;
	return (0);
}

// void draw_image_on_image(t_data *data, mlx_texture_t *bonus, int x, int y)
// {
// 	int index ;
// 	int increment ;
// 	(void)x;
// 	(void)y;
// 	int i;
// 	int r, g, b, a;

// 	// value = 0;
// 	index = 0;
// 	increment = 0;
// 	while (index < (int)bonus->height)
// 	{
// 		increment = 0;
// 		while (increment < (int)bonus->width)
// 		{
// 			i = (index * bonus->width + increment) * 4;
// 			r = bonus->pixels[i];
// 			g = bonus->pixels[i + 1];
// 			b = bonus->pixels[i + 2];
// 			a = bonus->pixels[i + 3];
// 			if (a != 0 && b != 0 && g != 0 && r != 0)
// 				mlx_put_pixel(data->mlx->image, increment + x, index + y, ft_color(r, g, b, a));
// 			increment++;
// 		}
// 		index++;
// 	}
// }

void	ft_draw_image(t_data *data, mlx_texture_t *texture, int x, int y)
{
	int	i ;
	int	j;
	int	color;

	i = 0;
	j = 0;
	data->color = (uint32_t *)texture->pixels;
	while (i < (int)texture->height)
	{
		j = 0;
		while (j < (int)texture->width)
		{
			color = ft_texture_color(data->color[i * texture->width + j]);
			if (color)
				mlx_put_pixel(data->mlx->image, j + x, i + y, \
			ft_texture_color(data->color[i * texture->width + j]));
			j++;
		}
		i++;
	}
}

void	ft_draw_all(t_data *data)
{
	int	pixel;
	int	top;
	int	bot;
	int	step;

	pixel = ft_wall_data(data, &top, &bot);
	while (pixel < top)
	{
		if (data->ray->index >= data->mini_width || pixel >= data->mini_height)
			ft_mlx_put_pixel(data, data->ray->index, \
							pixel, data->ceiling_color);
		ft_mlx_put_pixel(data, data->ray->index, \
							bot + pixel++, data->floor_color);
	}
	while (pixel < bot)
	{
		step = (pixel - top) * \
				((double)data->texture->height / data->wall_height);
		if (data->ray->index >= data->mini_width || pixel >= data->mini_height)
			ft_mlx_put_pixel(data, data->ray->index, pixel, \
				ft_texture_color(data->color[data->texture->width * \
					step + data->wall_start]));
		pixel++;
	}
	data->map->door = 0;
}
