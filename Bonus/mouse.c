/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:11:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 21:53:51 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_mouse_move(double xpos, double ypos, void *d)
{
	t_data		*data;
	t_position	mouse;

	data = d;
	(void)xpos;
	(void)ypos;
	if (data->hide_mouse)
	{
		mlx_get_mouse_pos(data->mlx->pointer, &mouse.x, &mouse.y);
		data->player->rotation = MOUSE_SPEED * (double)(mouse.x - \
												(data->win_width / 2));
		mlx_set_mouse_pos(data->mlx->pointer, (data->win_width / 2), \
												(data->win_height / 2));
	}
}
