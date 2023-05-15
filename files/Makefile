NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g -fsanitize=address

LIBS	=	-L ../mlx -lmlx -lXext -lX11

SRCS	=	so_long.c ./utils/clean_mallocs.c ./utils/events.c ./utils/general_utils.c \
			./utils/get_next_line_utils.c ./utils/get_next_line.c ./utils/populate_map.c \
			./utils/so_long_utils.c ./utils/verify_map_utils.c ./utils/verify_map.c

all:		$(NAME)

$(NAME):
			make -C ../mlx
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
			make clean -C ../mlx

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
