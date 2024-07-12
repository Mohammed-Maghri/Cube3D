/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/11 11:38:53 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	leacks_it(void)
{
	system("leaks Cub3d");
}

char	**for_main(t_pars *map)
{
	map->map = NULL;
	map->buf = NULL;
	function_open_map("maps/map.cub", map);
	map->get_map = moveto_array(map->map);
	return (move_only_content(moveto_array(map->map)));
}

void	check_on_element(t_store *store)
{
	if (store->no[0] == '*')
		putstring("NO Textures Are Not Available ..! \n");
	if (store->so[0] == '*')
		putstring("SO Textures Are Not Available ..! \n");
	if (store->we[0] == '*')
		putstring("WE Textures Are Not Available ..! \n");
	if (store->ea[0] == '*')
		putstring("EA Textures Are Not Available ..! \n");
}

void	check_tb(t_store *store)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		if (store->f[index] == -1)
		{
			putstring("RGB'S Are Not Valid ...!\n");
			exit(1);
		}
		index++ ;
	}
	index = 0;
	while (index < 3)
	{
		if (store->c[index] == -1)
		{
			putstring("RGB'S Are Not Valid ...!\n");
			exit(1);
		}
		index++ ;
	}
}

void	ini_tila(t_store *store, int flag)
{
	if (flag == 1)
	{
		store->c = gb(sizeof(int) * 3, 1);
		store->f = gb(sizeof(int) * 3, 1);
		store->c[0] = -1;
		store->c[1] = -1;
		store->c[2] = -1;
		store->f[0] = -1;
		store->f[1] = -1;
		store->f[2] = -1;
	}
	if (flag == 0)
		check_tb(store);
}

void func_checks(char **twode)
{
	int index;

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
char **heal_map(char **twode, char pass)
{
	int index;
	char **alloca;

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

int check_next(char *string)
{
	int index ;
	index = 0;
	while (string[index])
	{
		if (string[index] != '-')
			return (0);
		index++ ;
	}
	return (-1);
}
void function_check_inside(char **twode)
{
	t_pars this;
	int flag ;

	flag = 0;
	this.index = 0;
	while (twode[this.index])
	{
		if (flag == 1 && check_next(twode[this.index]) == -1)
		{
			flag = -1;
		}
		if (check_next(twode[this.index]) == 0)
		{
			if (flag == -1)
			{
				printf("Not a valid Map \n");
				exit(1);
			}
			flag = 1;
		}
		this.index++ ;
	}
}



void prin_map(char **twode)
{
	int index;

	index = 0;
	while (twode[index])
	{
		putstring(twode[index]);
		paste('\n');
		index++ ;
	}
}

void print_store(t_store *store)
{
	int index ;
	index = 0;
	while (index < 3)
	{
		printf("C = %d    | F = %d \n", store->c[index], store->f[index]);
		index++ ;
	}
	printf(" ------------------ \n\n");
	printf("[%s]\n", store->no);
	printf("[%s]\n", store->so);
	printf("[%s]\n", store->we);
	printf("[%s]\n", store->ea);

}

int check_ele(char string)
{
	if (string == '0' || string == '1' || \
	string == 'W' || string == 'N' \
	|| string == 'S' || string == 'E' || string == 'D')
		return (-1);
	return (0);
}
void check_weird_ithem(char *string)
{
	int index ;

	index = 0;
	while (string[index])
	{
		if (check_ele(string[index]) == 0)
		{
			printf("Wierd Ithem \n");
			exit(1);
		}
		index++ ;
	}
}

void initial_this(char current, t_store *elemes)
{
	if (current == 'N')
		elemes->player_position = 3 * M_PI / 2;
	if (current == 'S')
		elemes->player_position = M_PI / 2;;
	if (current == 'E')
		elemes->player_position = 0;
	if (current == 'W')
		elemes->player_position = M_PI;
}

int get_position(t_store *elemes, char *array)
{
	t_pars this;
	int flag ;

	flag = 0;
	this.index = 0;
	while (array[this.index])
	{
		if (array[this.index] == 'S' || \
		array[this.index]== 'E' || \
		array[this.index]== 'N' || 
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

int position_recheck(char **array)
{
	t_pars this;

	while (array[this.index])
	{
		while (array[this.index][this.incre])
		{
			if (array[this.index][this.incre] == 'S' || array[this.index][this.incre] == 'N'  
			|| array[this.index][this.incre] == 'W' || array[this.index][this.incre] == 'E' || array[this.index][this.incre] == 'D')
			{
				if (array[this.index][this.incre + 1] == '-')
					return (-1);
				if (array[this.index][this.incre - 1] == '-')
					return (-1);
				if (array[this.index][this.incre] == '-')
					return (-1);
				if (array[this.index][this.incre + 1] == '-')
					return (-1);
			}
			this.incre++;
		}
		this.incre = 0;
		this.index++ ;
	}
	return (0);
}

void function_position_check(char **array, t_store *elemes, char **other)
{
	t_pars this;
	int flag ;

	flag = 0;
	this.index = 0;
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
				elemes->y = this.index ; 
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

void funtion_for_main(t_pars *map, t_store *store)
{
	char	**that;
	int		index ;
	char	**other ;
	index = 0;
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
	index = 0;
	func_checks(other);
	map->array = heal_map(other, '-');
	check_inside_map(map->array);
	function_check_inside(map->array);
	free(map->array);
	map->array = heal_map(other, '1');
	function_position_check(map->array, store, other);
	if (store->player_position == -1)
	{
		printf("No Destinaion \n");
		exit(1);
	}
}
void merge_all_functions(t_pars *map, t_store	*store)
{
	store->player_position = -1;
	funtion_for_main(map, store);
	bothwalls(map->array);
	check_side_walls(map->array);
	prin_map(map->array);
	print_store(store);
	gb(0, -1);
}

