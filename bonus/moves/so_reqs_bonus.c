/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_reqs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:39:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	enemies_hook(t_vars *var)
{
	animation(var);
	james_moves(var);
	jessie_moves(var);
	giovanni_moves(var);
	meowth_moves(var);
	return (0);
}

void	move_counter(int movecount, t_vars *var)
{
	var->counter = ft_itoa(movecount);
	mlx_put_image_to_window(var->mlx, var->win, \
				var->img.lowall, 64, (var->w_h.height * 64) - 64);
	mlx_put_image_to_window(var->mlx, var->win, \
				var->img.lowall, 64 * 2, (var->w_h.height * 64) - 64);
	mlx_put_image_to_window(var->mlx, var->win, \
				var->img.lowall, 64 * 3, (var->w_h.height * 64) - 64);
	mlx_put_image_to_window(var->mlx, var->win, \
				var->img.lowall, 64 * 4, (var->w_h.height * 64) - 64);
	mlx_string_put(var->mlx, var->win, 64, \
				(var->w_h.height * 64) - 35, 0x000000, "Movemenet count: ");
	mlx_string_put(var->mlx, var->win, 64 * 4, \
				(var->w_h.height * 64) - 35, 0x000000, var->counter);
	free (var->counter);
}
