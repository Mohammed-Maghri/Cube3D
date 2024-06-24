/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/06/24 17:55:23 by cmasnaou         ###   ########.fr       */
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
                mlx_put_pixel(element->imag, (j + y), (i + x), color);
    }
}

void draw_map(t_store *elemenets)
{
    int y;
    int x;
    int tilex;
    int tiley;
    int size_x;
    int size_y;

    y = -1;
    size_x = (le_count(elemenets->array[0]) - 1) * TSIZE;
    size_y = count_twode_arr(elemenets->array)  * TSIZE;
    elemenets->imag = mlx_new_image(elemenets->mlx, size_x, size_y);
    while (elemenets->array[++y])
    {
        x = -1;
        while (elemenets->array[y][++x])
        {
            tilex = (x - 1) * TSIZE;
            tiley = y * TSIZE;
            if (elemenets->array[y][x] == '0')
                draw_square(elemenets, TSIZE, tilex , tiley, 0xFFFFFF00);
            if (elemenets->array[y][x] == '1')
                draw_square(elemenets, TSIZE, tilex , tiley, 0xEEEEEEFF);
            if (elemenets->array[y][x] == 'S')
                draw_square(elemenets, TSIZE / 3 , tilex + TSIZE / 3 , tiley + TSIZE / 3 , 0x90EE90FF);
        }
    }
    mlx_image_to_window(elemenets->mlx, elemenets->imag, 0, 0);
}

void get_player_position(t_store *elem)
{
    t_pars le;

    le.index = 0;
    le.incre = 0;
    while (elem->array[le.index])
    {
        le.incre = 0;
        while (elem->array[le.index][le.incre])
        {
            if (elem->array[le.index][le.incre] == 'S')
            {
                if (mlx_is_key_down(elem->mlx, MLX_KEY_DOWN))
                {
                    if (elem->array[le.index + 1][le.incre] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index + 1][le.incre] = 'S';
                        return;
                    }
                }
                if (mlx_is_key_down(elem->mlx, MLX_KEY_UP))
                {
                    if (elem->array[le.index - 1][le.incre] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index - 1][le.incre] = 'S';
                        return;
                    }
                }
                if (mlx_is_key_down(elem->mlx, MLX_KEY_RIGHT))
                {
                    if (elem->array[le.index][le.incre + 1] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index][le.incre + 1] = 'S';
                        return;
                    }
                }
                if (mlx_is_key_down(elem->mlx, MLX_KEY_LEFT))
                {
                    if (elem->array[le.index][le.incre - 1] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index][le.incre - 1] = 'S';
                        return;
                    }
                }
            }
            le.incre++ ;
        }
        le.index++ ;
    }
}

void key_move(mlx_key_data_t key, void *e) // for key_hook
{
    t_store *elemenets;

    elemenets = e;
    // if (key.action == MLX_PRESS)
    // {
        if (key.key == MLX_KEY_ESCAPE)
            mlx_close_window(elemenets->mlx);
        get_player_position(elemenets);
        prin_map(elemenets->array); 
    // }
    // if (key.action == MLX_RELEASE)
    // {
        
    // }
}

int	close_window(t_store *elemenets)
{
    (void)elemenets;
    // free();
	// mlx_destroy_image();
	// mlx_destroy_window();
	exit(0);
}

void draw(void *e)
{
    t_store *elemenets;

    elemenets = e;
    draw_map(elemenets);
    // update
    // draw player
    // return (0);
}

void create_window(char **twode, t_store *elemenets)
{
    t_pars le;

    elemenets->array = twode;
    le.index = count_twode_arr(elemenets->array);
    le.incre = le_count(elemenets->array[0]) -1;
    elemenets->mlx = mlx_init(le.incre * TSIZE, le.index * TSIZE ,"map_test", 0);
    mlx_key_hook(elemenets->mlx, key_move, (t_store *)elemenets);
    mlx_loop_hook(elemenets->mlx, draw, (void *)elemenets);
    mlx_loop(elemenets->mlx);
    mlx_terminate(elemenets->mlx);
}