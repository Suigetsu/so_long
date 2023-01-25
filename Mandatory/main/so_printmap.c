/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:02:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	printmap(t_vars *var)
{
	upper_wall(var);
	left_wall(var);
	lower_wall(var);
	right_wall(var);
	coll(var);
	obs(var);
	playerone(var);
	playertwo(var);
	playerthree(var);
	show_player(var);
}
