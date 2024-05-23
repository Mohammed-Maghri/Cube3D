SRC =   main.c parsing/utils/utils.c parsing/utils/utils1.c  parsing/map_validity.c parsing/valid_map_check.c parsing/valid_map1.c gcollector/gb.c 
OBJS = ${SRC:.c=.o}
NAME = Cub3d
CC = cc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -rf 

all : $(NAME)

$(NAME) : $(OBJS) cub3d.h
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.c $(SRC) cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)
fclean :
	$(RM) $(OBJS) $(NAME)
re : fclean all