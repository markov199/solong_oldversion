# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 12:12:10 by mkovoor           #+#    #+#              #
#    Updated: 2022/08/23 14:29:52 by mkovoor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -g3

FLAGS = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRC = test.c

OBJ = ${SRC:.c=.o}

all: ${OBJ}
	${MAKE} -C ./minilibx
	${CC} ${FLAGS} ${LINKS} ${OBJ} -o solong

clean:
	${RM} ${OBJ}

fclean:
	${RM} solong
	${MAKE} clean -C ./minilibx

re: fclean all

.PHONY: all clean fclean re
	
