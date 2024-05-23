/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:32:50 by mmaghri           #+#    #+#             */
/*   Updated: 2024/05/23 20:32:52 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
}			t_pars;

typedef struct store_map_elem
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}	t_store;
// Garbege Collector
int		count_lenght(void **array);
void	optins(void **array);
void	*gb(int size, int flag);
void	**garbege_array_fill(void **array, void *add);
// -----------------

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