/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/26 15:39:06 by mmaghri          ###   ########.fr       */
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
void draw_map(char **twode, t_store *elemenets)
{
    t_pars le;
    t_map mx;
    (void)elemenets; 
    mx.mlx_ptr = mlx_init();
    le.index = 100;
    le.incre = 100;
    mx.images = mlx_new_image(mx.mlx_ptr, 100, 100);
    mx.pic = mlx_xpm_file_to_image(mx.mlx_ptr, "./textures/sm.xpm", &le.index, &le.incre);
    mx.direction = mlx_xpm_file_to_image(mx.mlx_ptr, "./textures/dir.xpm", &le.index, &le.incre);
    if (!mx.pic)
        exit_message("Error In Drawing Getting The Elment..... !\n");
    le.index = count_twode_arr(twode) * 50;
    le.incre = le_count(twode[0]) * 50;
    void *winss = mlx_new_window(mx.mlx_ptr, le.incre, le.index ,"map_test");
    le.incre = 0;
    le.index = 0;
    int x ;
    int y ;
    x = 0 ;
    y = 0 ;
    while (twode[le.index])
    {
        while (twode[le.index][le.incre])
        {
            if (twode[le.index][le.incre] == '1')
                mlx_put_image_to_window(mx.mlx_ptr, winss, mx.pic, le.incre * 50,  le.index * 50);
            if (twode[le.index][le.incre] == 'S')
                mlx_put_image_to_window(mx.mlx_ptr, winss, mx.direction, le.incre * 50,  le.index * 50);
            le.incre++ ;
        }
        le.incre = 0;
        le.index++ ;
    }
    mlx_loop(mx.mlx_ptr);
}