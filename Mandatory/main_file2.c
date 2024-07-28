/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:48:49 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/28 11:47:04 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	function_check_inside(char **twode)
{
	t_pars	this;
	int		flag ;

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

void	prin_map(char **twode)
{
	int	index;

	index = 0;
	while (twode[index])
	{
		putstring(twode[index]);
		paste('\n');
		index++ ;
	}
}

int	check_ele(char string)
{
	if (string == '0' || string == '1' || \
	string == 'W' || string == 'N' \
	|| string == 'S' || string == 'E')
		return (-1);
	return (0);
}

void	check_weird_ithem(char *string)
{
	int	index ;

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

void	initial_this(char current, t_store *elemes)
{
	if (current == 'N')
		elemes->player_position = 3 * M_PI / 2;
	if (current == 'S')
		elemes->player_position = M_PI / 2;
	if (current == 'E')
		elemes->player_position = 0;
	if (current == 'W')
		elemes->player_position = M_PI;
}
