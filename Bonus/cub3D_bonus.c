/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/26 08:16:01 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_allocate_data(t_data **data)
{
	(*data) = (t_data *)gb(sizeof(t_data), 1);
	if (!*data)
		exit(1);
	(*data)->ray = (t_ray *)gb(sizeof(t_ray), 1);
	(*data)->player = (t_player *)gb(sizeof(t_player), 1);
	(*data)->map = (t_map *)gb(sizeof(t_map), 1);
	(*data)->mlx = (t_mlx *)gb(sizeof(t_mlx), 1);
	if (!(*data)->ray || !(*data)->player || !(*data)->map || !(*data)->mlx)
		exit(1);
	(*data)->mlx->pointer = mlx_init(WINDOW_WIDTH * TSIZE, \
			WINDOW_HEIGHT * TSIZE, "Cub3D_bonus", 0);
	if (!(*data)->mlx->pointer)
		exit(1);
}

void	ft_init_data(t_data *data, t_store *store, char **map)
{
	data->player->rotation = 0;
	data->player->left_right = 0;
	data->player->up_down = 0;
	data->player->move.x = 0;
	data->player->pos_in_map.x = store->x;
	data->player->pos_in_map.y = store->y;
	data->player->move.y = 0;
	data->player->pos_in_pixels.x = data->player->pos_in_map.x * \
									TSIZE + TSIZE / 2;
	data->player->pos_in_pixels.y = data->player->pos_in_map.y * \
									TSIZE + TSIZE / 2;
	data->player->angle = store->player_position;
	data->hide_mouse = 1;
	data->scale = ((double)MSIZE / TSIZE);
	data->win_width = WINDOW_WIDTH * TSIZE;
	data->win_height = WINDOW_HEIGHT * TSIZE;
	data->mini_height = data->win_height / 4;
	data->mini_width = data->win_width / 4;
	data->floor_color = ft_color(store->f[0], store->f[1], store->f[2], 255);
	data->ceiling_color = ft_color(store->c[0], store->c[1], store->c[2], 255);
	data->map->map_height = count_twode_arr(map);
	data->map->map_width = le_count(map[0]);
	data->map->map = map;
	data->check_reload = -1;
}

void	ft_init_texture(t_data *data, t_store *store)
{
	data->mlx->no_wall = mlx_load_png(store->no);
	data->mlx->so_wall = mlx_load_png(store->so);
	data->mlx->we_wall = mlx_load_png(store->we);
	data->mlx->ea_wall = mlx_load_png(store->ea);
	data->bonus = mlx_load_png("textures/gun.png");
	data->mlx->door = mlx_load_png("textures/door.png");
	data->reload[0] = mlx_load_png("textures/reload/1.png");
	data->reload[1] = mlx_load_png("textures/reload/2.png");
	data->reload[2] = mlx_load_png("textures/reload/3.png");
	data->reload[3] = mlx_load_png("textures/reload/5.png");
	data->reload[4] = mlx_load_png("textures/reload/2.png");
	if (!data->mlx->no_wall || !data->mlx->so_wall
		|| !data->mlx->we_wall || !data->mlx->ea_wall
		|| !data->mlx->door || !data->reload[0]
		|| !data->reload[1] || !data->reload[2]
		|| !data->reload[3] || !data->reload[4])
		ft_close(data);
}

int	main(void)
{
	t_data	*data;
	t_store	*store ;
	t_pars	*map ;

	store = gb(sizeof(t_store), 1);
	map = gb(sizeof(t_pars), 1);
	merge_all_functions(map, store);
	ft_allocate_data(&data);
	ft_init_data(data, store, map->array);
	ft_init_texture(data, store);
	prin_map(map->array);
	mlx_loop_hook(data->mlx->pointer, &ft_update_window, data);
	mlx_key_hook(data->mlx->pointer, &ft_key_move, data);
	mlx_mouse_hook(data->mlx->pointer, &ft_mouse_clic, data);
	mlx_set_cursor_mode(data->mlx->pointer, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(data->mlx->pointer, &ft_mouse_move, data);
	mlx_loop(data->mlx->pointer);
	return (0);
}

void	ft_close(t_data *data)
{
	mlx_delete_image(data->mlx->pointer, data->mlx->image);
	mlx_close_window(data->mlx->pointer);
	mlx_terminate(data->mlx->pointer);
	write(1, "GAME OVER!\n", 12);
	kill_sound();
	exit(0);
}
