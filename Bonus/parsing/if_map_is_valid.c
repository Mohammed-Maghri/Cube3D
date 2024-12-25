/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:58:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:04:11 by mmaghri          ###   ########.fr       */
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

char	*returncharfile(char replace, int incre, int biggest, char *buf)
{
	while (incre < biggest)
	{
		buf[incre] = replace;
		incre++ ;
	}
	buf[incre] = '\0';
	return (buf);
}

char	*heal_line(char *element, int biggest, char replace)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
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
	return (returncharfile(replace, le.incre, biggest, le.buf));
}

int	check_on_check(char string)
{
	if (string == ' ' || string == '\t' || string == '\0')
		return (-1);
	if (string == '1' || string == '0' || string == '\n')
		return (-1);
	if (string == 'S' || string == 'W' || string == 'E' \
	|| string == 'N' || string == 'D')
		return (-1);
	return (0);
}
