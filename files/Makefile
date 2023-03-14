NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

LIBS	=	-L ../mlx -lmlx -lXext -lX11

SRCS	=	so_long.c ./read_map/get_next_line.c ./read_map/get_next_line_utils.c ./game_utils/so_long_utils.c ./read_map/verify_map.c ./read_map/verify_map_utils.c ./game_utils/general_utils.c

all:		$(NAME)

$(NAME):
			make -C ../mlx
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
			make clean -C ../mlx

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
