/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_rmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:30:34 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/03 20:16:27 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rightimg1(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p1.oneright1, (var->j + 1) * 64, var->i * 64);
}

void	rightimg2(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p2.tworight1, (var->j + 1) * 64, var->i * 64);
}

void	rightimg3(t_vars *var)
{

	var->w_h.game[var->i][var->j] = '0';
	var->w_h.game[var->i][var->j + 1] = 'P';
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p3.threeright1, (var->j + 1) * 64, var->i * 64);
}

void	right_evolution(int count, t_vars *var)
{
	if (count >= 2 && count < 4)
		rightimg2(var);
	else if (count >= 4)
		rightimg3(var);
	else
		rightimg1(var);
}
