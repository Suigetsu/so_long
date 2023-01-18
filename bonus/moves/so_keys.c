/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:57:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/17 15:03:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	window_destroyer(int key, t_vars *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(1);
	}
	return (0);
}

int	keys(int key, t_vars *var)
{
	int	i;

	if (coll_scan(var) == 1)
		exit_win(key, var);
	if (key == 2)
	{
		james_exit(var);
		jessie_exit(var);
		giovanni_exit(var);
		meowth_exit(var);
		i = right_move(key, var);
	}
	else if (key == 13)
	{
		james_exit(var);
		jessie_exit(var);
		giovanni_exit(var);
		meowth_exit(var);
		i = up_move(key, var);
	}
	else if (key == 1)
	{
		james_exit(var);
		jessie_exit(var);
		giovanni_exit(var);
		meowth_exit(var);
		i = down_move(key, var);
	}
	else if (key == 0)
	{
		james_exit(var);
		jessie_exit(var);
		giovanni_exit(var);
		meowth_exit(var);
		i = left_move(key, var);
	}
	else if (key == 53)
		i = window_destroyer(key, var);
	return (0);
}

void	exit_win(int key, t_vars *var)
{
	int	i;

	exit_game(var);
		if (key == 2)
			i = right_exit(key, var);
		else if (key == 13)
			i = up_exit(key, var);
		else if (key == 1)
			i = down_exit(key, var);
		else if (key == 0)
			i = left_exit(key, var);
		else if (key == 53)
			i = window_destroyer(key, var);
}

int	enemies_hook(t_vars *var)
{
	meowth_animated(var);
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