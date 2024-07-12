/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/12 12:58:35 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int ft_color(int r, int g, int b, int a)
{
    return ((((r * 256 + g) * 256) + b) * 256 + a);
}

unsigned int	ft_texture_color(unsigned int c)
{
	int a = c % (int)pow(2, 8);
	c = c / (int)pow(2, 8);
	int b = c % (int)pow(2, 8);
	c = c / (int)pow(2, 8);
	int g = c % (int)pow(2, 8);
	int r = c / (int)pow(2, 8);
	return (ft_color(a, b, g, r));
}

// unsigned int	ft_texture_color(unsigned int c)
// {
// 	unsigned int	b;

// 	b = 0;
// 	b |= (c & 0xFF) << 24;
// 	b |= (c & 0xFF00) << 8;
// 	b |= (c & 0xFF0000) >> 8;
// 	b |= (c & 0xFF000000) >> 24;
// 	return (b);
// }

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
