/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:27:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/04 17:58:42 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./MLX42/MLX42.h"

# define TSIZE      32
# define MSIZE      22
// # define MSIZE      (0.02 * WINDOW_HEIGHT)
# define UNITY      ((double)MSIZE / TSIZE)
# define WINDOW_HEIGHT  (30 * TSIZE)
# define WINDOW_WIDTH   (50 * TSIZE)
# define MINI_HEIGHT  (WINDOW_HEIGHT / 4)
# define MINI_WIDTH   (WINDOW_WIDTH / 4)
// # define WINDOW_WIDTH   1800
// # define WINDOW_HEIGHT  1000
// # define MAP_WIDTH      59
// # define MAP_HEIGHT     22
# define MAP_WIDTH      25
# define MAP_HEIGHT     9
# define PLAYER_SPEED   2 // 2 pixels
// # define ROTATION_SPEED 0.02
# define ROTATION_SPEED (M_PI / 180) // 1 degree
# define FLOOR_COLOR    0x90EE90FF
// # define MINI_COLOR     0xAAAAAAFF
# define MINI_COLOR     0xAAAAAA00
# define CEILING_COLOR  0xB0E2FFFF
# define WALL_COLOR     0xFFFFFFFF
# define WALL_SHADE     0xEEEEEEFF
# define FOV            (M_PI / 3) // 60 degree
// # define FOV            (60 * M_PI / 180)
# define ANGLE_STEP     (FOV / WINDOW_WIDTH)
// Projection Plan
# define HALF_HEIGHT  (WINDOW_HEIGHT / 2)
# define HALF_WIDTH   (WINDOW_WIDTH / 2)
# define DISTANCE_PLAN  ((double)TSIZE * HALF_WIDTH / tan(FOV / 2))
# define ESC            256
# define R              262
# define L              263

typedef struct s_position
{
    int x;
    int y;
}   t_position;

typedef struct s_coordinate
{
    double x;
    double y;
}   t_coordinate;

typedef struct s_player
{
    t_position  pos_in_map;
    t_position  pos_in_pixels;
    t_coordinate    move;
    double      angle;
    int         rotation;
    int         left_right;   
    int         up_down;   
}   t_player;

typedef struct s_ray
{
	int		    index;
	int		    color;
    int         down;
    int         up;
    int         left;
    int         right;
    double      angle;
    double	    start;
    double      distance;
}   t_ray;

typedef struct s_map
{
    char        **map;
    int         map_width;
    int         map_height;
    int         mini_width;
    int         mini_height;
}   t_map;

typedef struct s_mlx
{
    void        *pointer;
    void        *image;
}   t_mlx;

typedef struct s_data
{
    t_mlx       *mlx;
    t_map       *map;
    t_ray       *ray;
    t_player    *player;
}   t_data;

/**************** LIBFT **************/
int     ft_strlen(char *s);
void	*ft_calloc(int count, int size);
char	*ft_strdup(char *s);

/*************** INIT *************/
void    ft_init_map(t_data *data);
void    ft_init_player(t_data *data);
void    ft_init_data(t_data **data);
void    ft_init(t_data *data);
void	ft_close(t_data *data);

/**************** MLX **************/
void    ft_init_mlx(t_data *data);
void    ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color);
void    ft_key_move(mlx_key_data_t keydata, void *d);

/*************** MOVE *************/

void	ft_move_player(t_data *data);
void    ft_update_window(void *d);

/*************** RAY_CAST *************/
void    ft_cast_rays(t_data *data);
double	ft_hdistance(t_data *data);
double	ft_vdistance(t_data *data);
void    ft_normalize(t_data *data);

/**************** DRAW ***************/
void ft_draw_minimap(t_data *data);
void ft_draw_ray(t_data *data);
void ft_draw_player(t_data *data);
int ft_wall(t_map *map, int x, int y);
// unsigned long color(int r, int g, int b, int a);
#endif