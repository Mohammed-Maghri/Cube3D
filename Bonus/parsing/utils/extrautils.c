/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrautils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammdmaghri <mohammdmaghri@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:53:16 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/24 11:07:48 by mohammdmagh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	copy(char check, char being_check)
{
	if (check == being_check)
		return (-1);
	return (0);
}

int	count_how_may(char *string, char srach_for)
{
	int	index;
	int	flag;

	flag = 0;
	index = 0;
	if (!string)
		return (0);
	while (string[index])
	{
		if (string[index] == srach_for)
			flag++ ;
		index++ ;
	}
	return (flag);
}

char	*copy_move(char *string)
{
	t_pars	elems;
	char	*allocation;

	elems.index = 0;
	allocation = gb(sizeof(char) + (le_count(string) + 1), 2);
	while (string[elems.index])
	{
		allocation[elems.index] = string[elems.index];
		elems.index++ ;
	}
	allocation[elems.index] = '\0';
	return (allocation);
}

char	**moveto_array(char *string)
{
	t_pars	e;

	e.index = 0;
	e.increment = 0;
	if (!string)
		return (NULL);
	e.array = gb(sizeof(char *) * (count_how_may(string, '\n') + 2), 2);
	while (string[e.index])
	{
		e.array[e.increment] = " ";
		while (copy(string[e.index], '\n') != -1 && string[e.index + 1])
		{
			e.array[e.increment] = \
			caracter_turn(e.array[e.increment], string[e.index]);
			e.index++ ;
		}
		if (string[e.index] != '\n')
			e.array[e.increment] = \
				caracter_turn(e.array[e.increment], \
				string[e.index]);
		e.increment++ ;
		e.index++;
	}
	e.array[e.increment] = NULL;
	return (e.array);
}
