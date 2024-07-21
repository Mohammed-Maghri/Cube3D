/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:58:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/21 15:48:53 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	get_longest_line(char **twode)
{
	t_pars	ch;

	ch.index = 0;
	ch.flag = 0;
	if (count_twode_arr(twode) != 0)
	{
		while (twode[ch.index])
		{
			if (ch.flag < le_count(twode[ch.index]))
				ch.flag = le_count(twode[ch.index]);
			ch.index++ ;
		}
	}
	return (ch.flag);
}

char	*heal_line(char *element, int biggest, char replace)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
	le.flag = 0;
	if (biggest == 0)
		return (NULL);
	le.buf = gb(sizeof(char) * (biggest + 1), 1);
	while (element[le.index])
	{
		if (element[le.index] == '\t')
			exit_message("Tabs Not Allowed Inside the Map .. !\n");
		if (element[le.index] == ' ')
		{
			le.buf[le.incre] = replace;
			le.index++ ;
			le.incre++ ;
		}
		else
		{
			le.buf[le.incre] = element[le.index];
			le.index++ ;
			le.incre++ ;
		}
	}
	while (le.incre < biggest)
	{
		le.buf[le.incre] = replace;
		le.incre++ ;
	}
	le.buf[le.incre] = '\0';
	return (le.buf);
}

int	check_on_check(char string)
{
	if (string == ' ' || string == '\t' || string == '\0')
		return (-1);
	if (string == '1' || string == '0' || string == '\n')
		return (-1);
	if (string == 'S' || string == 'W' || string == 'E' || string == 'N' || string == 'D')
		return (-1);
	return (0);
}

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
