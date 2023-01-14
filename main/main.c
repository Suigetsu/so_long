/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:55:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/13 20:05:50 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int ac, char **av)
{
	t_vars	var;
	
	(void)ac;
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (1);
	validmap(av[1]);
	map_read(av[1], &var);
	var.win = mlx_new_window(var.mlx, var.w_h.width * 64, var.w_h.height * 64, "poketest");
	if (var.win == NULL)
	{
		free (var.win);
		return (1);
	}
	printmap(&var);
	exit_xy(&var);
	mlx_hook(var.win, 2, 0, keys, &var);
	mlx_loop(var.mlx);
}