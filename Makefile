# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:08:25 by mlagrini          #+#    #+#              #
#    Updated: 2023/01/24 22:32:32 by mlagrini         ###   ########.fr        #
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
			Mandatory/checkmap/so_free.c \
			Mandatory/main/main.c

BSRS	=	bonus/checkmap/so_invalidmsg_bonus.c \
			bonus/checkmap/so_mapname_bonus.c \
			bonus/checkmap/so_mapread_bonus.c \
			bonus/checkmap/so_maputils_bonus.c \
			bonus/checkmap/so_path_bonus.c \
			bonus/checkmap/so_rectangle_bonus.c \
			bonus/checkmap/so_wallcheck_bonus.c \
			bonus/components/so_enemy_bonus.c \
			bonus/components/so_lower_upwall_imgs_bonus.c \
			bonus/components/so_others_bonus.c \
			bonus/components/so_walls_bonus.c \
			bonus/main/main_bonus.c \
			bonus/moves/so_animated_bonus.c \
			bonus/moves/so_downmove_bonus.c \
			bonus/moves/so_enemyimg_bonus.c \
			bonus/moves/so_exitgiovanni_bonus.c \
			bonus/moves/so_exitjames_bonus.c \
			bonus/moves/so_exitjessie_bonus.c \
			bonus/moves/so_exitmeowth_bonus.c \
			bonus/moves/so_exitmove_bonus.c \
			bonus/moves/so_giovanni_bonus.c \
			bonus/moves/so_james_bonus.c \
			bonus/moves/so_jessie_bonus.c \
			bonus/moves/so_keys_bonus.c \
			bonus/moves/so_lmove_bonus.c \
			bonus/moves/so_meowth_bonus.c \
			bonus/moves/so_movement_bonus.c \
			bonus/moves/so_playerimg_bonus.c \
			bonus/moves/so_reqs_bonus.c \
			bonus/moves/so_rmove_bonus.c \
			bonus/moves/so_upmove_bonus.c \
			bonus/utils/ft_bzero_bonus.c \
			bonus/utils/ft_calloc_bonus.c \
			bonus/utils/ft_itoa_bonus.c \
			bonus/utils/ft_memcpy_bonus.c \
			bonus/utils/ft_printf_bonus.c \
			bonus/utils/ft_putadrs_bonus.c \
			bonus/utils/ft_putchar_bonus.c \
			bonus/utils/ft_puthex_bonus.c \
			bonus/utils/ft_putnbr_bonus.c \
			bonus/utils/ft_putstr_bonus.c \
			bonus/utils/ft_putunsigned_bonus.c \
			bonus/utils/ft_putuphex_bonus.c \
			bonus/utils/ft_split_bonus.c \
			bonus/utils/ft_strchr_bonus.c \
			bonus/utils/ft_strdup_bonus.c \
			bonus/utils/ft_strjoin_bonus.c \
			bonus/utils/ft_strlen_bonus.c \
			bonus/utils/ft_substr_bonus.c \
			bonus/checkmap/so_free_bonus.c \
			bonus/utils/get_next_line_bonus.c \
			bonus/main/so_printmap_bonus.c \
			
OBJS	= ${SRCS:.c=.o} 
OBJB	= ${BSRS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Imlx
INCFLAG	= -I /usr/local/include
MLXFLAG	= -lmlx -framework OpenGL -framework AppKit
RM		= rm -rf
NAME	= Pokemon
BNAME	= Pokemon_bonus

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

bclean:
		${RM} ${OBJB}

b_fclean: bclean
		${RM} ${BNAME}


.PHONY:	all clean fclean bonus bclean b_fclean