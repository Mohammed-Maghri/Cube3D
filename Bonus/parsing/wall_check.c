/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:10:31 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/29 19:56:11 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	exit_message(char *string)
{
	putstring(string);
	exit(1);
}

void	checkfortheinside(char **twode, int *index, int *incre)
{
	if (twode[*index - 1][*incre] == '-' || \
	twode[*index + 1][*incre] == '-')
		exit_message("Ooops  Not a Valid Map ... ! \n");
	if (twode[*index][*incre + 1] && \
	(twode[*index][*incre + 1] == '-' \
	|| twode[*index][*incre - 1] == '-'))
		exit_message("Ooops  Not a Valid Map ... ! \n");
}

int	check(char cara)
{
	if (cara == 'N' || cara == 'S' || cara == 'W' || cara == 'E' || cara == 'D')
		return (-1);
	return (0);
}

void	check_inside_map(char **twode)
{
	t_pars	le;

	le.index = 0;
	le.incre = 0;
	while (twode[le.index])
	{
		if (twode[le.index] != 0 && \
			le.index != (count_twode_arr(twode) - 1))
		{
			while (twode[le.index][le.incre])
			{
				if (twode[le.index][le.incre] == '0' || \
				check(twode[le.index][le.incre]) == -1)
				{
					checkfortheinside(twode, &le.index, &le.incre);
				}
				le.incre++ ;
			}
			le.incre = 0;
		}
		le.index++ ;
	}
}

int	get_last_wall_position(char **twode)
{
	int	index;
	int	incre;

	incre = 0;
	index = 0;
	while (twode[index])
	{
		while (twode[index][incre])
		{
			if (twode[index][incre] != '-')
				break ;
			incre++ ;
		}
		if (incre == le_count(twode[index]))
			return (index);
		incre = 0;
		index++ ;
	}
	return (-1);
}
