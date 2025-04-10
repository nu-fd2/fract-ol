# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 21:35:20 by oel-mado          #+#    #+#              #
#    Updated: 2025/04/10 01:23:14 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

BNAME = fractol_bonus

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -IMLX42/include

MLXFLAGS = -Iinclude -ldl -lglfw -L"/Users/oel-mado/goinfre/homebrew/Cellar/glfw/3.4/lib" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

MLX_DIR = MLX42/build/libmlx42.a

SRC = fractol.c \
	src/do_fractol.c \
	src/is_error.c \
	src/ft_atod.c \
	src/ft_strncmp.c \
	src/mandelbrot.c \
	src/julia.c \

BSRC = bonus/fractol_bonus.c \
	bonus/do_fractol_bonus.c \
	bonus/is_error_bonus.c \
	bonus/ft_atod_bonus.c \
	bonus/ft_strncmp_bonus.c \
	bonus/mandelbrot_bonus.c \
	bonus/julia_bonus.c \
	bonus/burning_ship_bonus.c \

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_DIR) -o $(NAME) $(MLXFLAGS)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(MLX_DIR) -o $(BNAME) $(MLXFLAGS)

src/%.o: src/%.c $(SRC) fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BSRC) bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

f: fclean

c: clean

b: bonus

re: fclean all

.PHONY: all clean fclean bonus re f c b
