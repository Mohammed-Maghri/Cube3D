/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/29 18:31:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_allocate_data(t_data **data, t_store *store)
{
	(*data) = (t_data *)gb(sizeof(t_data), 1);
	if (!data || !*data)
		exit(1);
	(*data)->player = (t_player *)gb(sizeof(t_player), 1);
	(*data)->ray = (t_ray *)gb(sizeof(t_ray), 1);
	(*data)->map = (t_map *)gb(sizeof(t_map), 1);
	(*data)->mlx = (t_mlx *)gb(sizeof(t_mlx), 1);
	if (!(*data)->ray || !(*data)->player || !(*data)->map || !(*data)->mlx)
		exit(1);
	(*data)->mlx->pointer = mlx_init(WINDOW_WIDTH * TSIZE, \
								WINDOW_HEIGHT * TSIZE, "Cub3D", 0);
	if (!(*data)->mlx->pointer)
		exit(1);
	(*data)->mlx->no_wall = mlx_load_png(store->no);
	(*data)->mlx->so_wall = mlx_load_png(store->so);
	(*data)->mlx->we_wall = mlx_load_png(store->we);
	(*data)->mlx->ea_wall = mlx_load_png(store->ea);
	if (!(*data)->mlx->pointer || !(*data)->mlx->no_wall || \
		!(*data)->mlx->so_wall || !(*data)->mlx->we_wall || \
		!(*data)->mlx->ea_wall)
		ft_close(*data);
}

void	ft_init_data(t_data *data, t_store *store, char **map)
{
	data->player->rotation = 0;
	data->player->left_right = 0;
	data->player->up_down = 0;
	data->player->pos_in_map.x = store->x;
	data->player->pos_in_map.y = store->y;
	data->player->pos_in_pixels.x = store->x * TSIZE + TSIZE / 2;
	data->player->pos_in_pixels.y = store->y * TSIZE + TSIZE / 2;
	data->player->angle = store->player_position;
	data->scale = ((double)MSIZE / TSIZE);
	data->win_height = WINDOW_HEIGHT * TSIZE;
	data->win_width = WINDOW_WIDTH * TSIZE;
	data->mini_height = data->win_height / 4;
	data->mini_width = data->win_width / 4;
	data->floor_color = ft_color(store->f[0], store->f[1], store->f[2], 255);
	data->ceiling_color = ft_color(store->c[0], store->c[1], store->c[2], 255);
	data->map->map_height = count_twode_arr(map);
	data->map->map_width = le_count(map[0]);
	data->map->map = map;
}

void	functionpassarguments(int argc, char **argv, t_pars *map)
{
	if (argc != 2)
	{
		printf("Map Not Found !\n");
		exit(1);
	}
	if (argv[1][le_count(argv[1]) - 1] != 'b' || \
		argv[1][le_count(argv[1]) - 2] != 'u' || \
		argv[1][le_count(argv[1]) - 3] != 'c' || \
		argv[1][le_count(argv[1]) - 4] != '.')
	{
		printf("Error\n");
		exit(1);
	}
	map->map_name = argv[1];
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_store	*store ;
	t_pars	*map ;

	if (TSIZE == 0)
		exit(1);
	store = gb(sizeof(t_store), 1);
	map = gb(sizeof(t_pars), 1);
	data = (t_data *){0};
	if (!store || !map)
		exit(1);
	functionpassarguments(argc, argv, map);
	merge_all_functions(map, store);
	ft_allocate_data(&data, store);
	ft_init_data(data, store, map->array);
	mlx_loop_hook(data->mlx->pointer, &ft_update_window, data);
	mlx_key_hook(data->mlx->pointer, &ft_key_move, data);
	mlx_set_cursor_mode(data->mlx->pointer, MLX_MOUSE_HIDDEN);
	mlx_loop(data->mlx->pointer);
	return (0);
}
