/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:38:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/03 16:57:42 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// unsigned long color(int r, int g, int b, int a)
// {   
//     return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
// }

void  ft_normalize(t_data *data)
{
    while (data->ray->angle < 0)
        data->ray->angle += 2 * M_PI;
    while (data->ray->angle  >= (2 * M_PI))
        data->ray->angle -= 2 * M_PI;
    data->ray->down = (data->ray->angle > 0 && data->ray->angle < M_PI);//up = 1 down = 0
	data->ray->left = (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * M_PI / 2);//left = 1 right = 0
    data->ray->up = !data->ray->down;
    data->ray->right = !data->ray->left;
}

void    ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color)
{
    if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
	    mlx_put_pixel(mlx->image, x, y, color);
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
