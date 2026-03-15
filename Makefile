NAME := fdf

CC := cc

CFLAGS := -Wall -Wextra -Werror

MLX_PATH = ./minilibx-linux

SRCS = $(wildcard *.c) $(wildcard get_next_line/*.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)
	@echo "fdf create !"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
	@./$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -I./minilibx-linux -I/get_next_line -Imlx_linux -O3 -c $< -o $@ 

clean : 
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re