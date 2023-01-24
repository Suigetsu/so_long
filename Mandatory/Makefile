# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:08:25 by mlagrini          #+#    #+#              #
#    Updated: 2023/01/23 13:01:45 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Mandatory/checkmap/so_mapread.c \
			Mandatory/checkmap/so_wallcheck.c \
			Mandatory/checkmap/so_rectangle.c \
			Mandatory/checkmap/so_maputils.c \
			Mandatory/checkmap/so_mapname.c \
			Mandatory/checkmap/so_invalidmsg.c \
			Mandatory/checkmap/so_path.c \
			Mandatory/moves/so_exitmove.c \
			Mandatory/moves/so_movement.c \
			Mandatory/moves/so_upmove.c \
			Mandatory/moves/so_playerimg.c \
			Mandatory/moves/so_rmove.c \
			Mandatory/moves/so_lmove.c \
			Mandatory/moves/so_keys.c \
			Mandatory/moves/so_downmove.c \
			Mandatory/components/so_others.c \
			Mandatory/components/so_walls.c \
			Mandatory/utils/get_next_line.c \
			Mandatory/utils/ft_strjoin.c \
			Mandatory/utils/ft_strlen.c \
			Mandatory/utils/ft_split.c \
			Mandatory/utils/ft_strchr.c \
			Mandatory/utils/ft_substr.c \
			Mandatory/utils/ft_calloc.c \
			Mandatory/utils/ft_bzero.c \
			Mandatory/utils/ft_memcpy.c \
			Mandatory/utils/ft_strdup.c \
			Mandatory/utils/ft_printf.c \
			Mandatory/utils/ft_putadrs.c \
			Mandatory/utils/ft_putchar.c \
			Mandatory/utils/ft_puthex.c \
			Mandatory/utils/ft_putnbr.c \
			Mandatory/utils/ft_putstr.c \
			Mandatory/utils/ft_putunsigned.c \
			Mandatory/utils/ft_putuphex.c \
			Mandatory/components/so_lower_upwall_imgs.c \
			Mandatory/main/so_printmap.c \
			Mandatory/main/main.c
OBJS	= ${SRCS:.c=.o}

BSRS = 
OBJB	= ${BSRS:.c=.o}
BNAME = so_long_bonus


CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Imlx
INCFLAG	= -I /usr/local/include
MLXFLAG	= -lmlx -framework OpenGL -framework AppKit
RM		= rm -rf
NAME	= Pokemon

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		$(CC) $(OBJS) $(MLXFLAG) -o $(NAME)

bonus: ${BNAME}

$(BNAME): ${OBJB}
		$(CC) $(OBJB) $(MLXFLAG) -o $(BNAME)	

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}


.PHONY:	all clean fclean