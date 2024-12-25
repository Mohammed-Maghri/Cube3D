/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/29 19:51:43 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	count_lenght(void **array)
{
	int	index ;

	index = 0;
	if (!array)
		return (0);
	while (array[index])
		index++ ;
	return (index);
}

void	**garbege_array_fill(void **array, void *add)
{
	int		index ;
	void	**twode;

	index = 0;
	twode = malloc(sizeof(void *) * (count_lenght(array)+ 2));
	if (!twode)
		exit(1);
	while (array && array[index])
	{
		twode[index] = array[index];
		index++;
	}
	twode[index] = add;
	index++;
	twode[index] = NULL;
	free(array);
	return (twode);
}

void	free_gb(void **array)
{
	free(array);
}

void	*gb(int size, int flag)
{
	static void	**array;
	static void	**free_to_use;
	void		*add;

	if (flag == 1)
	{
		add = malloc(size);
		if (!add)
			exit(1);
		array = garbege_array_fill(array, add);
	}
	if (flag == 2)
	{
		add = malloc(size);
		if (!add)
			exit(1);
		free_to_use = garbege_array_fill(free_to_use, add);
	}
	if (flag == 3)
	{
		free_gb(array);
		free_gb(free_to_use);
	}
	return (add);
}
