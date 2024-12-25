/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_sound.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:34:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/29 19:29:32 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	*thread_function_handler(char *text)
{
	system(text);
	return (NULL);
}

void	ft_background_sound(char *text)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, (void *)thread_function_handler, (text));
	pthread_detach(thread);
}

void	kill_sound(void)
{
	execve("/usr/bin/killall", (char *[]){"killall", "afplay", NULL}, NULL);
}

void	ft_close(t_data *data)
{
	mlx_delete_image(data->mlx->pointer, data->mlx->image);
	mlx_close_window(data->mlx->pointer);
	mlx_terminate(data->mlx->pointer);
	write(1, "GAME OVER!\n", 12);
	gb(0, 3);
	kill_sound();
	exit(0);
}
