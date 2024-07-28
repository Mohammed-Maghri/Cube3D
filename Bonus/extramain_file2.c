/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extramain_file2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:36:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/28 15:44:13 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	position_recheck(char **array)
{
	t_pars	this;

	while (array[this.index])
	{
		while (array[this.index][this.incre])
		{
			if (array[this.index][this.incre] == 'S' || \
			array[this.index][this.incre] == 'N' \
			|| array[this.index][this.incre] == 'W' || \
			array[this.index][this.incre] == 'E' \
			|| array[this.index][this.incre] == 'D')
			{
				if (turnfunction(array, this.index, this.incre) == -1)
					return (-1);
			}
			this.incre++;
		}
		this.incre = 0;
		this.index++ ;
	}
	return (0);
}

void	function_position_check(char **array, t_store *elemes, char **other)
{
	t_pars	this;
	int		flag ;

	initializetwo(&flag, &this.index);
	while (array[this.index])
	{
		check_weird_ithem(array[this.index]);
		if (get_position(elemes, array[this.index]))
		{
			if (flag == 1)
			{
				printf("Duplicate Destination's\n");
				exit(1);
			}
			flag = 1;
			elemes->y = this.index;
		}
		this.index++ ;
	}
	array = heal_map(other, '-');
	if (position_recheck(array) == -1)
	{
		printf("Not a Valid Element \n");
		exit(1);
	}
}

void	funtion_for_main(t_pars *map, t_store *store)
{
	char	**that;
	char	**other ;

	that = for_main(map);
	store->no = copy_move("*");
	store->ea = copy_move("*");
	store->so = copy_move("*");
	store->we = copy_move("*");
	ini_tila(store, 1);
	check_directions(that, store);
	check_on_element(store);
	ini_tila(store, 0);
	other = rebuild_map(map->get_map);
	func_checks(other);
	map->array = heal_map(other, '-');
	search_for_dor(map->array, map);
	check_inside_map(map->array);
	function_check_inside(map->array);
	free(map->array);
	map->array = heal_map(other, '1');
	function_position_check(map->array, store, other);
	if (store->player_position == -1)
		exit_message("No destination \n");
}

void	merge_all_functions(t_pars *map, t_store	*store)
{
	store->player_position = -1;
	funtion_for_main(map, store);
	bothwalls(map->array);
	check_side_walls(map->array);
	// prin_map(map->array);
	gb(0, -1);
}
