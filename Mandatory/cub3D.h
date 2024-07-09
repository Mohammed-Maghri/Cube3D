/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:27:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/07 17:24:27 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../MLX42/MLX42.h"
#include <fcntl.h>
#include <pthread.h>

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
# define MOUSE_SPEED    0.7
// # define ROTATION_SPEED 0.02
# define ROTATION_SPEED (M_PI / 180) // 1 degree
// # define FLOOR_COLOR    0x90EE90FF
// # define MINI_COLOR     0xAAAAAAFF
# define MINI_COLOR     0xAAAAAA00
// # define CEILING_COLOR  0xB0E2FFFF
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
    double      rotation;
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
    char        view;
    double      angle;
    double	    start;
    double      h_distance;
    double      v_distance;
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
    mlx_image_t *ima;
    t_ray       *ray;
    t_player    *player;
    unsigned int floor_color;
    unsigned int ceiling_color;
    mlx_texture_t	*wall;
    mlx_texture_t    *bonus2;
    mlx_texture_t    *reload;
    mlx_texture_t    *reload2;
    mlx_texture_t    *reload3;
    int         check_reload;
}   t_data;

typedef struct parsing
{
	int		index;
	int		increment ;
	char	*map;
	int		fd ;
	int		read_buf;
	char	*buf;
	char	**array;
	int		flag;
	int		incre;
	int		pause;
	char	**get_map;
}			t_pars;

typedef struct store_map_elem
{
    int     x;
    int     y;
	double	player_position;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**map;
	char    **array;
	void 	*mlx;
	void 	*win;
	void 	*imag;
	void	*data ;
	int		dat ;
    int		linelenght;
    int		endian ;
}	t_store;
/**************** LIBFT **************/
int     ft_strlen(char *s);
void	*ft_calloc(int count, int size);
char	*ft_strdup(char *s);

/*************** INIT *************/
void    ft_init_map(t_data *data);
void    ft_init_player(t_data *data, t_store *store);
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
// void    ft_mouse_move(mouse_key_t button, action_t action, modifier_key_t mods, void* d);
void    mlx_cursor_move(double xpos, double ypos, void* d);

/*************** RAY_CAST *************/
void    ft_cast_rays(t_data *data);
double	ft_hdistance(t_data *data);
double	ft_vdistance(t_data *data);
void    ft_normalize(t_data *data);
double  ft_distance(t_coordinate a, t_position b);

/**************** DRAW ***************/
void ft_draw_ray(t_data *data);
void ft_draw_minimap(t_data *data);
void ft_draw_miniplayer(t_data *data);
int ft_wall(t_map *map, int x, int y);
unsigned int ft_color(int r, int g, int b);



// typedef struct only_for_map
// {
// 	void *mlx_ptr;
// 	void *images;
// 	void *pic;
// 	void *direction;
// } t_map;
//Sound 
// Garbege Collector
int		count_lenght(void **array);
void	optins(void **array);
void	*gb(int size, int flag);
void	**garbege_array_fill(void **array, void *add);
// -----------------
void merge_all_functions(t_pars *map, t_store	*store);
void create_window(char **twode, t_store *elemenets);
void	count_players(char **twode);
void draw_map(t_store *elemenets);
void	check_inside_map(char **twode);
void	check_side_walls(char **twode);
void	prin_map(char **twode);
int		function_check_ithems(char *string);
void	exit_message(char *string);
void	bothwalls(char **twode);
int		get_longest_line(char **twode);
char	*heal_line(char *element, int biggest, char replace);
void	check_on(char *string);
int		check_on_validiation(char *string);
int		function_check_ithem(char *string);
char	**rebuild_map(char **twode);
int		get_longest_line(char **twode);
int		number_conv(char *string);
char	*string_copy_from_till(char *string, int start, int stop);
void	check_rgb_colors(char **twode, t_store *store);
char	*copy_move(char *string);
int		check_directions(char **twode, t_store *store);
int		count_twode_arr(char **array);
int		count_twode_arr(char **array);
char	**move_only_content(char **twode);
int		le_count(char *string);
char	**moveto_array(char *string);
int		count_how_may(char *string, char srach_for);
char	*string_turn(char *string, char *copy);
void	putstring(char *string);
void	paste(char string);
int		function_open_map(char *file_name, t_pars *ithems);

//--------------


#endif