/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:27:06 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/02 09:54:22 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(void)
{
	t_vars	var;
	int     i;
	int     j;
	
	i = 0;
	j = 0;
	var.mlx = mlx_init();
	map_read(&var);
	int mok = 0;
	while(mok < var.w_h.height)
		ft_printf("%s\n", var.w_h.game[mok++]);
	var.win = mlx_new_window(var.mlx, var.w_h.width * 64, var.w_h.height * 64, "test");
    // mlx_hook(var.win, 2, 0, keys, &var);
    upper_wall(&var);
    left_wall(&var);
    lower_wall(&var);
    right_wall(&var);
    obs(&var);
    coll(&var);
    player(&var);
    player_up(&var);
    player_down(&var);
    player_left(&var);
    playerone(&var);
    playertwo(&var);
    playerthree(&var);
    show_player(&var);
    exit_game(&var);
    mlx_hook(var.win, 2, 0, keys, &var);
	mlx_loop(var.mlx);
}