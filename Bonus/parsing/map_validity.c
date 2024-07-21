/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:41:54 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/21 15:48:59 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	function_open_map(char *file_name, t_pars *ithems)
{
	ithems->fd = open(file_name, O_RDONLY);
	ithems->buf = gb(2, 1);
	if (ithems->fd == -1)
		return (putstring("File Not Found"), -1);
	ithems->read_buf = read(ithems->fd, ithems->buf, 1);
	ithems->buf[ithems->read_buf] = '\0';
	ithems->map = string_turn(ithems->map, ithems->buf);
	while (ithems->read_buf > 0)
	{
		ithems->read_buf = read(ithems->fd, ithems->buf, 1);
		ithems->buf[ithems->read_buf] = '\0';
		ithems->map = string_turn(ithems->map, ithems->buf);
	}
	if (ithems->read_buf == -1)
	{
		printf("Error Accured While Reading From file... !\n");
		exit(1);
	}
	return (1);
}
