/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_others_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:41:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/23 23:21:01 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	coll(t_vars *var)
{
	var->i = 1;
	var->path.path_col = "textures/xpm/collectibles/smallcandy.xpm";
	var->img.coll = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_col, &var->img_x, &var->img_y);
	if (!var->img.coll)
		free_pokemon(var);
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'C')
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.coll, var->j * 64, var->i * 64);
			var->j++;
		}
		var->i++;
	}
}

void	obs(t_vars *var)
{
	var->i = 1;
	var->path.obs = "textures/xpm/world/lamp2.xpm";
	var->img.obs = mlx_xpm_file_to_image(var->mlx, \
					var->path.obs, &var->img_x, &var->img_y);
	if (!var->img.obs)
		free_pokemon(var);
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == '1')
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.obs, var->j * 64, var->i * 64);
			var->j++;
		}
		var->i++;
	}
}

void	exit_game(t_vars *var)
{
	var->i = 1;
	var->path.path_exit = "textures/xpm/world/center1671710820.xpm";
	var->img.exit = mlx_xpm_file_to_image(var->mlx, \
						var->path.path_exit, &var->img_x, &var->img_y);
	if (!var->img.exit)
		free_pokemon(var);
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'E')
				mlx_put_image_to_window(var->mlx, \
				var->win, var->img.exit, var->j * 64, var->i * 64);
			var->j++;
		}
		var->i++;
	}
}

void	show_player(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P')
			{
				playerone(var);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->p1.oneright1, var->j * 64, var->i * 64);
			}
			var->j++;
		}
	var->i++;
	}
}

int	coll_scan(t_vars *var)
{
	var->i = 1;
	while (var->w_h.game[var->i])
	{
		if (ft_strchr(var->w_h.game[var->i], 'C') == 0)
			var->i++;
		else
			return (0);
	}
	return (1);
}
