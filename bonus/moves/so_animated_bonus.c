/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_animated_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 15:30:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	animation_img(t_vars *var)
{
	var->anim.framepath1 = "textures/xpm/world/01_fire.xpm";
	var->anim.framepath2 = "textures/xpm/world/02_fire.xpm";
	var->anim.framepath3 = "textures/xpm/world/03_fire.xpm";
	var->anim.frame1 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath1, &var->img_x, &var->img_y);
	if (!var->anim.frame1)
		free_pokemon(var);
	var->anim.frame2 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath2, &var->img_x, &var->img_y);
	if (!var->anim.frame2)
		free_pokemon(var);
	var->anim.frame3 = mlx_xpm_file_to_image(var->mlx, \
						var->anim.framepath3, &var->img_x, &var->img_y);
	if (!var->anim.frame3)
		free_pokemon(var);
}

int	animation(t_vars *var)
{
	static int	step;

	step++;
	if (step == 300)
	{
		if (rand() % 3 == 0)
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame1, \
			0, 0);
		else if (rand() % 4 == 1)
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame2, \
			0, 0);
		else
			mlx_put_image_to_window(var->mlx, var->win, var->anim.frame3, \
			0, 0);
		step = 0;
	}
	return (0);
}
