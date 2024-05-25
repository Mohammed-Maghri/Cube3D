/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:03:09 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/25 17:43:45 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**initial_it(void)
{
	char	**element;

	element = gb(sizeof(char *) * 7, 2);
	element[0] = "NO";
	element[1] = "SO";
	element[2] = "WE";
	element[3] = "EA";
	element[4] = "F";
	element[5] = "C";
	element[6] = NULL;
	return (element);
}

char	*copy_witout(char *string)
{
	t_pars	elems;
	char	*allocation;

	elems.index = 2;
	elems.incre= 0;
	allocation = gb(sizeof(char) + (le_count(string) + 1), 2);
	while (string[elems.index] == ' ' || string[elems.index] == '\t')
		elems.index++ ;
	while (string[elems.index])
	{
		if (string[elems.index] == ' ' || string[elems.index] == '\t')
			break ;
		allocation[elems.incre] = string[elems.index];
		elems.index++ ;
		elems.incre++ ;
	}
	allocation[elems.incre] = '\0';
	return (allocation);
}

void	function_fill(char *string, int flag, t_store *store, char **twode)
{
	int	index;
	index = 0;
	while (string[index] && (string[index] == ' ' || string[index] == '\t'))
		index++ ;
	if (flag == 0)
		store->no = copy_witout(&string[index]);
	if (flag == 1)
		store->so = copy_witout(&string[index]);
	if (flag == 2)
		store->we = copy_witout(&string[index]);
	if (flag == 3)
		store->ea = copy_witout(&string[index]);
	if (flag == 4)
	{
		check_rgb_colors(twode, store);
	}
	if (flag == 5)
	{
		check_rgb_colors(twode, store);
	}
	
}

void function_fill_to_check(t_store *store, char **elemet, char *string, char **twode)
{
	t_pars lem;

	lem.index = 0;
	lem.incre = 0;
	
	while (elemet[lem.index] && lem.index <= 6)
	{
		if (elemet[lem.index][0] == string[lem.incre] && lem.index < 4)
		{
			lem.incre++ ;
			if (elemet[lem.index][1] == string[lem.incre] && \
			(string[lem.incre + 1] == ' ' || string[lem.incre + 1] == '\t'))
			{
				function_fill(string, lem.index, store, twode);
				return ;
			}
		}
		else if (lem.index >= 4)
		{
			lem.incre = 0;
			if (elemet[lem.index][0] == string[lem.incre] && \
			(string[lem.incre + 1] == ' ' || string[lem.incre + 1] == '\t'))
			{
				function_fill(string, lem.index, store, twode);
				return ;
			}
		}
		lem.index++ ;
	}
}

int	check_directions(char **twode, t_store *store)
{
	t_pars	elems;
	char	**element;

	elems.index = 0;
	elems.increment = 0;
	element = initial_it();
	while (twode[elems.index])
	{
		while (twode[elems.index][elems.increment] && \
		(twode[elems.index][elems.increment] == ' ' || \
		twode[elems.index][elems.increment] == '\t'))
			elems.increment++ ;
		function_fill_to_check(store, element, &twode[elems.index][elems.increment], twode);
		elems.increment = 0;
		elems.index++ ;
		if (elems.index == 6)
			break;
	}
	elems.increment = 0;
	while (twode[elems.index] && twode[elems.index][elems.increment] && \
	(twode[elems.index][elems.increment] == ' ' || twode[elems.index][elems.increment] == '\t'))
	 	elems.increment++ ;
	while (twode[elems.index] && twode[elems.index][elems.increment])
	{
		if (twode[elems.index][elems.increment] != '1' && \
		(twode[elems.index][elems.increment] != ' ' && twode[elems.index][elems.increment] != '\t'))
			exit_message("Map Not Valid \n");
		elems.increment++ ;
	}
	return (-1);
}