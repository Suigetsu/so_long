/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:29:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/16 13:12:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	upper_img(t_vars *var)
{
	var->path.path_uwall = "sprites/xpm/world/upper_wall.xpm";
	var->path.path_ulwall = "sprites/xpm/world/first_wall.xpm";
	var->path.path_urwall = "sprites/xpm/world/last_wall.xpm";
}

void	upper_wall(t_vars *var)
{
	var->i = 0;
	var->j = 0;
	upper_img(var);
	var->img.upwall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_uwall, &var->img_x, &var->img_y);
	var->img.upl_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_ulwall, &var->img_x, &var->img_y);
	var->img.upr_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_urwall, &var->img_x, &var->img_y);
	while (var->w_h.game[var->i][var->j])
		{
			if (var->j == 0)
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.upl_wall, var->j * 64, var->i * 64);
			else if (var->j == (var->w_h.width - 1))
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.upr_wall, var->j * 64, var->i * 64);
			else if (var->w_h.game[var->i][var->j] == '1')
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.upwall, var->j * 64, var->i * 64);
			var->j++;
		}
}

void	left_wall(t_vars *var)
{
	var->i = 1;
	var->j = 1;
	var->path.path_lftwall = "sprites/xpm/world/left_wall.xpm";
	var->path.path_bg = "sprites/xpm/world/solid_ground.xpm";
	var->img.left_wall = mlx_xpm_file_to_image(var->mlx, \
							var->path.path_lftwall, &var->img_x, &var->img_y);
	var->img.bg = mlx_xpm_file_to_image(var->mlx, \
							var->path.path_bg, &var->img_x, &var->img_y);
	while (var->i < var->w_h.height - 1)
	{
		var->j = 0;
		while (var->j < var->w_h.width - 1)
		{
			if (var->j == 0)
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.left_wall, var->j * 64, var->i * 64);
			else
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.bg, var->j * 64, var->i * 64);
			var->j++;
		}
		var->i++;
	}
}

void	lower_wall(t_vars *var)
{
	var->i = var->w_h.height - 1;
	var->j = 0;
	var->path.path_lwall = "sprites/xpm/world/lower_wall.xpm";
	var->path.path_llwall = "sprites/xpm/world/02_first_wall.xpm";
	var->path.path_lrwall = "sprites/xpm/world/02_last_wall.xpm";
	var->img.lowall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lwall, &var->img_x, &var->img_y);
	var->img.lol_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_llwall, &var->img_x, &var->img_y);
	var->img.lor_wall = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_lrwall, &var->img_x, &var->img_y);
	while (var->w_h.game[var->i][var->j])
	{
		if (var->j == 0)
			mlx_put_image_to_window(var->mlx, \
			var->win, var->img.lol_wall, var->j * 64, var->i * 64);
		else if (var->j == (var->w_h.width - 1))
			mlx_put_image_to_window(var->mlx, \
			var->win, var->img.lor_wall, var->j * 64, var->i * 64);
		else if (var->w_h.game[var->i][var->j] == '1')
			mlx_put_image_to_window(var->mlx, \
			var->win, var->img.lowall, var->j * 64, var->i * 64);
		var->j++;
	}
}

void	right_wall(t_vars *var)
{
	var->i = 1;
	var->j = var->w_h.width - 1;
	var->path.path_rgtwall = "sprites/xpm/world/right_wall.xpm";
	var->img.right_wall = mlx_xpm_file_to_image(var->mlx, \
							var->path.path_rgtwall, &var->img_x, &var->img_y);
	while (var->i < var->w_h.height - 1)
	{
		mlx_put_image_to_window(var->mlx, \
		var->win, var->img.right_wall, var->j * 64, var->i * 64);
		var->i++;
	}
}