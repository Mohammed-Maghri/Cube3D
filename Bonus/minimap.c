/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 21:51:58 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
		mlx_put_pixel(data->mlx->image, x, y, color);
}

void	ft_draw_ray(t_data *data)
{
	t_coordinate	start;
	t_coordinate	step;
	int				pixel_count;

	start.x = data->player->pos_in_pixels.x * data->scale;
	start.y = data->player->pos_in_pixels.y * data->scale;
	start.x += data->mini_width / 2 - floor(start.x);
	start.y += data->mini_height / 2 - floor(start.y);
	step.x = cos(data->ray->angle);
	step.y = sin(data->ray->angle);
	pixel_count = data->ray->distance * data->scale + 1;
	while (--pixel_count >= 0)
	{
		if (start.x + step.x * pixel_count < data->mini_width && \
			start.y + step.y * pixel_count < data->mini_height)
			ft_mlx_put_pixel(data, start.x + step.x * pixel_count, \
										start.y + step.y * pixel_count, \
										0xAAAAAAEE);
	}
}

void	ft_draw_square(t_data *data, int size, int color, t_position p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_mlx_put_pixel(data, (j + p.x), (i + p.y), color);
	}
}

void	ft_draw_miniplayer(t_data *data)
{
	ft_draw_square(data, MSIZE / 3, MINI_COLOR, (t_position){\
					data->mini_width / 2 - MSIZE / 6, \
					data->mini_height / 2 - MSIZE / 6});
}

void	ft_draw_minimap(t_data *data)
{
	t_coordinate	diff;
	int				i;
	int				j;

	diff.x = data->mini_width / 2 - \
		floor(data->player->pos_in_pixels.x * data->scale);
	diff.y = data->mini_height / 2 - \
		floor(data->player->pos_in_pixels.y * data->scale);
	i = -1;
	while (++i < data->map->map_height)
	{
		j = -1;
		while (++j < data->map->map_width)
		{
			if (data->map->map[i][j] == '1')
				ft_draw_square(data, MSIZE, MINI_COLOR, (t_position){\
								j * MSIZE + diff.x, i * MSIZE + diff.y});
			else if (data->map->map[i][j] == 'D')
				ft_draw_square(data, MSIZE, DOOR_COLOR, (t_position){\
								j * MSIZE + diff.x, i * MSIZE + diff.y});
		}
	}
}
