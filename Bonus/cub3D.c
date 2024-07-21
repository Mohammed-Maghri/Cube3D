/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 09:52:47 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_init_data(t_data **data, t_store *store)
{
    (*data) = (t_data *)malloc(sizeof(t_data));
    if (!*data)
        exit(1);
    (*data)->ray = (t_ray *)malloc(sizeof(t_ray));
    (*data)->player = (t_player *)malloc(sizeof(t_player));
    (*data)->map = (t_map *)malloc(sizeof(t_map));//// add protection
    (*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));//// add protection
    (*data)->mlx->pointer = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", 0);
    (*data)->mlx->no_wall = mlx_load_png(store->no);// protect!
    (*data)->mlx->so_wall = mlx_load_png(store->so);// protect!
    (*data)->mlx->we_wall = mlx_load_png(store->we);// protect!
    (*data)->mlx->ea_wall = mlx_load_png(store->ea);// protect!
    (*data)->mlx->door = mlx_load_png("textures/door.png");// protect!
    if (!(*data)->ray || !(*data)->player || !(*data)->mlx->pointer)
        ft_close(*data);
}

void    ft_init_player(t_data *data, t_store *store)
{
    data->player->rotation = 0;
    data->player->left_right = 0;
    data->player->up_down = 0;
    data->player->move.x = 0;
    data->player->pos_in_map.x = store->x;
    data->player->pos_in_map.y = store->y;
    data->player->move.y = 0;
    data->player->pos_in_pixels.x = data->player->pos_in_map.x * TSIZE + TSIZE / 2;
    data->player->pos_in_pixels.y = data->player->pos_in_map.y * TSIZE + TSIZE / 2;
    data->player->angle = store->player_position;
    data->floor_color = ft_color(store->f[0], store->f[1], store->f[2], 255);
    data->ceiling_color = ft_color(store->c[0], store->c[1], store->c[2], 255);
    data->bonus2 = mlx_load_png("textures/gun.png"); // protect!
    data->reload = mlx_load_png("textures/reload/re1.png"); // protect!
    data->reload2 = mlx_load_png("textures/reload/re2.png"); // protect!
    data->reload3 = mlx_load_png("textures/reload/re3.png"); // protect!
    data->reload = mlx_load_png("textures/reload/re1.png"); // protect!
    data->reload2  = mlx_load_png("textures/reload/1.png"); // protect!
    data->reload2  = mlx_load_png("textures/reload/1.png"); // protect 
    data->reload3  = mlx_load_png("textures/reload/2.png"); // protect!
    data->reload4  = mlx_load_png("textures/reload/3.png"); // protect!
    data->reload5  = mlx_load_png("textures/reload/4.png"); // protect!
    data->reload6  = mlx_load_png("textures/reload/5.png"); // protect!
    data->reload7  = mlx_load_png("textures/reload/7.png"); // protect!
    data->reload8  = mlx_load_png("textures/reload/8.png"); // protect!
    data->reload9  = mlx_load_png("textures/reload/9.png"); // protect!
    data->reload10 = mlx_load_png("textures/reload/10.png"); // protect!
    data->reload11 = mlx_load_png("textures/reload/13.png"); // protect!
    data->reload12 = mlx_load_png("textures/reload/14.png"); // protect!
    data->reload13 = mlx_load_png("textures/reload/14.png");
    data->check_reload = -1;
}

int main()
{
    t_data  *data;
    t_store *store ;
    t_pars *map ;

    store = gb(sizeof(t_store), 1);
    map = gb(sizeof(t_pars), 1);

    merge_all_functions(map, store);
    data = (t_data *){0};
    ft_init_data(&data, store);
    ft_init_player(data, store);
     data->map->map_height = count_twode_arr(map->array);
    data->map->map_width = le_count(map->array[0]);
    data->map->map = map->array ;
    prin_map(map->array);

    mlx_loop_hook(data->mlx->pointer, &ft_update_window, data);
	mlx_key_hook(data->mlx->pointer, &ft_key_move, data);
    // mlx_set_cursor_mode(data->mlx->pointer, MLX_MOUSE_DISABLED);
    mlx_set_cursor_mode(data->mlx->pointer, MLX_MOUSE_HIDDEN);
    mlx_cursor_hook(data->mlx->pointer, &ft_mouse_move, data);
	mlx_loop(data->mlx->pointer);
    // prin_map(map->array);
    return (0);
}
