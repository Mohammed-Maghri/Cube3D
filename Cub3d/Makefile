# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 09:06:42 by cmasnaou          #+#    #+#              #
#    Updated: 2024/06/25 09:09:02 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c parsing/utils/utils.c parsing/utils/utils1.c \
parsing/map_validity.c parsing/map_valid2.c parsing/valid_map_check.c \
parsing/valid_map1.c gcollector/gb.c parsing/if_map_is_valid.c parsing/wall_check.c\
draw_map/map_draw.c 

OBJS = ${SRC:.c=.o}
NAME = Cub3d
CC = cc
CFLAGS = -O3 -ffast-math -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf
MLX = -framework Cocoa -framework OpenGL -framework IOKit -lglfw MLX42/libmlx42.a -L/Users/$(USER)/.brew/opt/glfw/lib/

all: $(NAME)

$(NAME): $(OBJS) cub3d.h
	$(CC) $(OBJS) $(MLX) $(CFLAGS) -o $(NAME)
%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
