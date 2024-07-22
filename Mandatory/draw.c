/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:24:42 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 10:13:35 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_wall_data(t_data *data, int *top, int *bot)
{
	data->wall_distance = (WINDOW_WIDTH / 2) / tan(FOV / 2);
	data->wall_height = (int)((TSIZE / data->ray->distance) * \
							data->wall_distance);
	*top = (WINDOW_HEIGHT / 2) - (data->wall_height / 2);
	*bot = (WINDOW_HEIGHT / 2) + (data->wall_height / 2);
	(*bot > WINDOW_HEIGHT) && (*bot = WINDOW_HEIGHT);
	data->color = (uint32_t *)data->texture->pixels;
	if (data->ray->view == 'v')
		data->wall_start = (int)(data->ray->v_distance * \
			data->texture->height / TSIZE) % data->texture->height;
	else
		data->wall_start = (int)(data->ray->h_distance * \
			data->texture->width / TSIZE) % data->texture->width;
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
		step = (pixel - top) * \
				((double)data->texture->height / data->wall_height);
		if (data->ray->index >= MINI_WIDTH || pixel >= MINI_HEIGHT)
			ft_mlx_put_pixel(data->mlx, data->ray->index, pixel, \
				ft_texture_color(data->color[data->texture->width * \
					step + data->wall_start]));
		pixel++;
	}
}
