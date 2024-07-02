/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/01 18:10:22 by mmaghri          ###   ########.fr       */
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
           *(unsigned int *)(element->data + ((x + i) * element->linelenght + (y + j) * (element->dat / 8)) ) = color;
    }
}

void draw_map(t_store *elemenets)
{
    int y;
    int x;
    int tilex;
    int tiley;


    y = -1;
    elemenets->imag = mlx_new_image(elemenets->mlx, \
    (le_count(elemenets->array[0]) - 1) * 30, count_twode_arr(elemenets->array)  * 30);
    elemenets->data = mlx_get_data_addr(elemenets->imag, &elemenets->dat, &elemenets->linelenght, &elemenets->endian);
    while (elemenets->array[++y])
    {
        x = -1;
        while (elemenets->array[y][++x])
        {
            tilex = (x - 1) * 30;
            tiley = y * 30;
            if (elemenets->array[y][x] == '0')
                draw_square(elemenets, 30, tilex , tiley, 0);
            else if (elemenets->array[y][x] == '1')
                draw_square(elemenets, 30, tilex , tiley, 255);
            else if (elemenets->array[y][x] == 'S')
                draw_square(elemenets, 10 , tilex, tiley, 65280);
        }
    }
    mlx_put_image_to_window(elemenets->mlx, elemenets->win, elemenets->imag, 0, 0);
}

void get_player_position(t_store *elem, int flag)
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
                if (flag == 125)
                {
                    if (elem->array[le.index + 1][le.incre] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index + 1][le.incre] = 'S';
                        return;
                    }
                }
                if (flag == 126)
                {
                    if (elem->array[le.index - 1][le.incre] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index - 1][le.incre] = 'S';
                        return;
                    }
                }
                if (flag == 124)
                {
                    if (elem->array[le.index][le.incre + 1] != '1')
                    {
                        elem->array[le.index][le.incre] = '0';
                        elem->array[le.index][le.incre + 1] = 'S';
                        return;
                    }
                }
                if (flag == 123)
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
int key_press(int key, t_store *elemenets)
{
    (void)key ;
    printf("---> %d \n" , key);
    if (key == 53)
        exit(0);
    if (key == 125)
        get_player_position(elemenets, key);
    if (key == 126)
        get_player_position(elemenets, key);
    if (key == 124)
        get_player_position(elemenets, key);
    if (key == 123)
        get_player_position(elemenets, key);
    prin_map(elemenets->array);
    return (0);
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
    le.incre = le_count(elemenets->array[0]) -1;
    elemenets->win = mlx_new_window( elemenets->mlx, le.incre * 30, le.index * 30,"map_test");
    mlx_key_hook(elemenets->win, key_press, (t_store *)elemenets);
    
    mlx_loop_hook(elemenets->mlx, draw, (void *)elemenets);
    mlx_loop( elemenets->mlx);
}