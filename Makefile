# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:08:25 by mlagrini          #+#    #+#              #
#    Updated: 2023/01/02 19:27:46 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	components/so_walls.c \
			components/so_others.c \
			moves/so_downmove.c \
			moves/so_keys.c \
			moves/so_playerimg.c \
			moves/so_rmove.c \
			moves/so_upmove.c \
			checkmap/so_chars.c \
			checkmap/so_invalidmsg.c \
			checkmap/so_mapname.c \
			checkmap/so_mapread.c \
			checkmap/so_maputils.c \
			checkmap/so_path.c \
			checkmap/so_rectangle.c \
			checkmap/so_wallcheck.c \
			utils/ft_split.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			main/new_main.c \
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
NAME	= so_long.a

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		ar rc ${NAME} $^

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re