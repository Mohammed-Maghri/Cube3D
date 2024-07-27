/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:56:44 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/27 20:07:34 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_wall_data(t_data *data, int *top, int *bot)
{
	data->wall_distance = (data->win_width / 2) / tan(M_PI / 6);
	data->wall_height = (TSIZE / data->ray->distance) * \
							data->wall_distance;
	*top = (data->win_height / 2) - (data->wall_height / 2);
	*bot = (data->win_height / 2) + (data->wall_height / 2);
	(*bot > data->win_height) && (*bot = data->win_height);
	data->color = (uint32_t *)data->texture->pixels;
	if (data->ray->view == 'v')
		data->wall_start = (int)(data->ray->v_intersect.y * \
			data->texture->height / TSIZE) % data->texture->height;
	else
		data->wall_start = (int)(data->ray->h_intersect.x * \
			data->texture->width / TSIZE) % data->texture->width;
	return (0);
}

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
}
