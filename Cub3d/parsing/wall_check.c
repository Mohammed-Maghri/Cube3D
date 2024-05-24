/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:08:43 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/24 18:15:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void exit_message(char *string)
{
    putstring(string);
    exit(1);
}
void  bothwalls(char **twode)
{
    t_pars ch;

    ch.index = 0;
    ch.incre = 0;
    while (twode[count_twode_arr(twode) - 1][ch.index])
    {
        if (twode[count_twode_arr(twode) - 1][ch.index] != '1' \
        && twode[count_twode_arr(twode) - 1][ch.index] != '-')
            exit_message("Map Not closed ...!\n");
        ch.index++ ;
    }
}