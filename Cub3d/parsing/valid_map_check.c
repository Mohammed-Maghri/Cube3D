/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:03:09 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 15:06:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **initial_it(void)
{
    char **element;

    element =  gb(sizeof(char *) * 7, 2);
    element[0] = "NO";
    element[1] = "SO";
    element[2] = "WE";
    element[3] = "EA";
    element[4] = "F";
    element[5] = "C";
    element[6] = NULL;
    return (element);
}

char *copy_witout(char *string)
{
    t_pars elems;
    char *allocation;

    elems.index = 0;
    allocation = gb(sizeof(char) + (le_count(string) + 1), 2);
    while (string[elems.index])
    {
        if (string[elems.index] == ' ' || string[elems.index] == '\t')
            break;
        allocation[elems.index] = string[elems.index];
        elems.index++ ;
    }
    allocation[elems.index] = '\0';
    return (allocation);
}
void function_fill(char *string, int flag, t_store *store)
{
    int index;

    index = 0;
    while (string[index] && (string[index] == ' ' || string[index] == '\t'))
        index++ ;
    if (flag == 0)
        store->no = copy_witout(&string[index]);
    if (flag == 1)
        store->so = copy_witout(&string[index]);
    if (flag == 2)
        store->we = copy_witout(&string[index]);
    if (flag == 3)
        store->ea = copy_witout(&string[index]);
}

int check_directions(char **twode, t_store *store)
{
    t_pars elems;
    char **element;

    elems.index = 0;
    elems.increment = 0;
    element = initial_it();
    while (twode[elems.index])
    {
        while (twode[elems.index][elems.increment] && \
        (twode[elems.index][elems.increment] == ' ' || \
        twode[elems.index][elems.increment] == '\t'))
            elems.increment++ ;
        if (element[elems.index][0] == twode[elems.index][elems.increment])
        {
            elems.increment++ ;
            if (element[elems.index][1] == twode[elems.index][elems.increment] \
            && (twode[elems.index][elems.increment + 1] == ' ' || twode[elems.index][elems.increment + 1] == '\t'))
            {
                elems.increment++ ;
                function_fill(&twode[elems.index][elems.increment],  elems.index, store);
            }
        }
        elems.increment = 0;
        elems.index++ ;
        if (elems.index == 4)
            return (0);
    }
    return (-1);
}
