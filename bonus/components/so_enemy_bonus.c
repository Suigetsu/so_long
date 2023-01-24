/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/23 14:53:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	show_james(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'A')
			{
				enemyone(var);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e1.oneright, var->j * 64, var->i * 64);
			}
			var->j++;
		}
		var->i++;
	}
}

void	show_jessie(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'B')
			{
				enemytwo(var);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e2.twoleft, var->j * 64, var->i * 64);
			}
			var->j++;
		}
		var->i++;
	}
}

void	show_giovanni(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'G')
			{
				enemythree(var);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->e3.threeright, var->j * 64, var->i * 64);
			}
			var->j++;
		}
		var->i++;
	}
}

void	show_meowth(t_vars *var)
{
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'M')
			{
				meowth(var);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->meowth.left, var->j * 64, var->i * 64);
			}
			var->j++;
		}
		var->i++;
	}
}
