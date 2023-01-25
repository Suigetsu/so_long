/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:55:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 15:35:30 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int ac, char **av)
{
	t_vars			var;
	t_additionals	mapcpy;

	ft_bzero(&var, sizeof(t_vars));
	(void)ac;
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (0);
	validmap(av[1]);
	map_read(av[1], &var);
	map_copy(&var, &mapcpy);
	player_finder(&var, &mapcpy);
	valid_path(&var, &mapcpy);
	var.win = mlx_new_window(var.mlx, var.w_h.width * 64, \
				var.w_h.height * 64, "pokebonus");
	if (var.win == NULL)
		free_pokemon(&var);
	printmap(&var);
	exit_xy(&var);
	mlx_hook(var.win, 17, 0, destroy_with_mouse, &var);
	mlx_hook(var.win, 2, 0, keys, &var);
	mlx_loop_hook(var.mlx, enemies_hook, &var);
	mlx_loop(var.mlx);
}
