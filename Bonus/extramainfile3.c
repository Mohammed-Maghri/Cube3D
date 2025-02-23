/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extramainfile3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:40:19 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 14:43:20 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	func_checks(char **twode)
{
	int	index;

	index = 0;
	while (twode && twode[index])
	{
		if (function_check_ithems(twode[index]) == -1)
		{
			putstring("Invalid Map ...!\n");
			exit(1);
		}
		check_on(twode[index]);
		index++ ;
	}
}

char	**heal_map(char **twode, char pass)
{
	int		index;
	char	**alloca;

	alloca = gb((sizeof(char *) * (count_twode_arr(twode) + 1)), 1);
	index = 0;
	while (twode && twode[index])
	{
		alloca[index] = heal_line(twode[index], get_longest_line(twode), pass);
		index++ ;
	}
	alloca[index] = NULL ;
	return (alloca);
}

int	check_next(char *string)
{
	int	index ;

	index = 0;
	while (string[index])
	{
		if (string[index] != '-')
			return (0);
		index++ ;
	}
	return (-1);
}
