/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/26 18:48:17 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void count_players(char **twode)
{
    t_pars elem;

    elem.index = 0;
    elem.incre = 0;
    elem.flag = 0;

    while (twode[elem.index])
    {
        while (twode[elem.index][elem.incre])
        {
            if (twode[elem.index][elem.incre] == 'S')
                elem.flag++ ;
            elem.incre++ ;
        }
        if (elem.flag > 1)
            exit_message("It Should Be One player ..!\n");
        elem.incre = 0;
        elem.index++ ;
    }
    if (elem.flag == 0)
        exit_message("It Should Be One player ..!\n");
}

void draw_square(t_store *element, int tileSize, int y, int x, int color)
{
    int i;
    int j;

    i = -1;
    while (++i < tileSize)
    {
        j = -1;
        while (++j < tileSize)
            mlx_pixel_put(element->mlx, element->win, i + y, j + x, color);
    }
}

void draw_map(t_store *elemenets)
{
    int y;
    int x;
    int tilex;
    int tiley;

    y = -1;
    elemenets->imag = mlx_new_image(elemenets->mlx, le_count(elemenets->array[0]) * 50, count_twode_arr(elemenets->array) * 50);
    while (++y < count_twode_arr(elemenets->array))
    {
        x = -1;
        while (++x < le_count(elemenets->array[0]))
        {
            tilex = x * 50;
            tiley = y * 50;
            if (elemenets->array[y][x] == '1')
                draw_square(elemenets, 50, tilex, tiley, 255);
            else 
                draw_square(elemenets, 50, tilex, tiley, 0);
        }
    }
}

int draw(t_store *elemenets)
{
    draw_map(elemenets);
    // update
    // draw player
    return (0);
}
void create_window(char **twode, t_store *elemenets)
{
    t_pars le;

     elemenets->array = twode;
    elemenets->mlx = mlx_init();
    le.index = count_twode_arr(elemenets->array);
    le.incre = le_count(elemenets->array[0]);
    elemenets->win = mlx_new_window( elemenets->mlx, le.incre * 50, le.index * 50,"map_test");
    mlx_loop_hook(elemenets->mlx, draw, (void*)elemenets);
    mlx_loop( elemenets->mlx);
}