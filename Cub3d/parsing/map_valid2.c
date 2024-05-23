/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:04:35 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 20:55:14 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initail_it(t_store *store, int number, int index, int ff)
{
	if (ff == 0)
		store->f[index] = number;
	if (ff == 1)
		store->c[index] = number;
}

int	*table(char *string, t_store *store, int ff)
{
	t_pars	ad;

	ad.index = 0;
	ad.flag = 0;
	ad.incre = 0;
	ad.pause = 0;
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
	table(string, store, flag);
}

void	check_rgb_colors(char **twode, t_store *store)
{
	t_pars	rb;
	char	*both;

	both = "FC";
	rb.index = 4;
	rb.increment = 0;
	while (twode[rb.index])
	{
		while (twode[rb.index][rb.increment] == ' ' \
		|| twode[rb.index][rb.increment] == '\t')
			rb.increment++ ;
		if (twode[rb.index][rb.increment] == both[0] && rb.index == 4 \
		&& (twode[rb.index][rb.increment + 1] == ' ' || \
		twode[rb.index][rb.increment + 1] == '\t'))
		{
			rb.increment++ ;
			check_rgbs(store, &twode[rb.index][rb.increment], 0);
		}
		if (twode[rb.index][rb.increment] == both[1] && rb.index == 5 && \
		(twode[rb.index][rb.increment + 1] == ' ' || \
		twode[rb.index][rb.increment + 1] == '\t'))
		{
			rb.increment++ ;
			check_rgbs(store, &twode[rb.index][rb.increment], 1);
		}
		rb.increment = 0;
		if (rb.index == 5)
			break ;
		rb.index++;
	}
}
