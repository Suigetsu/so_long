/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:52:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/19 16:37:03 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# define PIXEL_SIZE 64

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

typedef struct s_additionals
{
	char	**mapcopy;
}				t_additionals;


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
	char			**mapcopy;
	t_path			path;
	t_mapwh			w_h;
	t_img			img;
	t_playerone		p1;
	t_playertwo		p2;
	t_playerthree	p3;
}				t_vars;

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
int     up_move(t_vars *var);
int     keys(int key, t_vars *var);
int     down_move(t_vars *var);
int     left_move(t_vars *var);
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

#endif