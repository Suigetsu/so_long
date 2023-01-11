/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_enemyimg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:35:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/10 14:56:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	enemyone(t_vars *var)
{
	var->e1.o_uppath = "sprites/xpm/Enemies/Enemy01/up1673351254.xpm";
	var->e1.o_downpath = "sprites/xpm/Enemies/Enemy01/down1673351254.xpm";
	var->e1.o_rightpath = "sprites/xpm/Enemies/Enemy01/right1673351254.xpm";
	var->e1.o_leftpath = "sprites/xpm/Enemies/Enemy01/left1673351253.xpm";
	var->e1.oneup = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_uppath, &var->img_x, &var->img_y);
	var->e1.onedown = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_downpath, &var->img_x, &var->img_y);
	var->e1.oneright = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_rightpath, &var->img_x, &var->img_y);
	var->e1.oneleft = mlx_xpm_file_to_image(var->mlx, \
					var->e1.o_leftpath, &var->img_x, &var->img_y);
}

void	enemytwo(t_vars *var)
{
	var->e2.to_uppath = "sprites/xpm/Enemies/Enemy02/up1673351230.xpm";
	var->e2.to_downpath = "sprites/xpm/Enemies/Enemy02/down1673351230.xpm";
	var->e2.to_rightpath = "sprites/xpm/Enemies/Enemy02/right1673351231.xpm";
	var->e2.to_leftpath = "sprites/xpm/Enemies/Enemy02/left1673351230.xpm";
	var->e2.twoup = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_uppath, &var->img_x, &var->img_y);
	var->e2.twodown = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_downpath, &var->img_x, &var->img_y);
	var->e2.tworight = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_rightpath, &var->img_x, &var->img_y);
	var->e2.twoleft = mlx_xpm_file_to_image(var->mlx, \
					var->e2.to_leftpath, &var->img_x, &var->img_y);
}

void	enemythree(t_vars *var)
{
	var->e3.th_uppath = "sprites/xpm/Enemies/Enemy03/up1673351207.xpm";
	var->e3.th_downpath = "sprites/xpm/Enemies/Enemy03/down1673351207.xpm";
	var->e3.th_rightpath = "sprites/xpm/Enemies/Enemy03/right1673351207.xpm";
	var->e3.th_leftpath = "sprites/xpm/Enemies/Enemy03/left1673351207.xpm";
	var->e3.threeup = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_uppath, &var->img_x, &var->img_y);
	var->e3.threedown = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_downpath, &var->img_x, &var->img_y);
	var->e3.threeright = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_rightpath, &var->img_x, &var->img_y);
	var->e3.threeleft = mlx_xpm_file_to_image(var->mlx, \
					var->e3.th_leftpath, &var->img_x, &var->img_y);
}

void	meowth(t_vars *var)
{
	var->meowth.uppath = "sprites/xpm/Enemies/Meowth/up1673351178.xpm";
	var->meowth.downpath = "sprites/xpm/Enemies/Meowth/down1673351177.xpm";
	var->meowth.rightpath = "sprites/xpm/Enemies/Meowth/right1673351177.xpm";
	var->meowth.leftpath = "sprites/xpm/Enemies/Meowth/left1673351177.xpm";
	var->meowth.up = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.uppath, &var->img_x, &var->img_y);
	var->meowth.down = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.downpath, &var->img_x, &var->img_y);
	var->meowth.right = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.rightpath, &var->img_x, &var->img_y);
	var->meowth.left = mlx_xpm_file_to_image(var->mlx, \
					var->meowth.leftpath, &var->img_x, &var->img_y);
}