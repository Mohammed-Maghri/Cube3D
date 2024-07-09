/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:58:12 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/05 18:01:18 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_wall(t_map *map, int x, int y)
{
	return ((x < 0 || y < 0 || y >= map->map_height || x >= map->map_width || (map->map[y][x] == '1')));
}

double  ft_distance(t_coordinate a, t_position b)
{
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void    ft_key_move(mlx_key_data_t keydata, void *d)
{
    t_data	*data;
	int	key;
	int action;

	data = d;
	key = keydata.key;
	action = keydata.action; // 1 for key_press // 0 for key_release // 2 for key_repeat 
	if (key == ESC)
		ft_close(data);
	(action == 2) && (action = 1);
	(key == R) && (data->player->rotation = action); // right
	(key == L) && (data->player->rotation = -action); // left
	(key == 'W') && (data->player->up_down = action);
	(key == 'S') && (data->player->up_down = -action);
	(key == 'D') && (data->player->left_right = action);
	(key == 'A') && (data->player->left_right = -action);
}

void	ft_move_player(t_data *data)
{
	t_player *player;
	t_position	pos;

	player = data->player;
	player->angle += player->rotation * ROTATION_SPEED; // +ROTATION_SPEED or -ROTATION_SPEED
	if (player->up_down || player->left_right) //move
	{
		player->move.x = PLAYER_SPEED * cos(player->angle + player->left_right * (M_PI / 2) + (player->up_down < 0) * M_PI);
		player->move.y = PLAYER_SPEED * sin(player->angle + player->left_right * (M_PI / 2) + (player->up_down < 0) * M_PI);
		pos.x = roundf(player->pos_in_pixels.x + player->move.x); // get the new x position
		pos.y = roundf(player->pos_in_pixels.y + player->move.y); // get the new y position
		player->move = (t_coordinate){0, 0};
		if (!ft_wall(data->map, pos.x / TSIZE, pos.y / TSIZE) \
			&& data->map->map[pos.y / TSIZE][data->player->pos_in_pixels.x / TSIZE] != '1' \
			&& data->map->map[data->player->pos_in_pixels.y / TSIZE][pos.x / TSIZE] != '1')
		{
			player->pos_in_pixels.x = pos.x; // move the player
			player->pos_in_pixels.y = pos.y; // move the player
		}
			
	}
}

unsigned int ft_color2(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void draw_image_on_image(t_data *data, mlx_texture_t *bonus, int x, int y)
{
	int index ;
	int increment ;
	(void)x;
	(void)y;
	int i;
	int r, g, b, a;

	// value = 0;
	index = 0;
	increment = 0;
	while (index < (int)bonus->height)
	{
		increment = 0;
		while (increment < (int)bonus->width)
		{
			i = (index * bonus->width + increment) * 4;
			r = bonus->pixels[i];
			g = bonus->pixels[i + 1];
			b = bonus->pixels[i + 2];
			a = bonus->pixels[i + 3];
			if (a != 0 && b != 0 && g != 0 && r != 0)
				mlx_put_pixel(data->mlx->image, increment + x, index + y, ft_color2(r, g, b, a));
			increment++;
		}
		index++;
	}
}

// void function_check_if_reload(t_data *data)
// {
// 	if (data->check_reload == 0)
// 		draw_image_on_image(data, data->bonus2, 500, 586);
// 	else if (data->check_reload == 1)
// 	{
// 		draw_image_on_image(data, data->reload, 500, 400);
// 		draw_image_on_image(data, data->reload, 500, 400);
// 		draw_image_on_image(data, data->reload, 500, 400);
// 		data->check_reload = 2;
// 	}
// 	else if (data->check_reload == 2)
// 	{
// 		draw_image_on_image(data, data->reload2, 500, 400);
// 		draw_image_on_image(data, data->reload2, 500, 400);
// 		draw_image_on_image(data, data->reload2, 500, 400);
// 		draw_image_on_image(data, data->reload2, 500, 400);

// 		data->check_reload = 3;
// 	}
// 	else if (data->check_reload == 3)
// 	{
// 		draw_image_on_image(data, data->reload3, 500, 400);
// 		data->check_reload = 0;
	
// 	}
// }

void    ft_update_window(void *d)
{
	t_data			*data;

	data = d;

	mlx_delete_image(data->mlx->pointer, data->mlx->image);	// delete the image
	data->mlx->image = mlx_new_image(data->mlx->pointer, WINDOW_WIDTH, WINDOW_HEIGHT);	// create new image
	ft_move_player(data);
	ft_draw_minimap(data); // 
	ft_cast_rays(data);	// cast the rays
	ft_draw_miniplayer(data); // 
	draw_image_on_image(data, data->bonus2, 500, 586);
	// function_check_if_reload(data);
	mlx_image_to_window(data->mlx->pointer, data->mlx->image, 0, 0); // put the image to the window
}
