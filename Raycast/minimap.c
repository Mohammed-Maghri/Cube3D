/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/04 17:58:02 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void    ft_draw_ray(t_data *data) // moving player
// {
// 	t_coordinate start;
// 	t_coordinate step;
// 	int pixel_count;

// 	start.x = data->player->pos_in_pixels.x * UNITY;
// 	start.y = data->player->pos_in_pixels.y * UNITY;
// 	step.x = cos(data->ray->angle);
// 	step.y = sin(data->ray->angle);
// 	pixel_count = data->ray->distance * UNITY + 1;
// 	while (--pixel_count >= 0)
// 		ft_mlx_put_pixel(data->mlx, start.x + step.x * pixel_count, start.y + step.y * pixel_count, 0xAAAAAAFF);
// }

void    ft_draw_ray(t_data *data) // fixed player
{
	t_position player;
	t_coordinate step;
	int pixel_count;

	player.x = MINI_WIDTH / 2;
	player.y = MINI_HEIGHT / 2;
	step.x = cos(data->ray->angle);
	step.y = sin(data->ray->angle);
	pixel_count = data->ray->distance * UNITY + 1;
	while (--pixel_count >= 0)
		if (step.x * pixel_count < MINI_WIDTH / 2 && step.y * pixel_count < MINI_HEIGHT / 2)
			ft_mlx_put_pixel(data->mlx, player.x + step.x * pixel_count, player.y + step.y * pixel_count, 0xAAAAAAEE);
}

void ft_draw_square(t_data *data, int tileSize, int color, int y, int x)
{
	int i;
	int j;

	i = -1;
	while (++i < tileSize)
	{
		j = -1;
		while (++j < tileSize)
				ft_mlx_put_pixel(data->mlx, (j + y), (i + x), color);
	}
}

void    ft_draw_player(t_data *data) // fixed player
{
	ft_draw_square(data, MSIZE / 3, WALL_COLOR, \
					MINI_WIDTH / 2 - MSIZE / 6, \
					MINI_HEIGHT / 2 - MSIZE / 6);
}

// void    ft_draw_player(t_data *data)// moving player
// {
// 	ft_draw_square(data, MSIZE / 3, WALL_COLOR, \
// 					data->player->pos_in_pixels.x * UNITY - MSIZE / 6, \
// 					data->player->pos_in_pixels.y * UNITY - MSIZE / 6);
// }


// void ft_draw_minimap(t_data *data)// fixed map
// {
// 	int i;
// 	int j;

// i = -1;
// 	while (++i < data->map->map_height)
// 	{
// 		j = -1;
// 		while (++j < data->map->map_width)
// 		{
// 			if (data->map->map[i][j] == '1')
// 				ft_draw_square(data, MSIZE, WALL_COLOR, j * MSIZE, i * MSIZE);
// 			else
// 				ft_draw_square(data, MSIZE, 0xAAAAAABF, j * MSIZE , i * MSIZE);
// 		}
// 	}
// }

void ft_draw_minimap(t_data *data)// moving map
{
	int i;
	int j;
	t_coordinate diff;
	
	diff.x = (MINI_WIDTH / 2 - data->player->pos_in_pixels.x * UNITY) / MSIZE;
	diff.y = (MINI_HEIGHT / 2 - data->player->pos_in_pixels.y * UNITY) / MSIZE;
	i = -1;
	while (++i < data->map->map_height)
	{
		j = -1;
		while (++j < data->map->map_width)
		{
			if (data->map->map[i][j] == '1')
				ft_draw_square(data, MSIZE, WALL_COLOR, (j + diff.x) * MSIZE, (i + diff.y) * MSIZE);
			else
				ft_draw_square(data, MSIZE, MINI_COLOR, (j + diff.x) * MSIZE , (i + diff.y) * MSIZE);
		}
	}
}
