/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:09:29 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/24 14:11:09 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	le_count(char *string)
{
	int	index ;

	index = 0;
	if (!string)
		return (0);
	while (string && string[index] != '\0')
		index++ ;
	return (index);
}

void	paste(char string)
{
	write(1, &string, 1);
}

char	*caracter_turn(char *string, char copy)
{
	t_pars	this;
	char	*turn ;

	this.index = 0;
	this.increment = 0;
	turn = gb(((le_count(string) + 2)), 1);
	if (!turn)
		return (NULL);
	while (string && string[this.index])
	{
		turn[this.index] = string[this.index];
		this.index++ ;
	}
	turn[this.index] = copy;
	this.index++ ;
	turn[this.index] = '\0';
	return (turn);
}

char	*string_turn(char *string, char *copy)
{
	t_pars	this;
	char	*turn ;

	this.index = 0;
	this.increment = 0;
	turn = gb(le_count(string) + le_count(copy) + 1, 1);
	if (!turn)
		return (NULL);
	while (string && string[this.index])
	{
		turn[this.index] = string[this.index];
		this.index++ ;
	}
	while (copy[this.increment])
	{
		turn[this.index] = copy[this.increment];
		this.index++ ;
		this.increment++ ;
	}
	turn[this.index] = '\0';
	free(string);
	return (turn);
}

void	putstring(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		paste(string[index]);
		index++ ;
	}
}

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
	t_pars	elems;

	elems.index = 0;
	elems.increment = 0;
	if (!string)
		return (NULL);
	elems.array = gb(sizeof(char *) * (count_how_may(string, '\n') + 2), 2);
	while (string[elems.index])
	{
		elems.array[elems.increment] = " ";
		while (copy(string[elems.index], '\n') != -1 && string[elems.index + 1])
		{
			elems.array[elems.increment] = \
			caracter_turn(elems.array[elems.increment], string[elems.index]);
			elems.index++ ;
		}
		elems.increment++ ;
		elems.index++;
	}
	elems.array[elems.increment] = NULL;
	return (elems.array);
}