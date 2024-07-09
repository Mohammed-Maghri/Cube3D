/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_sound.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-08 12:34:15 by mmaghri           #+#    #+#             */
/*   Updated: 2024-07-08 12:34:15 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void *thread_function_handler(void)
{
    system("afplay ./Mandatory/te.mp3");
    return (NULL);
}

void function_background_sound(void)
{
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)thread_function_handler, NULL);
    pthread_detach(thread);
}
void kill_sound(void)
{
    execve("/usr/bin/killall", (char *[]){"killall", "afplay", NULL}, NULL);
}
