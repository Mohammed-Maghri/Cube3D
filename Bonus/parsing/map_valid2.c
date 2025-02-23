/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:04:35 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:03:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	initail_it(t_store *store, int number, int index, int ff)
{
	if (ff == 0)
		store->f[index] = number;
	if (ff == 1)
		store->c[index] = number;
}

int	function_check(char string)
{
	if (string == ' ' || string == '\t')
		return (-1);
	if (string >= 9 && string <= 13)
		return (-1);
	if (string >= '0' && string <= '9')
		return (-1);
	if (string == ',')
		return (-1);
	return (0);
}

int	check_numbers(char *string)
{
	int	index ;
	int	flag ;

	index = 0;
	flag = 0;
	while (string[index])
	{
		if (string[index] == ',')
			flag++ ;
		if (function_check(string[index]) == 0)
			return (-1);
		if (flag > 2)
		{
			putstring("Invalid argument ... !\n");
			exit(1);
		}
		index++ ;
	}
	return (0);
}
