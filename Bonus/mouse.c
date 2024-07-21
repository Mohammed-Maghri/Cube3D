/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/21 15:50:13 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

// void    ft_mouse_move(mouse_key_t button, action_t action, modifier_key_t mods, void* d)
// {
//     t_data	*data;
// 	data = d;
//     (void)mods;
    
//     // (button == 1) && (data->player->rotation = action); // right
//     // (button == 0) && (data->player->rotation = -action); // left
// }

void ft_mouse_move(double xpos, double ypos, void* d)
{
    t_data	*data;
    (void)xpos;
    (void)ypos;
    t_position mouse;
	data = d;
    
    mlx_get_mouse_pos(data->mlx->pointer, &mouse.x, &mouse.y);
    // data->player->rotation = MOUSE_SPEED * (double)(mouse.x - (WINDOW_WIDTH / 2)) / (WINDOW_HEIGHT / 2); // right
    data->player->rotation = MOUSE_SPEED * (double)(mouse.x - (WINDOW_WIDTH / 2)); // right
    mlx_set_mouse_pos(data->mlx->pointer, (WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2));
}

// void mlx_cursor_move(double xpos, double ypos, void* d)
// {
//     t_data	*data;
//     static double position;
// 	data = d;
//     (void)ypos;
    
//     data->player->rotation = 0;
//     if (xpos < 0 || xpos > WINDOW_WIDTH || ypos < 0 || ypos > WINDOW_HEIGHT)
//     {
//         data->player->rotation = 0;
//         return ;
//     }
//     (position < xpos) && (data->player->rotation = MOUSE_SPEED); // right
//     (position > xpos) && (data->player->rotation = -MOUSE_SPEED); // left
//     position = xpos;
// }
