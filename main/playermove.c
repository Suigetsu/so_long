/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:17:13 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/31 18:07:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rightimg1(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
    mlx_put_image_to_window(var->mlx, var->win, var->p1.oneright1, (var->j + 1) * 64, var->i * 64);
}

void	rightimg2(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
    mlx_put_image_to_window(var->mlx, var->win, var->p2.tworight1, (var->j + 1) * 64, var->i * 64);
}

void	rightimg3(t_vars *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
    mlx_put_image_to_window(var->mlx, var->win, var->p3.threeright1, (var->j + 1) * 64, var->i * 64);
}

void	rightmove1(t_vars *var)
{
	int		c;
	int		c2;
	char	**s;
	
	s = map_read2(var);
	c = count2(s);
	var->w_h.game[var->i][var->j] = '0';
	var->w_h.game[var->i][var->j + 1] = 'P';
	c2 = count(var);
	ft_printf("%d, %d\n", c, c2);
	if (c2 == c)
	{
	mlx_put_image_to_window(var->mlx, var->win, var->img.bg, var->j * 64, var->i * 64);
    mlx_put_image_to_window(var->mlx, var->win, var->p1.oneright1, (var->j + 1) * 64, var->i * 64);
	}
	else if (c2 >= c - 3)
		rightimg2(var);
	else
		rightimg3(var);
}