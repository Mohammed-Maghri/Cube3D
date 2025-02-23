/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extramain_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:27:04 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/29 10:56:18 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initializetwo(int *var, int *var2)
{
	*var = 0;
	*var2 = 0;
}

int	get_position(t_store *elemes, char *array)
{
	t_pars	this;
	int		flag ;

	initializetwo(&this.index, &flag);
	while (array[this.index])
	{
		if (array[this.index] == 'S' || \
		array[this.index] == 'E' || \
		array[this.index] == 'N' || \
		array[this.index] == 'W')
		{
			if (flag == 1)
			{
				printf("Duplicate Destination's\n");
				exit(1);
			}
			elemes->x = this.index ;
			initial_this(array[this.index], elemes);
			flag = 1;
		}
		this.index++ ;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	turnfunction(char **array, int index, int incre)
{
	if (array[index][incre + 1] == '-')
		return (-1);
	if (array[index][incre - 1] == '-')
		return (-1);
	if (array[index - 1][incre] == '-')
		return (-1);
	if (array[index + 1][incre] == '-')
		return (-1);
	return (0);
}
