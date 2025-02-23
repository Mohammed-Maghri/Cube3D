/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrawall_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:50:24 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:07:26 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_side_walls(char **twode)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
	while (twode[le.index] && le.index < get_last_wall_position(twode))
	{
		while (twode[le.index][le.incre] == '-')
			le.incre++ ;
		if (twode[le.index][le.incre] != '1')
			exit_message("Sides Not Closed  !!\n");
		le.incre = 0;
		le.index++ ;
	}
	le.index = 0;
	le.incre = 0;
	while (twode[le.index] && le.index < get_last_wall_position(twode))
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

void	bothwalls(char **twode)
{
	t_pars	ch;

	ch.index = 0;
	ch.incre = 0;
	while (twode[0] && twode[0][ch.index])
	{
		if (twode[count_twode_arr(twode) - 1][ch.index] != '1' \
		&& twode[count_twode_arr(twode) - 1][ch.index] != '-')
			exit_message("Map Not closed ...!\n");
		ch.index++ ;
	}
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
