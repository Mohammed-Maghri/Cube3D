/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 20:43:24 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_init_data(t_data **data, t_store *store)
{
    (*data) = (t_data *)malloc(sizeof(t_data));//ok
    if (!data || !*data)
        exit(1);
    (*data)->player = (t_player *)malloc(sizeof(t_player));//fix
    (*data)->ray = (t_ray *)malloc(sizeof(t_ray));//fix
    (*data)->map = (t_map *)malloc(sizeof(t_map));//fix
    (*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));//fix
    if (!(*data)->ray || !(*data)->player || !(*data)->map || !(*data)->mlx)
        ft_close(*data);
    (*data)->mlx->pointer = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", 0);
    (*data)->mlx->no_wall = mlx_load_png(store->no);// protect!
    (*data)->mlx->so_wall = mlx_load_png(store->so);// protect!
    (*data)->mlx->we_wall = mlx_load_png(store->we);// protect!
    (*data)->mlx->ea_wall = mlx_load_png(store->ea);// protect!
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
    data->check_reload = 0;
    data->player->pos_in_pixels.x = data->player->pos_in_map.x * TSIZE + TSIZE / 2;
    data->player->pos_in_pixels.y = data->player->pos_in_map.y * TSIZE + TSIZE / 2;
    data->player->angle = store->player_position;
    data->floor_color = ft_color(store->f[0], store->f[1], store->f[2], 255);
    data->ceiling_color = ft_color(store->c[0], store->c[1], store->c[2], 255);
}

// void leak(){system("leaks cub3D");}

int main()
{
    // atexit(leak);
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
    mlx_set_cursor_mode(data->mlx->pointer, MLX_MOUSE_HIDDEN);
    // mlx_cursor_hook(data->mlx->pointer, &mlx_cursor_move, data);
	mlx_loop(data->mlx->pointer);
    // prin_map(map->array);
    return (0);
}