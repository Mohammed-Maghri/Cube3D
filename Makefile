# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 09:26:25 by cmasnaou          #+#    #+#              #
#    Updated: 2024/07/29 18:26:13 by cmasnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
BONUS	=	cub3D_bonus
CC		=	cc
RM		=	rm -rf
FLAGS	=	-O3 -ffast-math -Wall -Wextra -Werror
FLMLX	=	-framework Cocoa -framework OpenGL -framework IOKit
LFLAG	=	MLX42/libmlx42.a -lglfw -L/Users/$(USER)/.brew/opt/glfw/lib/
HEADM	=	Mandatory/cub3D.h
HEADB	=	Bonus/cub3D_bonus.h
SRCS	=	Mandatory/cub3D.c Mandatory/main_file.c Mandatory/move.c Mandatory/raycast.c  \
			Mandatory/draw.c Mandatory/utils.c Mandatory/minimap.c Mandatory/main_file2.c Mandatory/extramain_file.c Mandatory/parsing/extravalid_map_check.c\
			Mandatory/parsing/utils/utils.c Mandatory/parsing/utils/utils1.c Mandatory/extramainfile3.c Mandatory/extramain_file2.c\
			Mandatory/parsing/map_validity.c Mandatory/parsing/map_valid2.c Mandatory/parsing/valid_map_check.c Mandatory/parsing/utils/extrautils.c \
			Mandatory/parsing/valid_map1.c Mandatory/gcollector/gb.c Mandatory/parsing/if_map_is_valid.c Mandatory/parsing/wall_check.c Mandatory/parsing/extrawall_check.c \
			Mandatory/parsing/extravalid_map1.c Mandatory/parsing/mapvaliextra.c Mandatory/parsing/ifmapvalidextra.c

SRCB	=	Bonus/background_sound.c Bonus/cub3D_bonus.c Bonus/extramainfile3.c Bonus/main_file.c  Bonus/main_file2.c Bonus/move.c Bonus/extramain_file.c Bonus/raycast.c \
			Bonus/utils.c Bonus/draw.c Bonus/minimap.c Bonus/mouse.c Bonus/extramain_file2.c \
			Bonus/parsing/utils/utils.c Bonus/parsing/utils/extrautils.c Bonus/parsing/utils/utils1.c Bonus/parsing/extravalid_map_check.c \
			Bonus/parsing/map_validity.c Bonus/parsing/map_valid2.c Bonus/parsing/valid_map_check.c  Bonus/parsing/extrawall_check.c\
			Bonus/parsing/valid_map1.c Bonus/parsing/extravalid_map1.c Bonus/gcollector/gb.c Bonus/parsing/if_map_is_valid.c Bonus/parsing/mapvaliextra.c \
			Bonus/parsing/ifmapvalidextra.c Bonus/parsing/wall_check.c Bonus/parsing/check_dors.c 
OBJS	=	$(SRCS:.c=.o)
OBJB	=	$(SRCB:.c=.o)
all		:	$(NAME)
$(NAME)	:	$(OBJS)
			@$(CC) $(FLAGS) $(FLMLX) $(LFLAG) $^ -o $@
$(OBJS)	:	%.o:%.c		$(HEADM) Makefile
			@$(CC) $(FLAGS) -c $< -o $@
bonus	:	$(BONUS)
$(BONUS):	$(OBJB)
			@$(CC) $(FLAGS) $(FLMLX) $(LFLAG) $^ -o $@
$(OBJB)	:	%.o:%.c		$(HEADB) Makefile
			@$(CC) $(FLAGS) -c $< -o $@
clean	:
			@$(RM) $(OBJS) $(OBJB)
fclean	:	clean
			@$(RM) $(NAME) $(BONUS)
re		:	fclean all
.PHONY	:	clean
