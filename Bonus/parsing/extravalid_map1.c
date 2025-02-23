/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extravalid_map1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:41:13 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/29 19:55:56 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

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

int	check_on_validiation(char *string)
{
	int	index ;
	int	flag;

	flag = 0;
	index = 0;
	while (string[index])
	{
		if (string[index] >= '0' && string[index] <= '9' && \
		(string[index + 1] == ' ' || string[index + 1] == '\t'))
			flag++ ;
		if ((string[index] == ' ' || string[index] == '\t') \
		&& (string[index + 1] >= '0' && string[index + 1] <= '9') && flag > 0)
		{
			putstring("Invalid Argument.... !");
			exit(1);
		}
		index++ ;
	}
	return (0);
}

char	*string_copy_from_till(char *string, int start, int stop)
{
	int		index ;
	char	*alloc ;

	index = 0;
	while (string[start] && (string[start] == ' ' || string[start] == '\t'))
		start++ ;
	alloc = gb(sizeof(char) + le_count(string) + 1, 2);
	while (start < stop)
	{
		alloc[index] = string[start];
		start++ ;
		index++ ;
	}
	alloc[index] = '\0';
	check_on_validiation(alloc);
	return (alloc);
}
