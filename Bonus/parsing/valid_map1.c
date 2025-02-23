/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:07:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:04:06 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	keep_check(long number)
{
	if (number > 255 || number < 0)
	{
		putstring("RGB'S Are Not Valid .. !\n");
		exit(1);
	}
}

int	check_valid_cara(char string)
{
	if (string >= '0' && string <= '9')
		return (1);
	return (0);
}

int	check_nonumbers(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (check_valid_cara(string[index]) == 1)
			return (0);
		index++ ;
	}
	return (-1);
}
