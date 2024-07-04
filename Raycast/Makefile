# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 09:26:25 by cmasnaou          #+#    #+#              #
#    Updated: 2024/07/03 14:59:36 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
# BONUS	=	cub3D_bonus
CC		=	cc
RM		=	rm -rf
FLAGS	=	-O3 -ffast-math -Wall -Wextra -Werror -g -fsanitize=address
FLMLX	=	-framework Cocoa -framework OpenGL -framework IOKit
LFLAG	=	-lglfw MLX42/libmlx42.a -L/Users/$(USER)/.brew/opt/glfw/lib/
HEADM	=	cub3D.h
# HEADB	=	cub3D_bonus.h
SRCS	=	cub3D.c move.c raycast.c close.c distance.c utils.c minimap.c
# SRCB	=	cub3D.c libft.c player.c ray.c close.c key.c draw.c utils.c
OBJS	=	$(SRCS:.c=.o)
# OBJB	=	$(SRCB:.c=.o)
all		:	$(NAME)
$(NAME)	:	$(OBJS)
			@$(CC) $(FLAGS) $(FLMLX) $(LFLAG) $^ -o $@
$(OBJS)	:	%.o:%.c		$(HEADM) Makefile
			@$(CC) $(FLAGS) -c $< -o $@
# bonus	:	$(BONUS)
# $(BONUS):	$(OBJB)
# 			@$(CC) $(FLAGS) $(FLMLX) $(LFLAG) $^ -o $@
# $(OBJB)	:	%.o:%.c		$(HEADB)
# 			@$(CC) $(FLAGS) -c $< -o $@
clean	:
			@$(RM) $(OBJS) $(OBJB)
fclean	:	clean
			@$(RM) $(NAME) $(BONUS)
re		:	fclean all
.PHONY	:	clean
