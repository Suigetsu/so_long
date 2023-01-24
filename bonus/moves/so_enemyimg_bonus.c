/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_enemyimg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:35:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/23 23:21:01 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	enemyone(t_vars *var)
{
	var->e1.o_uppath = "textures/xpm/Enemies/Enemy01/up1673351254.xpm";
	var->e1.o_downpath = "textures/xpm/Enemies/Enemy01/down1673351254.xpm";
	var->e1.o_rightpath = "textures/xpm/Enemies/Enemy01/right1673351254.xpm";
	var->e1.o_leftpath = "textures/xpm/Enemies/Enemy01/left1673351253.xpm";
	var->e1.oneup = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_uppath, &var->img_x, &var->img_y);
	if (!var->e1.oneup)
		free_pokemon(var);
	var->e1.onedown = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_downpath, &var->img_x, &var->img_y);
	if (!var->e1.onedown)
		free_pokemon(var);
	var->e1.oneright = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_rightpath, &var->img_x, &var->img_y);
	if (!var->e1.oneright)
		free_pokemon(var);
	var->e1.oneleft = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_leftpath, &var->img_x, &var->img_y);
	if (!var->e1.oneleft)
		free_pokemon(var);
}

void	enemytwo(t_vars *var)
{
	var->e2.to_uppath = "textures/xpm/Enemies/Enemy02/up1673351230.xpm";
	var->e2.to_downpath = "textures/xpm/Enemies/Enemy02/down1673351230.xpm";
	var->e2.to_rightpath = "textures/xpm/Enemies/Enemy02/right1673351231.xpm";
	var->e2.to_leftpath = "textures/xpm/Enemies/Enemy02/left1673351230.xpm";
	var->e2.twoup = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_uppath, &var->img_x, &var->img_y);
	if (!var->e2.twoup)
		free_pokemon(var);
	var->e2.twodown = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_downpath, &var->img_x, &var->img_y);
	if (!var->e2.twodown)
		free_pokemon(var);
	var->e2.tworight = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_rightpath, &var->img_x, &var->img_y);
	if (!var->e2.tworight)
		free_pokemon(var);
	var->e2.twoleft = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_leftpath, &var->img_x, &var->img_y);
	if (!var->e2.twoleft)
		free_pokemon(var);
}

void	enemythree(t_vars *var)
{
	var->e3.th_uppath = "textures/xpm/Enemies/Enemy03/up1673351207.xpm";
	var->e3.th_downpath = "textures/xpm/Enemies/Enemy03/down1673351207.xpm";
	var->e3.th_rightpath = "textures/xpm/Enemies/Enemy03/right1673351207.xpm";
	var->e3.th_leftpath = "textures/xpm/Enemies/Enemy03/left1673351207.xpm";
	var->e3.threeup = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_uppath, &var->img_x, &var->img_y);
	if (!var->e3.threeup)
		free_pokemon(var);
	var->e3.threedown = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_downpath, &var->img_x, &var->img_y);
	if (!var->e3.threedown)
		free_pokemon(var);
	var->e3.threeright = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_rightpath, &var->img_x, &var->img_y);
	if (!var->e3.threeright)
		free_pokemon(var);
	var->e3.threeleft = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_leftpath, &var->img_x, &var->img_y);
	if (!var->e3.threeleft)
		free_pokemon(var);
}

void	meowth(t_vars *var)
{
	var->meowth.uppath = "textures/xpm/Enemies/Meowth/up1673351178.xpm";
	var->meowth.downpath = "textures/xpm/Enemies/Meowth/down1673351177.xpm";
	var->meowth.rightpath = "textures/xpm/Enemies/Meowth/right1673351177.xpm";
	var->meowth.leftpath = "textures/xpm/Enemies/Meowth/left1673351177.xpm";
	var->meowth.up = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.uppath, &var->img_x, &var->img_y);
	if (!var->meowth.up)
		free_pokemon(var);
	var->meowth.down = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.downpath, &var->img_x, &var->img_y);
	if (!var->meowth.down)
		free_pokemon(var);
	var->meowth.right = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.rightpath, &var->img_x, &var->img_y);
	if (!var->meowth.right)
		free_pokemon(var);
	var->meowth.left = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.leftpath, &var->img_x, &var->img_y);
	if (!var->meowth.left)
		free_pokemon(var);
}
