/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:20:11 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/22 13:08:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../headers/so_long.h"

typedef struct s_img
{
    void	*coll;
	void	*p1;
	void	*exit;
    void    *obs;
    void    *ul_wall;
    void    *ur_wall;
    void    *ll_wall;
    void    *lr_wall;
    void    *left_wall;
    void    *right_wall;
    void    *lwall;
}				t_img;

typedef struct s_map_wh
{
	int     w;
	int     h;
    char    **test;
}              t_map_wh;

typedef struct s_path
{
	char    *path_bg;
	char    *path_uwall;
    char    *path_lwall;
    char    *path_ulwall;
    char    *path_urwall;
    char    *path_llwall;
    char    *path_lrwall;
    char    *path_lftwall;
    char    *path_rgtwall;
	char    *path_p1;
	char    *path_col;
	char    *path_exit;
    char    *obs;
}               t_path;

typedef struct s_vars
{
	void	    *mlx;
	void	    *win;
	void	    *img;
	int		    img_x;
	int		    img_y;
	t_path      path;
	char        *map;
	void        *i;
	t_map_wh    wh;
	t_img		test;
}			t_vars;

int window_destroyer(int key, t_vars *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(1);    
	}
	return (0);
}

void    upper_wall(t_vars *var)
{
    int i;
    int j;

    i = 0;
    j = 0;
    var->path.path_uwall = "../sprites/xpm/world/upper_wall.xpm";
    var->path.path_ulwall = "../sprites/xpm/world/first_wall.xpm";
    var->path.path_urwall = "../sprites/xpm/world/last_wall.xpm";
    var->i = mlx_xpm_file_to_image(var->mlx, var->path.path_uwall, &var->img_x, &var->img_y);
    var->test.ul_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_ulwall, &var->img_x, &var->img_y);
    var->test.ur_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_urwall, &var->img_x, &var->img_y);
    while (i == 0)
    {
        while (var->wh.test[i][j])
        {
            if (j == 0)
                mlx_put_image_to_window(var->mlx, var->win, var->test.ul_wall, j*64, i*64);
            else if (j == (var->wh.w - 1))
                mlx_put_image_to_window(var->mlx, var->win, var->test.ur_wall, j*64, i*64);
            else if (var->wh.test[i][j] == '1')
                mlx_put_image_to_window(var->mlx, var->win, var->i, j*64, i*64);
            j++;
        }
        i++;
    }           
}

void    left_wall(t_vars *var)
{
    int i;
    int j;

    i = 1;
    var->path.path_lftwall = "../sprites/xpm/world/left_wall.xpm";
    var->path.path_bg = "../sprites/xpm/world/solid_ground.xpm";
    var->test.left_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_lftwall, &var->img_x, &var->img_y);
    var->img = mlx_xpm_file_to_image(var->mlx, var->path.path_bg, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        j = 0;
        while (j < var->wh.w - 1)
        {
            if (j == 0)
                mlx_put_image_to_window(var->mlx, var->win, var->test.left_wall, j*64, i*64);
            else
                mlx_put_image_to_window(var->mlx, var->win, var->img, j*64, i*64);
            j++;
        }
        i++;
    }
}

void    lower_wall(t_vars *var)
{
    int i;
    int j;

    i = var->wh.h - 1;
    j = 0;
    var->path.path_lwall = "../sprites/xpm/world/lower_wall.xpm";
    var->path.path_llwall = "../sprites/xpm/world/02_first_wall.xpm";
    var->path.path_lrwall = "../sprites/xpm/world/02_last_wall.xpm";
    var->test.lwall = mlx_xpm_file_to_image(var->mlx, var->path.path_lwall, &var->img_x, &var->img_y);
    var->test.ll_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_llwall, &var->img_x, &var->img_y);
    var->test.lr_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_lrwall, &var->img_x, &var->img_y);
    while (var->wh.test[i][j])
    {
        if (j == 0)
            mlx_put_image_to_window(var->mlx, var->win, var->test.ll_wall, j*64, i*64);
        else if (j == (var->wh.w - 1))
            mlx_put_image_to_window(var->mlx, var->win, var->test.lr_wall, j*64, i*64);
        else if (var->wh.test[i][j] == '1')
            mlx_put_image_to_window(var->mlx, var->win, var->test.lwall, j*64, i*64);
        j++;
    }           
}

