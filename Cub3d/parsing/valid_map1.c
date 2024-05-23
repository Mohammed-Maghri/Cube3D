/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:07:18 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 18:58:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void keep_check(long number)
{
    if (number > 250 || number < 0)
    {
        putstring("RGB'S Are Not Valid .. !\n");
        exit(1);
    }
}

int check_valid_cara(char string)
{
    if (string >= '0' && string <= '9')
        return (1);
    return (0);
}
int check_nonumbers(char *string)
{
    int index;

    index = 0;
    while (string[index])
    {
        if (check_valid_cara(string[index]) == 1)
            return (0);
        index++ ;
    }
    return (-1);
}
int number_conv(char *string)
{
    long long res ;
    int index ;

    res = 0;
    index = 0;

    while (string[index] == ' ' || (string[index] >= 9 && string[index] <= 13))
        index++ ;
    if (check_nonumbers(&string[index]) == -1)
        return (-1);
    while (string[index] && string[index] >= '0' && string[index] <= '9')
        {
            res = (res * 10 + (string[index] - '0'));
            keep_check(res);
            index++ ;
        }
    return (res);
}

char *string_copy_from_till(char *string, int start, int stop)
{
    int index ;
    char *alloc ;

    index = 0;
    alloc = gb(sizeof(char) + le_count(string) + 1, 2);
    while (start < stop)
    {
        alloc[index] = string[start];
        start++ ;
        index++ ;
    }
    alloc[index] = '\0';
    return (alloc);
}

void initail_it(t_store *store, int number, int index, int ff)
{
    if (ff == 0)
        store->f[index] = number;
    if (ff == 1)
        store->c[index] = number;
}
int *table(char *string, t_store *store, int ff)
{
    t_pars ad;

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
                store->f[ad.incre] = number_conv(string_copy_from_till(string, ad.flag, ad.index));
            if (ff == 1)
                store->c[ad.incre] = number_conv(string_copy_from_till(string, ad.flag, ad.index));
            ad.incre++ ;
        }
        ad.flag = ad.pause + 1;
        ad.index++ ;
    }
    initail_it(store, number_conv(string_copy_from_till(string, ad.flag, le_count(string))) , ad.incre, ff);
    ad.incre++ ;
    return NULL;
}
void check_rgbs(t_store *store, char *string, int flag)
{
    table(string, store, flag);
}
void check_rgb_colors(char **twode, t_store *store)
{
    t_pars rb;
    char *both;

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
        if (twode[rb.index][rb.increment] == both[1] && rb.index == 5 &&  \
        (twode[rb.index][rb.increment + 1] == ' ' || \
        twode[rb.index][rb.increment + 1] == '\t'))
            {
                rb.increment++ ;
                check_rgbs(store, &twode[rb.index][rb.increment], 1);
            }
        rb.increment = 0;
        if (rb.index == 5)
            break;
        rb.index++;
    }
}
