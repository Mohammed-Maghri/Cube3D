SRC = main.c parsing/utils/utils.c parsing/utils/utils1.c \
parsing/map_validity.c parsing/map_valid2.c parsing/valid_map_check.c \
parsing/valid_map1.c gcollector/gb.c parsing/if_map_is_valid.c parsing/wall_check.c\
draw_map/map_draw.c 

OBJS = ${SRC:.c=.o}
NAME = Cub3d
CC = cc
# CFLAGS = -O3 -I ./mlx -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf
# MLX = ./mlx/libmlx.a -lm -framework OpenGL -framework AppKit

# all: $(NAME)

# $(NAME): $(OBJS) cub3d.h
# 	$(CC) $(OBJS) $(MLX) $(CFLAGS) -o $(NAME)
# %.o: %.c cub3d.h
# 	$(CC) $(CFLAGS) -c $< -o $@
all:
	cc -O3 -ffast-math -framework Cocoa -framework OpenGL -framework IOKit -lglfw libmlx42.a -L/Users/cmasnaou/.brew/opt/glfw/lib/ \
	$(SRC) -o cub3d -g -fsanitize=address
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
