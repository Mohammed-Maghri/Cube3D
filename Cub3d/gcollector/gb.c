/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:07 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 20:50:12 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		return (NULL);
	while (array && array[index])
	{
		twode[index] = array[index];
		index++ ;
	}
	twode[index] = add;
	index++ ;
	twode[index] = NULL ;
	free(array);
	return (twode);
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
			return (NULL);
		array = garbege_array_fill(array, add);
	}
	if (flag == 2)
	{
		add = malloc(size);
		if (!add)
			return (NULL);
		free_to_use = garbege_array_fill(free_to_use, add);
	}
	return (add);
}
