/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:32:50 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/27 11:06:01 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
// For Parsing 
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

typedef struct only_for_map
{
	void *mlx_ptr;
	void *images;
	void *pic;
	void *direction;
} t_map;

// Garbege Collector
int		count_lenght(void **array);
void	optins(void **array);
void	*gb(int size, int flag);
void	**garbege_array_fill(void **array, void *add);
// -----------------

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



//For Raycasting

//--------------
#endif 