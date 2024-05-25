/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:08:43 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/25 18:40:50 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void exit_message(char *string)
{
    putstring(string);
    exit(1);
}

void check_inside_map(char **twode)
{
    t_pars le;

    le.index = 0;
    le.incre = 0;
    while (twode[le.index])
    {
        if (twode[le.index] != 0 && \
            le.index != (count_twode_arr(twode) - 1))
        {
            while (twode[le.index][le.incre])
            {
                if (twode[le.index][le.incre] == '0' || twode[le.index][le.incre] == 'S')
                {
                    if (twode[le.index - 1][le.incre] == '-' || \
                    twode[le.index + 1][le.incre] == '-')
                        exit_message("Ooops Somthing Not Valid .. \n");
                    if (twode[le.index][le.incre + 1] && (twode[le.index][le.incre + 1] == '-'))
                        exit_message("Ooops Somthing Not Valid .. ");
                }
                le.incre++ ;
            }
            le.incre = 0;
        }
        le.index++ ;
    }
}
void check_side_walls(char **twode)
{
    t_pars le;

    le.index = 0;
    le.incre = 0;
    while (twode[le.index])
    {
        while (twode[le.index][le.incre] == '-')
            le.incre++ ;
        if (twode[le.index][le.incre] != '1')
        {
            printf("[ %s ]----[ %d ]\n", &twode[le.index][le.incre], le.incre);
            exit_message("Sides Not Closed \n !");
        }
        le.incre = 0;
        le.index++ ;
    }
    le.index = 0;
    le.incre = 0;
    while (twode[le.index])
    {
        le.incre = le_count(twode[le.index]);
        le.incre--;
        while (twode[le.index][le.incre] == '-')
            le.incre--;
        if (twode[le.index][le.incre] != '1')
            exit_message("Sides Not Closed !\n");
        le.index++ ;
    }
}
void  bothwalls(char **twode)
{
    t_pars ch;

    ch.index = 0;
    ch.incre = 0;
    prin_map(twode);
    while (twode[0] && twode[0][ch.index])
    {
        if (twode[count_twode_arr(twode) - 1][ch.index] != '1' \
        && twode[count_twode_arr(twode) - 1][ch.index] != '-')
            exit_message("Map Not closed ...!\n");
        ch.index++ ;
    }
    printf(" -- > %d", count_twode_arr(twode));
    if (count_twode_arr(twode) != 0)
    {
        while (twode[count_twode_arr(twode) - 1][ch.index])
        {
            if (twode[count_twode_arr(twode) - 1][ch.index] != '1' \
            && twode[count_twode_arr(twode) - 1][ch.index] != '-')
                exit_message("Map Not closed ...!\n");
            ch.index++ ;
        }
    }
}