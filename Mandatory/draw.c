/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:24:42 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 19:40:17 by cmasnaou         ###   ########.fr       */
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
	data->texture = (uint32_t *)data->wall->pixels;
	if (data->ray->view == 'v')
		data->wall_start = (int)(data->ray->v_distance * \
			data->wall->height / TSIZE) % data->wall->height;
	else
		data->wall_start = (int)(data->ray->h_distance * \
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
}
