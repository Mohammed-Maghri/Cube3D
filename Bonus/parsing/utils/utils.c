/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:09:29 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:03:31 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

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
