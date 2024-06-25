/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 09:28:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double  ft_distance(t_coordinate a, t_position b)
{
    return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

double  ft_normalize(double angle)
{
	return (angle + ((angle < 0) - (angle > (2 * M_PI))) * (2 * M_PI));
}

void    ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	    mlx_put_pixel(mlx->image, x, y, color);
}
