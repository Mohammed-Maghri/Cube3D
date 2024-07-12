/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:04:58 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 09:28:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_close(t_data *data)
{
	int	i = -1;

    mlx_delete_image(data->mlx->pointer, data->mlx->image);
    mlx_close_window(data->mlx->pointer);
	mlx_terminate(data->mlx->pointer);
	free(data->mlx);
	while (data->map->map[++i])
		free(data->map->map[i]);
	free(data->map->map);
	free(data->map);
	free(data->player);
	free(data->ray);
    free(data);
	write(1, "GAME OVER!\n", 12);
	kill_sound();
	exit(0);
}
