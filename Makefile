# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 21:35:20 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/14 19:58:27 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror

CFLAGS = -Wall -Wextra -Werror

NAME = fractol

LIB = libft/libft.a

all:

$(LIB):
	make -C libft re
	make -C libft clean

clean:

fclean: clean
	make -C libft fclean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
