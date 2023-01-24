/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_printmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:02:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/24 22:31:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
	animation_img(var);
	show_player(var);
	show_james(var);
	show_jessie(var);
	show_giovanni(var);
	show_meowth(var);
}
