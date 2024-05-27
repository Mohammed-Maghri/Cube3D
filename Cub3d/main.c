/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/26 21:28:58 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		store->f = gb(sizeof(int) * 3, 1); store->c[0] = -1;
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
char **heal_map(char **twode)
{
	int index;
	char **alloca;

	alloca = gb((sizeof(char *) * (count_twode_arr(twode) + 1)), 1);
	index = 0;
	while (twode && twode[index])
	{
		alloca[index] = heal_line(twode[index], get_longest_line(twode), '-');
		index++ ;
	}
	alloca[index] = NULL ;
	return (alloca);
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
	map->array = heal_map(other);
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

int	main()
{
	t_pars	*map;
	t_store	*store;
	map = gb(sizeof(t_pars), 1);
	store = gb(sizeof(t_store), 1);
	funtion_for_main(map, store);
	bothwalls(map->array);
	prin_map(map->array);
	check_side_walls(map->array);
	check_inside_map(map->array);
	count_players(map->array);
	print_store(store);
	create_window(map->array, store);
	gb(0, -1);
}
