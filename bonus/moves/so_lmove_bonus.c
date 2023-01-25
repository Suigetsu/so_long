/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lmove_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:37:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	leftimg1(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p1.oneleft1, (var->j - 1) * 64, var->i * 64);
}

static void	leftimg2(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p2.twoleft1, (var->j - 1) * 64, var->i * 64);
}

static void	leftimg3(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, \
	var->img.bg, var->j * 64, var->i * 64);
	mlx_put_image_to_window(var->mlx, var->win, \
	var->p3.threeleft1, (var->j - 1) * 64, var->i * 64);
}

void	left_evolution(int count, t_vars *var)
{
	if (count >= 2 && count < 4)
		leftimg2(var);
	else if (count >= 4)
		leftimg3(var);
	else
		leftimg1(var);
}
