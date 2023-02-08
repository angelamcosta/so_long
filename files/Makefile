NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

LIBS	=	-L ./mlx -lmlx -lXext -lX11

SRCS	=	

all:		$(NAME)

$(NAME):
			make -C mlx
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)
clean:
			make clean -C mlx

fclean:
			clean
			$(RM) $(NAME)

re:
			fclean all
