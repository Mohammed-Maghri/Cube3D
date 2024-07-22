/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:27:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/07/22 10:21:12 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <math.h>

# define TSIZE			32
# define MSIZE			22
# define ESC			256
# define RIGHT			262
# define LEFT			263
# define PLAYER_SPEED	3 // 2 pixels
# define MOUSE_SPEED	0.1
# define ROTATION_SPEED	(M_PI / 180) // 1 degree
# define FOV			(M_PI / 3) // 60 degree
# define WINDOW_HEIGHT	(30 * TSIZE)
# define WINDOW_WIDTH	(50 * TSIZE)
# define MINI_HEIGHT	(WINDOW_HEIGHT / 4)
# define MINI_WIDTH		(WINDOW_WIDTH / 4)
# define UNITY			((double)MSIZE / TSIZE)
# define ANGLE_STEP		(FOV / WINDOW_WIDTH)
# define PIXI			(double)(MSIZE / 6)
# define MINI_COLOR		0xAAAAAAAA
# define DOOR_COLOR		0xAAAAAA33

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_coordinate
{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_player
{
	t_position		pos_in_map;
	t_position		pos_in_pixels;
	t_coordinate	move;
	double			angle;
	double			rotation;
	int				left_right;
	int				up_down;
}	t_player;

typedef struct s_ray
{
	int		index;
	int		color;
	int		down;
	int		up;
	int		left;
	int		right;
	char	view;
	double	angle;
	double	start;
	double	h_distance;
	double	v_distance;
	double	distance;
}	t_ray;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		mini_width;
	int		mini_height;
	int		h_door;
	int		v_door;
	int		door;
}	t_map;

typedef struct s_mlx
{
	void			*pointer;
	void			*image;
	mlx_texture_t	*no_wall;
	mlx_texture_t	*so_wall;
	mlx_texture_t	*we_wall;
	mlx_texture_t	*ea_wall;
	mlx_texture_t	*door;
}	t_mlx;

typedef struct s_data
{
	t_mlx			*mlx;
	t_map			*map;
	t_ray			*ray;
	t_player		*player;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				check_reload;
	int				var_check;
	int				wall_start;
	double			wall_height;
	double			wall_distance;
	uint32_t		*color;
	mlx_texture_t	*texture;
	mlx_texture_t	*bonus;
	mlx_texture_t	*reload[10];
}	t_data;

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
	int		x;
	int		y;
	double	player_position;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	char	**map;
	char	**array;
	void	*mlx;
	void	*win;
	void	*imag;
	void	*data ;
	int		dat ;
	int		linelenght;
	int		endian ;
}	t_store;

/*************** INIT *************/
void	ft_init_map(t_data *data);
void	ft_init_player(t_data *data, t_store *store);
void	ft_init_data(t_data **data, t_store *store);
void	ft_init_mlx(t_data *data);
void	ft_init(t_data *data);
void	ft_close(t_data *data);

/*************** MOVE *************/
void	ft_move_player(t_data *data);
void	ft_update_window(void *d);
void	ft_key_move(mlx_key_data_t keydata, void *d);
void	ft_mouse_move(double xpos, double ypos, void *d);

/*************** RAY_CAST *************/
void	ft_cast_rays(t_data *data);
void	ft_normalize(t_ray *ray);
double	ft_hdistance(t_data *data);
double	ft_vdistance(t_data *data);
double	ft_distance(t_coordinate a, t_position b);

/**************** DRAW ***************/
void	ft_draw_ray(t_data *data);
void	ft_draw_all(t_data *data);
void	ft_draw_minimap(t_data *data);
void	ft_draw_miniplayer(t_data *data);
int		ft_wall(t_map *map, double x, double y);
int		ft_door(t_data *data, double a, double b);
int		ft_near_wall(t_map *map, double a, double b);
int		ft_color(int r, int g, int b, int a);
int		ft_texture_color(unsigned int c);
void	ft_draw_image(t_data *data, mlx_texture_t *bonus, int x, int y);
void	ft_mlx_put_pixel(t_mlx *mlx, int x, int y, int color);

/**************** PARSING ***************/
int		count_lenght(void **array);
void	optins(void **array);
void	*gb(int size, int flag);
void	**garbege_array_fill(void **array, void *add);
void	ft_background_sound(char *text);
void	kill_sound(void);

// -----------------
void	merge_all_functions(t_pars *map, t_store	*store);
void	create_window(char **twode, t_store *elemenets);
void	count_players(char **twode);
void	draw_map(t_store *elemenets);
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

#endif