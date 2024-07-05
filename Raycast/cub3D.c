/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:31:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/05 14:41:10 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_init_data(t_data **data)
{
    (*data) = (t_data *)malloc(sizeof(t_data));
    if (!*data)
        exit(1);
    (*data)->ray = (t_ray *)malloc(sizeof(t_ray));
    (*data)->player = (t_player *)malloc(sizeof(t_player));
    (*data)->map = (t_map *)malloc(sizeof(t_map));//// add protection
    // (*data)->map->map = (char **)malloc((MAP_HEIGHT + 1) * sizeof(char *));
    (*data)->mlx = (t_mlx *)malloc(sizeof(t_mlx));//// add protection
    (*data)->mlx->pointer = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", 0);
    if (!(*data)->ray || !(*data)->player || !(*data)->mlx->pointer)
        ft_close(*data);
}

void    ft_init_player(t_data *data)
{
    data->player->rotation = 0;
    data->player->left_right = 0;
    data->player->up_down = 0;
    data->player->pos_in_map.x = 14;
    data->player->pos_in_map.y = 3;
    data->player->move.x = 0;
    data->player->move.y = 0;
    data->player->pos_in_pixels.x = data->player->pos_in_map.x * TSIZE + TSIZE / 2;
    data->player->pos_in_pixels.y = data->player->pos_in_map.y * TSIZE + TSIZE / 2;
    data->player->angle = M_PI;
}

void    ft_init_map(t_data *data)
{
    int i = -1;
    int j = -1;
    char    map[9][25] = 
                   {"1111111111111111111111111",
                    "1000000000010000000100001",
                    "1001000010000P00000000001",
                    "1001000000000000001000001",
                    "1001000000000000001000001",
	                "1001000000100000001000001",
	                "1001000000000000001000001",
	                "1001000000001000001000001",
                    "1111111111111111111111111"};
    // char    map[20][25] = 
    //                {"1111111111111111111111111",
    //                 "1000000000010000000100001",
    //                 "1001000010000P00000000001",
    //                 "1001000000000000001000001",
    //                 "1001000000000000001000001",
	//                 "1001000000100000001000001",
	//                 "1001000000000000001000001",
	//                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1001000000001000001000001",
    //                 "1111111111111111111111111"};
    
    // data->map->map_height = 20;
    // data->map->map_width = 25;
    data->map->map_height = 9;
    data->map->map_width = 25;
    data->map->map = (char **)malloc((data->map->map_height + 1) * sizeof(char *));
    while (++i < data->map->map_height)
    {
        j = -1;
        data->map->map[i] = (char *)malloc((data->map->map_width + 1) * sizeof(char));
        while (++j < data->map->map_width)
            data->map->map[i][j] = map[i][j];
    }
    data->map->map[i] = NULL;
    
	// data->map->map[0] = ft_strdup("1111111111111111111111111");
	// data->map->map[1] = ft_strdup("1000000000010000000100001");
	// data->map->map[2] = ft_strdup("1001000010000P00000000001");
	// data->map->map[3] = ft_strdup("1001000000000000001000001");
	// data->map->map[4] = ft_strdup("1001000000000000001000001");
	// data->map->map[5] = ft_strdup("1001000000100000001000001");
	// data->map->map[6] = ft_strdup("1001000000000000001000001");
	// data->map->map[7] = ft_strdup("1001000000001000001000001");
	// data->map->map[8] = ft_strdup("1111111111111111111111111");
	// data->map->map[9] = NULL;
}


void    ft_mouse_move(mouse_key_t button, action_t action, modifier_key_t mods, void* d)
{
    t_data	*data;
	data = d;
    (void)mods;
    
    (button == 1) && (data->player->rotation = action); // right
    (button == 0) && (data->player->rotation = -action); // left
}

int main()
{
    t_data  *data;
    
    // data = (t_data *){0};
    ft_init_data(&data);
    ft_init_player(data);
    ft_init_map(data);
    mlx_loop_hook(data->mlx->pointer, &ft_update_window, data);
	mlx_key_hook(data->mlx->pointer, &ft_key_move, data);
    mlx_mouse_hook(data->mlx->pointer, &ft_mouse_move, data);
	mlx_loop(data->mlx->pointer);

    return (0);
}