/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:43:00 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:06:16 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	function_check_ithems(char *string)
{
	int	index;

	index = 0;
	if (le_count(string) == 0)
		return (-1);
	while (string[index])
	{
		if ((string[index] != ' ' && string[index] != '\t') \
		|| string[index] != '\0')
			return (0);
		index++ ;
	}
	return (-1);
}

int	function_check_ithem(char *string)
{
	int	index;

	index = 0;
	if (le_count(string) == 1 || le_count(string) == 0)
		return (-1);
	while (string[index])
	{
		if ((string[index] != ' ' && string[index] != '\t') \
		|| string[index] != '\0')
			return (0);
		index++ ;
	}
	return (-1);
}

int	count_twode_arr(char **array)
{
	int	index;

	index = 0;
	if (!array)
		return (0);
	while (array[index])
		index++ ;
	return (index);
}

char	**move_only_content(char **twode)
{
	t_pars	ele;

	ele.index = 0;
	ele.increment = 0;
	ele.array = gb(sizeof(char *) * (count_twode_arr(twode) + 1), 2);
	if (!ele.array)
		return (NULL);
	while (twode && twode[ele.index])
	{
		if (function_check_ithem(twode[ele.index]) == 0)
		{
			ele.array[ele.increment] = twode[ele.index];
			ele.increment++ ;
		}
		ele.index++ ;
	}
	ele.array[ele.increment] = NULL;
	return (ele.array);
}
