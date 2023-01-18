/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_animeowth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:27:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/17 15:05:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	meowth_img(t_vars *var)
{
	var->meowth.path1 = "sprites/xpm/Enemies/Meowth/1frame1673800129.xpm";
	var->meowth.path2 = "sprites/xpm/Enemies/Meowth/2frame1673800129.xpm";
	var->meowth.f1 = mlx_xpm_file_to_image(var->mlx, \
						var->meowth.path1, &var->img_x, &var->img_y);
	var->meowth.f2 = mlx_xpm_file_to_image(var->mlx, \
						var->meowth.path2, &var->img_x, &var->img_y);
}

static void	meowth_anim(t_vars *var)
{
	var->i = 0;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 0;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'T')
			{
				mlx_put_image_to_window(var->mlx, var->win, var->meowth.f1, var->i * 64, var->j * 64);
			}
			var->j++;
		}
		var->i++;
	}
}

int	meowth_animated(t_vars *var)
{
	meowth_anim(var);
	return (0);
}