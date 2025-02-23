/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmapvalidextra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:09:26 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:07:45 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_on(char *string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		if (check_on_check(string[index]) != -1)
		{
			putstring("Invalid MAP....!");
			exit(1);
		}
		index++ ;
	}
}

char	**copy_this(char **twode, char **map)
{
	t_pars	le;

	le.incre = 0;
	while (twode[le.index])
	{
		map[le.incre] = copy_move(twode[le.index]);
		le.index++ ;
		le.incre++ ;
	}
	map[le.incre] = NULL ;
	return (map);
}

char	**rebuild_map(char **twode)
{
	t_pars	le;
	char	**map ;

	le.index = 6;
	le.incre = 0;
	map = gb(sizeof(char *) * count_twode_arr(twode), 2);
	while (twode[le.index])
	{
		if (function_check_ithem(twode[le.index]) == 0)
		{
			while (twode[le.index][le.incre] && \
			(twode[le.index][le.incre] == ' '\
			|| twode[le.index][le.incre] == '\t'))
				le.incre++ ;
			if (twode[le.index][le.incre] == '1')
				return (copy_this(&twode[le.index], map));
		}
		le.incre = 0;
		le.index++ ;
	}
	return (NULL);
}