void    right_wall(t_vars *var)
{
    int i;
    int j;

    i = 1;
    j = var->wh.w - 1;
    var->path.path_rgtwall = "../sprites/xpm/world/right_wall.xpm";
    var->test.right_wall = mlx_xpm_file_to_image(var->mlx, var->path.path_rgtwall, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        mlx_put_image_to_window(var->mlx, var->win, var->test.right_wall, j*64, i*64);
        i++;
    }
}

void    coll(t_vars *var)
{
    int i;
    int j;
    
    i = 1;
    var->path.path_col = "../sprites/xpm/collectibles/smallcandy.xpm";
    var->test.coll = mlx_xpm_file_to_image(var->mlx, var->path.path_col, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        j = 1;
        while (j < var->wh.w - 1)
        {
            if (var->wh.test[i][j] == 'C')
                mlx_put_image_to_window(var->mlx, var->win, var->test.coll, j*64, i*64);
            j++;
        }
        i++;
    }
}

void    obs(t_vars *var)
{
    int i;
    int j;
    
    i = 1;
    var->path.obs = "../sprites/xpm/world/lamp2.xpm";
    var->test.obs = mlx_xpm_file_to_image(var->mlx, var->path.obs, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        j = 1;
        while (j < var->wh.w - 1)
        {
            if (var->wh.test[i][j] == '1')
                mlx_put_image_to_window(var->mlx, var->win, var->test.obs, j*64, i*64);
            j++;
        }
        i++;
    }
}

void    player(t_vars *var)
{
    int i;
    int j;
    
    i = 1;
    var->path.path_p1 = "../sprites/xpm/01/01_right011671529027.xpm";
    var->test.p1 = mlx_xpm_file_to_image(var->mlx, var->path.path_p1, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        j = 1;
        while (j < var->wh.w - 1)
        {
            if (var->wh.test[i][j] == 'P')
                mlx_put_image_to_window(var->mlx, var->win, var->test.p1, j*64, i*64);
            j++;
        }
        i++;
    }
}

void    exit_game(t_vars *var)
{
    int i;
    int j;
    
    i = 1;
    var->path.path_exit = "../sprites/xpm/world/center1671710820.xpm";
    var->test.exit = mlx_xpm_file_to_image(var->mlx, var->path.path_exit, &var->img_x, &var->img_y);
    while (i < var->wh.h - 1)
    {
        j = 1;
        while (j < var->wh.w - 1)
        {
            if (var->wh.test[i][j] == 'E')
                mlx_put_image_to_window(var->mlx, var->win, var->test.exit, j*64, i*64);
            j++;
        }
        i++;
    }
}

void    map_read(t_vars *var)
{
	int     fd;
	int     i;
    int     j;
	char    *s;
	
	i = 1;
	fd = open("../map/maptest.ber", O_RDONLY);
	s = get_next_line(fd);
    var->wh.w = ft_strlen(s) - 1;
    var->wh.h = 1;
    var->map = ft_strdup(s);
    while (s)
    {
        s = get_next_line(fd);
        if (!s)
            {
                free (s);
                break;
            }
        var->map = ft_strjoin(var->map, s);
        var->wh.h += 1;
    }
    var->wh.test = ft_split(var->map, '\n');
}

int	main(void)
{
	t_vars	var;
	int     i;
	int     j;
	
	i = 0;
	j = 0;
	var.mlx = mlx_init();
	map_read(&var);
	int mok = 0;
	while(mok < var.wh.h)
		ft_printf("%s\n", var.wh.test[mok++]);
	var.win = mlx_new_window(var.mlx, var.wh.w * 64, var.wh.h * 64, "test");

	mlx_hook(var.win, 2, 0, window_destroyer, &var);
    upper_wall(&var);
    left_wall(&var);
    lower_wall(&var);
    right_wall(&var);
    obs(&var);
    coll(&var);
    player(&var);
    exit_game(&var);
	mlx_loop(var.mlx);
}