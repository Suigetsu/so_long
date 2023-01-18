/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:52:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/17 15:04:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <time.h>
# include "mlx.h"
# define	enemy 30 

typedef struct s_animeowth
{
	char	*path1;
	char	*path2;
	void	*f1;
	void	*f2;
}				t_animeowth;

typedef struct s_errors
{
    char    *inv_char;
    char    *rect_map;
    char    *map_name;
    char    *map_wall;
}				t_errors;

typedef struct s_mapchar
{
	int	col_count;
	int	ext_count;
	int	strt_count;
	int	schar_count;

}				t_mapchar;

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

typedef struct s_playerone
{
	void	*oneup1;
	void	*oneup2;
	void	*oneright1;
	void	*oneright2;
	void	*oneleft1;
	void	*oneleft2;
	void	*onedown1;
	void	*onedown2;
	char	*o_uppath1;
	char	*o_uppath2;
	char	*o_rightpath1;
	char	*o_rightpath2;
	char	*o_leftpath1;
	char	*o_leftpath2;
	char	*o_downpath1;
	char	*o_downpath2;
}				t_playerone;

typedef struct s_playertwo
{
	void	*twoup1;
	void	*twoup2;
	void	*tworight1;
	void	*tworight2;
	void	*twoleft1;
	void	*twoleft2;
	void	*twodown1;
	void	*twodown2;
	char	*to_uppath1;
	char	*to_uppath2;
	char	*to_rightpath1;
	char	*to_rightpath2;
	char	*to_leftpath1;
	char	*to_leftpath2;
	char	*to_downpath1;
	char	*to_downpath2;
}				t_playertwo;

typedef struct s_playerthree
{
	void	*threeup1;
	void	*threeup2;
	void	*threeright1;
	void	*threeright2;
	void	*threeleft1;
	void	*threeleft2;
	void	*threedown1;
	void	*threedown2;
	char	*th_uppath1;
	char	*th_uppath2;
	char	*th_rightpath1;
	char	*th_rightpath2;
	char	*th_leftpath1;
	char	*th_leftpath2;
	char	*th_downpath1;
	char	*th_downpath2;
}				t_playerthree;

typedef struct s_img
{
    void    *bg;
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

typedef struct s_vars
{
	void			*mlx;
	void			*win;
    int             i;
    int             j;
	int				img_x;
	int				img_y;
    int             count;
    int             ev1;
    int             ev2;
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
}				t_vars;

int		starting_pt(char *s);
int		strangechars(char *s);
int		exits(char *s);
int		collectibles_nbr(char *s);
int		calculatrice(char *s);
int		wall_of_maria(char *filename);
int		mapchars(char *filename);
int		maprectangle(char *filename);
int		mapname(char *filename);
void	validmap(char *filename);
int		window_destroyer(int key, t_vars *vars);
int		right_move(int key, t_vars *var);
void	upper_wall(t_vars *var);
void	left_wall(t_vars *var);
void	lower_wall(t_vars *var);
void	right_wall(t_vars *var);
void	coll(t_vars *var);
void	obs(t_vars *var);
void	player(t_vars *var);
void	exit_game(t_vars *var);
void	map_read(char *filename, t_vars *var);
int	    player_up(int key, t_vars *var);
int     up_move(int key, t_vars *var);
int     keys(int key, t_vars *var);
int    	player_down(int key, t_vars *var);
int     down_move(int key, t_vars *var);
int	    player_left(int key, t_vars *var);
int     left_move(int key, t_vars *var);
int		count(t_vars *var);
char    **map_read2(t_vars *var);
void	playerone(t_vars *var);
void	playertwo(t_vars *var);
void	playerthree(t_vars *var);
int		right(int key, t_vars *var);
int		count2(char	**s);
void	rightimg1(t_vars *var);
void	rightimg2(t_vars *var);
void	rightimg3(t_vars *var);
void	rightmove1(t_vars *var);
void	show_player(t_vars *var);
int		player_right(int key, t_vars *var);
void	upper_img(t_vars *var);
void	down_evolution(int count, t_vars *var);
void	up_evolution(int count, t_vars *var);
void	right_evolution(int count, t_vars *var);
void	left_evolution(int count, t_vars *var);
void	exit_xy(t_vars *var);
int		collectibles(char *filename);
int		exit_i(t_vars *var);
int		exit_j(t_vars *var);
int		coll_scan(t_vars *var);
void	exit_win(int key, t_vars *var);
int		right_exit(int key, t_vars *var);
int		left_exit(int key, t_vars *var);
int		up_exit(int key, t_vars *var);
int		down_exit(int key, t_vars *var);
int		james_moves(t_vars *var);
void	enemyone(t_vars *var);
void	enemytwo(t_vars *var);
void	enemythree(t_vars *var);
void	show_james(t_vars *var);
void	show_jessie(t_vars *var);
void	show_giovanni(t_vars *var);
void	show_meowth(t_vars *var);
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
void	meowth_img(t_vars *var);
int		meowth_animated(t_vars *var);



#endif