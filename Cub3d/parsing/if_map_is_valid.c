/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:58:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/24 14:10:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_longest_line(char **twode)
{
	t_pars	ch;

	ch.index = 6;
	ch.flag = 0;
	while (twode[ch.index])
	{
		if (ch.flag < le_count(twode[ch.index]))
			ch.flag = le_count(twode[ch.index]);
		ch.index++ ;
	}
	return (ch.flag);
}

char	*heal_line(char *element, int biggest, char replace)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
	le.flag = 0;
	le.buf = gb(sizeof(char) + biggest + 1, 1);
	while (element[le.index])
	{
		if (element[le.index] == '\t')
		{
			while (le.flag < 4)
			{
				le.buf[le.incre] = replace;
				le.incre++ ;
				le.index++ ;
				le.flag++ ;
			}
			le.flag = 0;
		}
		if (element[le.index] == ' ')
		{
			le.buf[le.incre] = replace;
			le.incre++ ;
			le.index++ ;
		}
		else
		{
			le.buf[le.incre] = element[le.index];
			le.incre++ ;
			le.index++ ;
		}
	}
	while (le.incre <= biggest)
	{
		le.buf[le.incre] = replace;
		le.incre++ ;
	}
	le.buf[le.incre]  = '\0';
	return (le.buf);
}

char	*rebuild_map(char *twode)
{
	t_pars	le;

	le.index = 6;
	printf("%s\n", twode);
	return (NULL);
}