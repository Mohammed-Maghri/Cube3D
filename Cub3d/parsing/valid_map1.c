/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:07:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 20:31:34 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	keep_check(long number)
{
	if (number > 250 || number < 0)
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

int	number_conv(char *string)
{
	long long	res ;
	int			index ;

	res = 0;
	index = 0;
	while (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
		index++ ;
	if (check_nonumbers(&string[index]) == -1)
		return (-1);
	while (string[index] && string[index] >= '0' && string[index] <= '9')
	{
		res = (res * 10 + (string[index] - '0'));
		keep_check(res);
		index++ ;
	}
	return (res);
}

char	*string_copy_from_till(char *string, int start, int stop)
{
	int		index ;
	char	*alloc ;

	index = 0;
	alloc = gb(sizeof(char) + le_count(string) + 1, 2);
	while (start < stop)
	{
		alloc[index] = string[start];
		start++ ;
		index++ ;
	}
	alloc[index] = '\0';
	return (alloc);
}
