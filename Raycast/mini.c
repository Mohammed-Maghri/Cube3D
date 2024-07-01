/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:11:23 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/01 18:05:53 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_draw_ray(t_data *data)
{
    double deltaX;
    double deltaY;
    int pixels;
    double pixelX;
    double pixelY;

        pixelX = data->player->pos_in_pixels.x * UNITY;
        pixelY = data->player->pos_in_pixels.y * UNITY;
        deltaX = cos(data->ray->angle) * (data->ray->distance - data->player->pos_in_pixels.x / TSIZE) * UNITY;
        deltaY = sin(data->ray->angle) * (data->ray->distance - data->player->pos_in_pixels.y / TSIZE) * UNITY;
        pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
        deltaX /= pixels;
        deltaY /= pixels;
        while (pixels >= 0)
        {
            ft_mlx_put_pixel(data->mlx, pixelX, pixelY, 0x858536ff);
            pixelX += deltaX;
            pixelY += deltaY;
            --pixels;
        }

}

void ft_draw_square(t_data *data, int tileSize, int y, int x, int color)
{
    int i;
    int j;

    i = -1;
    while (++i < tileSize)
    {
        j = -1;
        while (++j < tileSize)
                ft_mlx_put_pixel(data->mlx, (j + y), (i + x), color);
    }
}

void ft_draw_player(t_data *data)
{
    ft_draw_square(data, MSIZE / 3, data->player->pos_in_pixels.x * UNITY - MSIZE / 6, data->player->pos_in_pixels.y * UNITY - MSIZE / 6, WALL_COLOR);
}
void ft_draw_map(t_data *data)
{
    int y;
    int x;
    int tilex;
    int tiley;

    y = -1;
    while (++y < data->map->map_height)
    {
        x = -1;
        while (++x < data->map->map_width)
        {
            tilex = x * MSIZE;
            tiley = y * MSIZE;
            if (data->map->map[y][x] == '1')
                ft_draw_square(data, MSIZE, tilex , tiley, WALL_COLOR);
            else
                ft_draw_square(data, MSIZE, tilex , tiley, 0xAAAAAAFF);
        }
    }
}