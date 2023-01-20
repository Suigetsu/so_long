/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_animated.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 22:45:43 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	animation_img(t_vars *var)
{
	var->anim.framepath1 = "sprites/xpm/world/01_fire.xpm";
	var->anim.framepath2 = "sprites/xpm/world/02_fire.xpm";
	var->anim.framepath3 = "sprites/xpm/world/03_fire.xpm";
	var->anim.frame1 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath1, &var->img_x, &var->img_y);
	var->anim.frame2 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath2, &var->img_x, &var->img_y);
	var->anim.frame3 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath3, &var->img_x, &var->img_y);
}

int	animation(t_vars *var)
{
	static int	step;

	step++;
	srand(time(0));
	if (step == 5000)
	{
		if (rand() % 3 == 0)
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame1, \
			0, 64);
		else if (rand() % 4 == 1)
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame2, \
			0, 64);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame3, \
			0, 64);
		step = 0;
	}
	return (0);
}
