# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 21:35:20 by oel-mado          #+#    #+#              #
#    Updated: 2025/04/08 14:53:31 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -IMLX42/include

MLXFLAGS = -Iinclude -ldl -lglfw -L"/Users/oel-mado/goinfre/homebrew/Cellar/glfw/3.4/lib" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

MLX_DIR = MLX42/build/libmlx42.a

SRCS = put.c is_error.c ft_atod.c fractol.c mandelbrot.c do_fractol.c libft/ft_strncmp.c julia.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_DIR) -o $(NAME) $(MLXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

f: fclean

c: clean

re: fclean all

