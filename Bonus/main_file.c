/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:38:48 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/28 14:13:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

char	**for_main(t_pars *map)
{
	map->map = NULL;
	map->buf = NULL;
	function_open_map(map->map_name, map);
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
