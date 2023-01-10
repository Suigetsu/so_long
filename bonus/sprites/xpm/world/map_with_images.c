/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_with_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:46:58 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/20 11:22:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../../../headers/so_long.h"
typedef struct s_path
{
    char    *path_bg;
    char    *path_tree;
    char    *path_p1;
    char    *path_col;
    char    *path_exit;
}               t_path;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_x;
	int		img_y;
    t_path  path;
    char    **map;
    void    *i;
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

void    my_read(t_vars *var)
{
    int     fd;
    char    *s;
    
    fd = open("../../../map/maptest.ber", O_RDONLY);
    s = get_next_line(fd);
    var->img_x = ft_strlen(s) - 1;
    var->img_y = 0;
    var->map[0] = ft_strdup(s);
    var->img_y += 1;
    free (s);
    while (s)
    {
        s = get_next_line(fd);
        if (!s)
            break;
        var->map[var->img_y] = ft_strjoin(var->map[var->img_y], s);
        var->img_y += 1;
    }
}

int	main(void)
{
	t_vars	var;
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 600, 300, "new_window");
    my_read(&var);
    ft_printf("%s", var.map);
    var.path.path_bg = "Grass01.xpm";
    var.path.path_tree = "Tree01.xpm";
    var.img = mlx_xpm_file_to_image(var.mlx, var.path.path_bg, &var.img_x, &var.img_y);
    var.i = mlx_xpm_file_to_image(var.mlx, var.path.path_tree, &var.img_x, &var.img_y);
    mlx_hook(var.win, 2, 0, window_destroyer, &var);
    mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
    mlx_put_image_to_window(var.mlx, var.win, var.i, 0, 0);
	mlx_loop(var.mlx);
}
