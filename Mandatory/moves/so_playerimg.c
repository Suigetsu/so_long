/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_playerimg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:23:03 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 12:44:30 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	playerone(t_vars *var)
{
	var->p1.o_rightpath1 = "sprites/xpm/01/01_right011671529027.xpm";
	var->p1.o_uppath1 = "sprites/xpm/01/01_up011671529028.xpm";
	var->p1.o_leftpath1 = "sprites/xpm/01/01_left011671529027.xpm";
	var->p1.o_downpath1 = "sprites/xpm/01/01_down01.xpm";
	var->p1.oneright1 = mlx_xpm_file_to_image(var->mlx, \
						var->p1.o_rightpath1, &var->img_x, &var->img_y);
	if (!var->p1.oneright1)
		exit(1);
	var->p1.oneup1 = mlx_xpm_file_to_image(var->mlx, \
						var->p1.o_uppath1, &var->img_x, &var->img_y);
	if (!var->p1.oneup1)
		exit(1);
	var->p1.oneleft1 = mlx_xpm_file_to_image(var->mlx, \
						var->p1.o_leftpath1, &var->img_x, &var->img_y);
	if (!var->p1.oneleft1)
		exit(1);
	var->p1.onedown1 = mlx_xpm_file_to_image(var->mlx, \
						var->p1.o_downpath1, &var->img_x, &var->img_y);
	if (!var->p1.onedown1)
		exit(1);
}

void	playertwo(t_vars *var)
{
	var->p2.to_rightpath1 = "sprites/xpm/02/02_right011671529175.xpm";
	var->p2.to_uppath1 = "sprites/xpm/02/02_up011671529176.xpm";
	var->p2.to_leftpath1 = "sprites/xpm/02/02_left011671529175.xpm";
	var->p2.to_downpath1 = "sprites/xpm/02/02_down011671529174.xpm";
	var->p2.tworight1 = mlx_xpm_file_to_image(var->mlx, \
						var->p2.to_rightpath1, &var->img_x, &var->img_y);
	if (!var->p2.tworight1)
		exit(1);
	var->p2.twoup1 = mlx_xpm_file_to_image(var->mlx, \
						var->p2.to_uppath1, &var->img_x, &var->img_y);
	if (!var->p2.twoup1)
		exit(1);
	var->p2.twoleft1 = mlx_xpm_file_to_image(var->mlx, \
						var->p2.to_leftpath1, &var->img_x, &var->img_y);
	if (!var->p2.twoleft1)
		exit(1);
	var->p2.twodown1 = mlx_xpm_file_to_image(var->mlx, \
						var->p2.to_downpath1, &var->img_x, &var->img_y);
	if (!var->p2.twodown1)
		exit(1);
}

void	playerthree(t_vars *var)
{
	var->p3.th_rightpath1 = "sprites/xpm/03/03_right011671529272.xpm";
	var->p3.th_uppath1 = "sprites/xpm/03/03_up011671529272.xpm";
	var->p3.th_leftpath1 = "sprites/xpm/03/03_left011671529271.xpm";
	var->p3.th_downpath1 = "sprites/xpm/03/03_down011671529271.xpm";
	var->p3.threeright1 = mlx_xpm_file_to_image(var->mlx, \
							var->p3.th_rightpath1, &var->img_x, &var->img_y);
	if (!var->p3.threeright1)
		exit(1);
	var->p3.threeup1 = mlx_xpm_file_to_image(var->mlx, \
							var->p3.th_uppath1, &var->img_x, &var->img_y);
	if (!var->p3.threeup1)
		exit(1);
	var->p3.threeleft1 = mlx_xpm_file_to_image(var->mlx, \
							var->p3.th_leftpath1, &var->img_x, &var->img_y);
	if (!var->p3.threeleft1)
		exit(1);
	var->p3.threedown1 = mlx_xpm_file_to_image(var->mlx, \
							var->p3.th_downpath1, &var->img_x, &var->img_y);
	if (!var->p3.threedown1)
		exit(1);
}
