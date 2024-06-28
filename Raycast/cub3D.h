/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:27:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/06/28 17:21:35 by cmasnaou         ###   ########.fr       */
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
# define WINDOW_WIDTH   (50 * TSIZE)
# define WINDOW_HEIGHT  (30 * TSIZE)
// # define WINDOW_WIDTH   1800
// # define WINDOW_HEIGHT  1000
# define MAP_WIDTH      25
# define MAP_HEIGHT     9
# define PLAYER_SPEED   2
# define ROTATION_SPEED 0.02
# define FLOOR_COLOR    0x90EE90FF
# define CEILING_COLOR  0xB0E2FFFF
# define WALL_COLOR     0xFFFFFFFF
# define WALL_SHADE     0xEEEEEEFF
# define FOV            (60 * M_PI / 180)
# define ANGLE_STEP     (FOV / WINDOW_WIDTH)
// Projection Plan
# define HEIGHT_CENTER  (WINDOW_HEIGHT / 2)
# define WIDTH_CENTER   (WINDOW_WIDTH / 2)
# define DISTANCE_PLAN  (WIDTH_CENTER / tan(FOV / 2))

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
    double      angle;
    int         rotation_flag;
    int         left_right_flag;   
    int         up_down_flag;   
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
}   t_map;

typedef struct s_mlx
{
    void        *pointer;
    // void        *window;
    void        *image;
    char        *buffer;
    int         bits_per_pixel;
    int         size_line;
    int         endian;
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

/*************** PLAYER *************/
void	ft_rotate_player(t_player *player);
void    ft_update_position(t_player *player, t_coordinate *move);
void	ft_move_player(t_data *data, t_coordinate move);
void    ft_update_window(void *d);

/*************** KEY_MOVE *************/
void    ft_key_move(mlx_key_data_t keydata, void *d);
void    ft_key_release(mlx_key_data_t keydata, t_data *data);
void    ft_key_press(mlx_key_data_t keydata, t_data *data);

/*************** RAY_CAST *************/
void    ft_cast_rays(t_data *data);
double	ft_vertical_intersect(t_data *data);
double	ft_horizont_intersect(t_data *data);

/**************** UTILS ***************/
double  ft_distance(t_coordinate a, t_position b);
void    ft_normalize(t_data *data);
int     ft_wall(t_map *map, int x, int y);

#endif