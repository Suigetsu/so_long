# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:08:25 by mlagrini          #+#    #+#              #
#    Updated: 2023/01/09 22:25:06 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	checkmap/so_mapread.c \
			checkmap/so_wallcheck.c \
			checkmap/so_rectangle.c \
			checkmap/so_maputils.c \
			checkmap/so_mapname.c \
			checkmap/so_chars.c \
			checkmap/so_invalidmsg.c \
			moves/so_exitmove.c \
			moves/so_movement.c \
			moves/so_upmove.c \
			moves/so_playerimg.c \
			moves/so_rmove.c \
			moves/so_lmove.c \
			moves/so_keys.c \
			moves/so_downmove.c \
			components/so_others.c \
			components/so_walls.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
			42_libft/ft_strjoin.c \
			42_libft/ft_strlen.c \
			42_libft/ft_split.c \
			42_libft/ft_strchr.c \
			42_libft/ft_substr.c \
			42_libft/ft_calloc.c \
			42_libft/ft_bzero.c \
			42_libft/ft_memcpy.c \
			42_libft/ft_strdup.c \
			42_ft_printf/ft_printf.c \
			42_ft_printf/ft_putadrs.c \
			42_ft_printf/ft_putchar.c \
			42_ft_printf/ft_puthex.c \
			42_ft_printf/ft_putnbr.c \
			42_ft_printf/ft_putstr.c \
			42_ft_printf/ft_putunsigned.c \
			42_ft_printf/ft_putuphex.c \
			main/main.c
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Imlx
INCFLAG	= -I /usr/local/include
MLXFLAG	= -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
RM		= rm -rf
NAME	= Pokemon

# game:%.o
# 		${CC} -o game %.o 

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		clear

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re