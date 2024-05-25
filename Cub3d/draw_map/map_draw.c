/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/25 21:27:35 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void draw_map(char **twode, t_store *elemenets)
{
    t_pars le;
    t_map mx;
    (void)twode; 
    (void)elemenets; 
    mx.mlx_ptr = mlx_init();
    le.index = 100;
    le.incre = 100;
    mx.images = mlx_new_image(mx.mlx_ptr, 100, 100);
    mx.pic = mlx_xpm_file_to_image(mx.mlx_ptr, "./textures/wall.xpm", &le.index, &le.incre);
    if (!mx.pic)
        exit_message("WAAAA asad \n");
    le.index = count_twode_arr(twode) * 100;
    le.incre = le_count(twode[0]) * 100;
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
            {

                x = (le.index * 100);
                y = (le.incre * 100);
                printf("   | %d |---[ %d ]  \n", x , y);
                mlx_put_image_to_window(mx.mlx_ptr, winss, mx.pic, x,  y);
            }
            le.incre++ ;
        }
        le.incre = 0;
        le.index++ ;
    }
    mlx_loop(mx.mlx_ptr);
}