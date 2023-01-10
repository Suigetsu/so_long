/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_upmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:39:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/04 14:58:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	upimg1(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p1.oneup1, var->j * 64, (var->i - 1) * 64);
}

void	upimg2(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p2.twoup1, var->j * 64, (var->i - 1) * 64);
}

void	upimg3(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p3.threeup1, var->j * 64, (var->i - 1) * 64);
}

void	up_evolution(int count, t_vars *var)
{
	if (count >= 2 && count < 4)
		upimg2(var);
	else if (count >= 4)
		upimg3(var);
	else
		upimg1(var);
}
