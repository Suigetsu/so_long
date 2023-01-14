/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:02:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/13 20:04:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printmap(t_vars *var)
{
	upper_img(var);
	upper_wall(var);
    left_wall(var);
    lower_wall(var);
    right_wall(var);
    obs(var);
    coll(var);
	playerone(var);
	playertwo(var);
	playerthree(var);
    show_player(var);
}