/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:56:50 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/25 09:28:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void	*ft_calloc(int count, int size)
{
	void	*p;
    int     i;
    
    i = -1;
	if ((count < 0 && size) || (size < 0 && count))
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
    while (++i < count * size)
        *(unsigned char *)(p + i) = 0;
	return (p);
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
