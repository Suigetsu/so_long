/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_downmove_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:41:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	downimg1(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p1.onedown1, var->j * 64, (var->i + 1) * 64);
}

static void	downimg2(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p2.twodown1, var->j * 64, (var->i + 1) * 64);
}

static void	downimg3(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p3.threedown1, var->j * 64, (var->i + 1) * 64);
}

void	down_evolution(int count, t_vars *var)
{
	if (count >= 2 && count < 4)
		downimg2(var);
	else if (count >= 4)
		downimg3(var);
	else
		downimg1(var);
}
