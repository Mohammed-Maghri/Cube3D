/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/24 14:20:57 by mmaghri          ###   ########.fr       */
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
		printf("%d\n", store->f[index]);
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
		printf("%d\n", store->c[index]);
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

int	main()
{
	t_pars	*map;
	t_store	*store;
	char	**that;

	map = NULL;
	store = NULL;
	// atexit(leacks_it);
	map = gb(sizeof(t_pars), 1);
	int index ;
	index = 0;
	that = for_main(map);
	store = gb(sizeof(t_store), 1);
	store->no = copy_move("*");
	store->ea = copy_move("*");
	store->so = copy_move("*");
	store->we = copy_move("*");
	check_directions(that, store);
	check_on_element(store);
	ini_tila(store, 1);
	check_rgb_colors(that, store);
	ini_tila(store, 0);
	// rebuild_map(map->map);
	gb(0, -1);
}
