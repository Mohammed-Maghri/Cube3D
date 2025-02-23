/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extravalid_map_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:43:31 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:06:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	functionturneither(char **elemet, char *string, int *index, int *incre)
{
	if (elemet[*index][1] == string[*incre] && \
	(string[*incre + 1] == ' ' || string[*incre + 1] == '\t'))
		return (1);
	if (index >= (int *)4)
	{
		if (elemet[*index][0] == string[*incre] && \
		(string[*incre + 1] == ' ' || string[*incre + 1] == '\t'))
			return (2);
	}
	return (0);
}

void	function_fill_to_check(t_store *store, char **elemet, \
char *string, char **twode)
{
	t_pars	lem;

	lem.index = 0;
	lem.incre = 0;
	while (elemet[lem.index] && lem.index <= 6)
	{
		if (elemet[lem.index][0] == string[lem.incre] && lem.index < 4)
		{
			lem.incre++ ;
			if (functionturneither(elemet, string, &lem.index, &lem.incre) == 1)
			{
				function_fill(string, lem.index, store, twode);
				return ;
			}
		}
		if (functionturneither(elemet, string, &lem.index, &lem.incre) == 2)
		{
			function_fill(string, lem.index, store, twode);
			return ;
		}
		lem.index++ ;
	}
}

void	fnuctiocheckpass(char **twode, int index, int increment)
{
	while (twode[index] && twode[index][increment] && \
	(twode[index][increment] == ' ' || twode[index][increment] == '\t'))
		increment++ ;
	while (twode[index] && twode[index][increment])
	{
		if (twode[index][increment] != '1' && \
		(twode[index][increment] != ' ' && twode[index][increment] != '\t'))
			exit_message("Map Not Valid \n");
		increment++ ;
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
		function_fill_to_check(store, element, \
		&twode[elems.index][elems.increment], twode);
		elems.increment = 0;
		elems.index++ ;
		if (elems.index == 6)
			break ;
	}
	elems.increment = 0;
	fnuctiocheckpass(twode, elems.index, elems.increment);
	return (-1);
}
