# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenzo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 17:07:03 by lorenzo           #+#    #+#              #
#    Updated: 2024/08/18 17:18:05 by lorenzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/main.c srcs/no_args.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/read_file.c

OBJS		= ${SRCS:.c=.o}

NAME		= ft_cat

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

