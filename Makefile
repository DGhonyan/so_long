NAME = so_long
CC = cc
CFLAGS = -c -Wall -Wextra -Werror#TODO add flags
# MLX = -lmlx -L /usr/local/include -framework AppKit -framework OpenGL
# MLX = -I/usr/include -Imlx_linux -O3
# MLX_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX = -lmlx -L mlx -framework AppKit -framework OpenGL
LIBFT = -lft -L libft
FT_PRINTF = -lftprintf -L ft_printf
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.c:
	$(CC) $(CFLAGS) $(SRCS)

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -o $(NAME)

# Linux
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_LINUX) -o $(NAME)


ftprintf:
	cd ft_printf && make

lib:
	cd libft && make 

clean:
	rm -f ./*.o libft/*.o ft_printf/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re lib ftprintf