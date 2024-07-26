/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:37:37 by mohammdmagh       #+#    #+#             */
/*   Updated: 2024/07/26 07:18:27 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	search_for_dor(char **array, t_pars *map)
{
	int		index;
	int		increment;

	index = 0;
	increment = 0;
	while (array[index])
	{
		increment = 0;
		while (array[index][increment])
		{
			if (array[index][increment] == 'D')
			{
				map->row = index;
				map->col = increment;
				check_dor_position(map);
			}
			increment++;
		}
		index++;
	}
	return (-1);
}

void	ft_mouse_clic(mouse_key_t button, action_t action, \
modifier_key_t mods, void *d)
{
	t_data	*data;

	data = d;
	(void)mods;
	(void)action;
	if (button == 0)
		data->check_reload = 1;
}

int	check_dor_position(t_pars *map)
{
	if ((map->col + 1) <= le_count(map->array[map->row]) && \
	map->array[map->row][map->col + 1] == 'D')
		exit_message("Invalid map, door is not allowed \
		to be next to each other");
	if ((map->col - 1) >= 0 && map->array[map->row][map->col + 1] == 'D')
		exit_message("Invalid map, door is not allowed to \
		be next to each other");
	if ((map->row + 1) <= count_twode_arr(map->array) && \
	map->array[map->row + 1][map->col] == 'D')
		exit_message("Invalid map, door is not allowed to \
		be next to each other");
	if ((map->row - 1) >= 0 && map->array[map->row - 1][map->col] == 'D')
		exit_message("Invalid map, door is not allowed to \
		be next to each other");
	if ((map->col + 1) <= le_count(map->array[map->row]) && \
	map->array[map->row][map->col + 1] != '0' &&
		(map->col - 1) >= 0 && map->array[map->row][map->col - 1] != '0' && \
		(map->row + 1) <= count_twode_arr(map->array) && \
		map->array[map->row + 1][map->col] != '0' && \
		(map->row - 1) >= 0 && map->array[map->row - 1][map->col] != '0')
		exit_message("Invalid map, door is not allowed to\
			be next to each other");
	return (1);
}
