/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/07 14:27:09 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int ft_color(int r, int g, int b)
{   
    // return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (255 & 0xff);
    // return ((r * pow(2, 24) + g * pow(2, 16)) + b * pow(2, 8) + 255);
    return ((((r * 256 + g) * 256) + b) * 256 + 255);
}


int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strdup(char *s)
{
	char	*p;
	int 	n;
    int     i;
    
    i = -1;
	n = ft_strlen(s);
	p = (char *)malloc((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
    while (++i < n)
        p[i] = s[i];
    p[i] = '\0';
	return (p);
}
