/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exitmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:34:45 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 22:45:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	right_exit(int key, t_vars *var)
{
	(void)key;
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i][var->j + 1] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.exit, (var->j + 1) * 64, var->i * 64);
				ft_printf("Congrats!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	left_exit(int key, t_vars *var)
{
	(void)key;
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i][var->j - 1] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.exit, (var->j - 1) * 64, var->i * 64);
				ft_printf("Congrats!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	up_exit(int key, t_vars *var)
{
	(void)key;
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i - 1][var->j] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.exit, var->j * 64, (var->i - 1) * 64);
				ft_printf("Congrats!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	down_exit(int key, t_vars *var)
{
	(void)key;
	var->i = 1;
	while (var->i < var->w_h.height - 1)
	{
		var->j = 1;
		while (var->j < var->w_h.width - 1)
		{
			if (var->w_h.game[var->i][var->j] == 'P' \
				&& var->w_h.game[var->i + 1][var->j] == 'E')
			{
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.bg, var->j * 64, var->i * 64);
				mlx_put_image_to_window(var->mlx, var->win, \
				var->img.exit, var->j * 64, (var->i + 1) * 64);
				ft_printf("Congrats!\n");
				exit(0);
			}
			var->j++;
		}
		var->i++;
	}
	return (0);
}
