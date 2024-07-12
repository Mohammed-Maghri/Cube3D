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

void *thread_function_handler(char *text)
{
    system(text);
    return (NULL);
}

void function_background_sound(char *text)
{
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)thread_function_handler, (text));
    pthread_detach(thread);
}
void kill_sound(void)
{
    execve("/usr/bin/killall", (char *[]){"killall", "afplay", NULL}, NULL);
}

