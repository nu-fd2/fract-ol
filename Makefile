# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/02 21:35:20 by oel-mado          #+#    #+#              #
#    Updated: 2025/03/02 21:43:11 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This figgle is useless (rir daba)

CC = cc -Wall -Wextra -Werror

NAME = fract-oel

all:

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
