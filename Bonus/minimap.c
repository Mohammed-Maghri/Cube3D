/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 17:20:45 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
		mlx_put_pixel(mlx->image, x, y, color);
}

void	ft_draw_ray(t_data *data)
{
	t_coordinate	start;
	t_coordinate	step;
	int				pixel_count;

	start.x = data->player->pos_in_pixels.x * UNITY;
	start.y = data->player->pos_in_pixels.y * UNITY;
	start.x += MINI_WIDTH / 2 - floor(start.x);
	start.y += MINI_HEIGHT / 2 - floor(start.y);
	step.x = cos(data->ray->angle);
	step.y = sin(data->ray->angle);
	pixel_count = data->ray->distance * UNITY + 1;
	while (--pixel_count >= 0)
	{
		if (start.x + step.x * pixel_count < MINI_WIDTH && \
			start.y + step.y * pixel_count < MINI_HEIGHT)
			ft_mlx_put_pixel(data->mlx, start.x + step.x * pixel_count, \
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
			ft_mlx_put_pixel(data->mlx, (j + p.x), (i + p.y), color);
	}
}

void	ft_draw_miniplayer(t_data *data)
{
	ft_draw_square(data, MSIZE / 3, MINI_COLOR, (t_position){\
					MINI_WIDTH / 2 - MSIZE / 6, \
					MINI_HEIGHT / 2 - MSIZE / 6});
}

void	ft_draw_minimap(t_data *data)
{
	t_coordinate	diff;
	int				i;
	int				j;

	diff.x = MINI_WIDTH / 2 - floor(data->player->pos_in_pixels.x * UNITY);
	diff.y = MINI_HEIGHT / 2 - floor(data->player->pos_in_pixels.y * UNITY);
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
