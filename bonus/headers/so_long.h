/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:52:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/24 22:28:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_walls
{
	int		fd;
	int		c;
	int		len;
	char	*s;
}				t_walls;

typedef struct s_errors
{
	char	*inv_char;
	char	*rect_map;
	char	*map_name;
	char	*map_wall;
}				t_errors;

typedef struct s_mapchar
{
	int	col_count;
	int	ext_count;
	int	strt_count;
	int	schar_count;

}				t_mapchar;

typedef struct s_playerone
{
	void	*oneup1;
	void	*oneright1;
	void	*oneleft1;
	void	*onedown1;
	char	*o_uppath1;
	char	*o_rightpath1;
	char	*o_leftpath1;
	char	*o_downpath1;
}				t_playerone;

typedef struct s_playertwo
{
	void	*twoup1;
	void	*tworight1;
	void	*twoleft1;
	void	*twodown1;
	char	*to_uppath1;
	char	*to_rightpath1;
	char	*to_leftpath1;
	char	*to_downpath1;
}				t_playertwo;

typedef struct s_playerthree
{
	void	*threeup1;
	void	*threeright1;
	void	*threeleft1;
	void	*threedown1;
	char	*th_uppath1;
	char	*th_rightpath1;
	char	*th_leftpath1;
	char	*th_downpath1;
}				t_playerthree;

typedef struct s_img
{
	void	*bg;
	void	*upwall;
	void	*upl_wall;
	void	*upr_wall;
	void	*lowall;
	void	*lol_wall;
	void	*lor_wall;
	void	*left_wall;
	void	*right_wall;
	void	*coll;
	void	*exit;
	void	*obs;
}				t_img;

typedef struct s_mapwh
{
	int		width;
	int		height;
	char	*map;
	char	**game;
}				t_mapwh;

typedef struct s_path
{
	char	*path_bg;
	char	*path_uwall;
	char	*path_ulwall;
	char	*path_urwall;
	char	*path_lwall;
	char	*path_llwall;
	char	*path_lrwall;
	char	*path_lftwall;
	char	*path_rgtwall;
	char	*path_col;
	char	*path_exit;
	char	*obs;
	char	*path_p1;
}				t_path;

typedef struct s_additionals
{
	char	**mapcopy;
}				t_additionals;

typedef struct s_anim
{
	char	*framepath1;
	char	*framepath2;
	char	*framepath3;
	void	*frame1;
	void	*frame2;
	void	*frame3;
}				t_anim;

typedef struct s_enemyone
{
	void	*oneup;
	void	*oneright;
	void	*oneleft;
	void	*onedown;
	char	*o_uppath;
	char	*o_downpath;
	char	*o_rightpath;
	char	*o_leftpath;
}				t_enemyone;

typedef struct s_enemytwo
{
	void	*twoup;
	void	*tworight;
	void	*twoleft;
	void	*twodown;
	char	*to_uppath;
	char	*to_downpath;
	char	*to_rightpath;
	char	*to_leftpath;
}				t_enemytwo;

typedef struct s_enemythree
{
	void	*threeup;
	void	*threeright;
	void	*threeleft;
	void	*threedown;
	char	*th_uppath;
	char	*th_downpath;
	char	*th_rightpath;
	char	*th_leftpath;
}				t_enemythree;

typedef struct s_meowth
{
	void	*up;
	void	*down;
	void	*right;
	void	*left;
	char	*uppath;
	char	*downpath;
	char	*rightpath;
	char	*leftpath;
	char	*path1;
	char	*path2;
	void	*f1;
	void	*f2;
}				t_meowth;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				i;
	int				j;
	int				img_x;
	int				img_y;
	int				count;
	int				ev1;
	int				ev2;
	char			*counter;
	t_path			path;
	t_mapwh			w_h;
	t_img			img;
	t_playerone		p1;
	t_playertwo		p2;
	t_playerthree	p3;
	t_enemyone		e1;
	t_enemytwo		e2;
	t_enemythree	e3;
	t_meowth		meowth;
	t_anim			anim;
}				t_vars;

char	*get_next_line(int fd);
int		ft_isnewline(char *s);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned int n);
int		ft_putuphex(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_putadrs(unsigned long n);
int		wall_of_maria(char *filename);
int		mapchars(char *filename);
int		maprectangle(char *filename);
int		mapname(char *filename);
void	validmap(char *filename);
int		right_move(t_vars *var);
void	upper_wall(t_vars *var);
void	left_wall(t_vars *var);
void	lower_wall(t_vars *var);
void	right_wall(t_vars *var);
void	coll(t_vars *var);
void	obs(t_vars *var);
void	exit_game(t_vars *var);
void	map_read(char *filename, t_vars *var);
int		up_move(t_vars *var);
int		keys(int key, t_vars *var);
int		down_move(t_vars *var);
int		left_move(t_vars *var);
void	playerone(t_vars *var);
void	playertwo(t_vars *var);
void	playerthree(t_vars *var);
void	show_player(t_vars *var);
void	down_evolution(int count, t_vars *var);
void	up_evolution(int count, t_vars *var);
void	right_evolution(int count, t_vars *var);
void	left_evolution(int count, t_vars *var);
void	exit_xy(t_vars *var);
int		coll_scan(t_vars *var);
int		right_exit(t_vars *var);
int		left_exit(t_vars *var);
int		up_exit(t_vars *var);
int		down_exit(t_vars *var);
void	printmap(t_vars *var);
void	player_finder(t_vars *var, t_additionals *mapcpy);
void	valid_path(t_vars *var, t_additionals *mapcpy);
void	map_copy(t_vars *var, t_additionals *mapcpy);
int		destroy_with_mouse(t_vars *var);
void	lower_wall_imgs(t_vars *var);
void	upper_wall_imgs(t_vars *var);
int		animation(t_vars *var);
void	meowth(t_vars *var);
int		jessie_moves(t_vars *var);
int		giovanni_moves(t_vars *var);
int		meowth_moves(t_vars *var);
int		enemies_hook(t_vars *var);
void	james_exit(t_vars *var);
void	jessie_exit(t_vars *var);
void	giovanni_exit(t_vars *var);
void	meowth_exit(t_vars *var);
void	move_counter(int movecount, t_vars *var);
void	animation_img(t_vars *var);
int		james_moves(t_vars *var);
void	enemyone(t_vars *var);
void	enemytwo(t_vars *var);
void	enemythree(t_vars *var);
void	show_james(t_vars *var);
void	show_jessie(t_vars *var);
void	show_giovanni(t_vars *var);
void	show_meowth(t_vars *var);
void	free_pokemon(t_vars *var);

#endif