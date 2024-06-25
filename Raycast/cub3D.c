/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 12:07:55 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_init_data(t_data **data)
{
    (*data) = (t_data *)malloc(sizeof(t_data));
    (*data)->ray = (t_ray *)malloc(sizeof(t_ray));
    (*data)->player = (t_player *)malloc(sizeof(t_player));
    (*data)->map = (t_map *)malloc(sizeof(t_map));
    (*data)->map->map = (char **)malloc((MAP_HEIGHT + 1) * sizeof(char *));
    (*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));
}

void    ft_init_player(t_data *data)
{
    data->player->rotation_flag = 0;
    data->player->left_right_flag = 0;
    data->player->up_down_flag = 0;
    data->player->pos_in_map.x = 14;
    data->player->pos_in_map.y = 3;
    data->player->pos_in_pixels.x = data->player->pos_in_map.x * TILE_SIZE + TILE_SIZE / 2;
    data->player->pos_in_pixels.y = data->player->pos_in_map.y * TILE_SIZE + TILE_SIZE / 2;
    data->player->angle = M_PI;
}

void    ft_init_map(t_data *data)
{
    data->map->map_height = MAP_HEIGHT;
    data->map->map_width = MAP_WIDTH;
	data->map->map[0] = ft_strdup("1111111111111111111111111");
	data->map->map[1] = ft_strdup("1000000000010000000100001");
	data->map->map[2] = ft_strdup("1001000010000P00000000001");
	data->map->map[3] = ft_strdup("1001000000000000001000001");
	data->map->map[4] = ft_strdup("1001000000000000001000001");
	data->map->map[5] = ft_strdup("1001000000100000001000001");
	data->map->map[6] = ft_strdup("1001000000000000001000001");
	data->map->map[7] = ft_strdup("1001000000001000001000001");
	data->map->map[8] = ft_strdup("1111111111111111111111111");
	data->map->map[9] = NULL;
}

void    ft_init_mlx(t_data *data)
{
    data->mlx->pointer = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", 0);
    mlx_loop_hook(data->mlx->pointer, &ft_update_window, data);
	mlx_key_hook(data->mlx->pointer, &ft_key_move, data);
	mlx_loop(data->mlx->pointer);
}


int main()
{
    t_data  *data;

    ft_init_data(&data);
    ft_init_player(data);
    ft_init_map(data);
    ft_init_mlx(data);
    return (0);
}