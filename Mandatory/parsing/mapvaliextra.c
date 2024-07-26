/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvaliextra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:08:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/23 15:07:38 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	functoin_variableinitial(int *index, int *flag, int *incre, int *pause)
{
	*index = 0;
	*incre = 0;
	*flag = 0;
	*pause = 0;
}

int	*table(char *string, t_store *store, int ff)
{
	t_pars	ad;

	functoin_variableinitial(&ad.index, &ad.flag, &ad.incre, &ad.pause);
	while (string[ad.index])
	{
		if (string[ad.index] == ',')
		{
			ad.pause = ad.index ;
			if (ff == 0)
				store->f[ad.incre] = number_conv(string_copy_from_till(string, \
				ad.flag, ad.index));
			if (ff == 1)
				store->c[ad.incre] = number_conv(string_copy_from_till(string, \
				ad.flag, ad.index));
			ad.incre++ ;
		}
		ad.flag = ad.pause + 1;
		ad.index++ ;
	}
	initail_it(store, number_conv(string_copy_from_till(string, ad.flag, \
	le_count(string))), ad.incre, ff);
	ad.incre++ ;
	return (NULL);
}

void	check_rgbs(t_store *store, char *string, int flag)
{
	if (check_numbers(string) == -1)
	{
		putstring("invelid Element ... !\n");
		exit(1);
	}
	table(string, store, flag);
}

void	addonemorethen(int *increment, int *index, char **twode, t_store *store)
{
	*increment = *increment;
	if (twode[*index][*increment] == 'F' && \
	(twode[*index][*increment + 1] == ' ' || \
	twode[*index][*increment + 1] == '\t'))
	{
		*increment += 1;
		check_rgbs(store, &twode[*index][*increment], 0);
	}
}

void	check_rgb_colors(char **twode, t_store *store)
{
	t_pars	rb;

	rb.index = 0;
	rb.increment = 0;
	while (twode[rb.index])
	{
		while (twode[rb.index][rb.increment] == ' ' \
		|| twode[rb.index][rb.increment] == '\t')
			rb.increment++ ;
		addonemorethen(&rb.increment, &rb.index, twode, store);
		if (twode[rb.index][rb.increment] == 'C' && \
		(twode[rb.index][rb.increment + 1] == ' ' || \
		twode[rb.index][rb.increment + 1] == '\t'))
		{
			rb.increment++ ;
			check_rgbs(store, &twode[rb.index][rb.increment], 1);
		}
		rb.increment = 0;
		if (rb.index == 6)
			break ;
		rb.index++;
	}
}
