/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:03:09 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:06:48 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**initial_it(void)
{
	char	**element;

	element = gb(sizeof(char *) * 7, 2);
	element[0] = "NO";
	element[1] = "SO";
	element[2] = "WE";
	element[3] = "EA";
	element[4] = "F";
	element[5] = "C";
	element[6] = NULL;
	return (element);
}

char	*copy_witout(char *string)
{
	t_pars	elems;
	char	*allocation;

	elems.index = 2;
	elems.incre = 0;
	allocation = gb(sizeof(char) + (le_count(string) + 1), 2);
	while (string[elems.index] == ' ' || string[elems.index] == '\t')
		elems.index++ ;
	while (string[elems.index])
	{
		allocation[elems.incre] = string[elems.index];
		elems.index++ ;
		elems.incre++ ;
	}
	allocation[elems.incre] = '\0';
	return (allocation);
}

void	function_fill(char *string, int flag, t_store *store, char **twode)
{
	int	index;

	index = 0;
	while (string[index] && (string[index] == ' ' || string[index] == '\t'))
		index++ ;
	if (flag == 0)
		store->no = copy_witout(&string[index]);
	if (flag == 1)
		store->so = copy_witout(&string[index]);
	if (flag == 2)
		store->we = copy_witout(&string[index]);
	if (flag == 3)
		store->ea = copy_witout(&string[index]);
	if (flag == 4)
		check_rgb_colors(twode, store);
	if (flag == 5)
		check_rgb_colors(twode, store);
}
