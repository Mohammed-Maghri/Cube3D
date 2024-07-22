/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_sound.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:34:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024/07/22 16:22:46 by cmasnaou         ###   ########.fr       */
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
