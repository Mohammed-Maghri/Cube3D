/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:08:43 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/21 15:49:09 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	exit_message(char *string)
{
	putstring(string);
	exit(1);
}

void	check_inside_map(char **twode)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
	while (twode[le.index])
	{
		if (twode[le.index] != 0 && \
			le.index != (count_twode_arr(twode) - 1))
		{
			while (twode[le.index][le.incre])
			{
				if (twode[le.index][le.incre] == '0')
				{
					if (twode[le.index - 1][le.incre] == '-' || \
					twode[le.index + 1][le.incre] == '-')
						exit_message("Ooops  Not a Valid Map ... ! \n");
					if (twode[le.index][le.incre + 1] && \
					(twode[le.index][le.incre + 1] == '-' \
					|| twode[le.index][le.incre - 1] == '-'))
						exit_message("Ooops  Not a Valid Map ... ! \n");
				}
				le.incre++ ;
			}
			le.incre = 0;
		}
		le.index++ ;
	}
}


int get_last_wall_position(char **twode)
{
	int	index;
	int	incre;

	incre = 0;
	index = 0;
	while (twode[index])
	{
		while (twode[index][incre])
		{
			if (twode[index][incre] != '-')
				break ;
			incre++ ;
		}
		if (incre == le_count(twode[index]))
			return (index);
		incre = 0;
		index++ ;
	}
	return (-1);
}

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
void  bothwalls(char **twode)
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
