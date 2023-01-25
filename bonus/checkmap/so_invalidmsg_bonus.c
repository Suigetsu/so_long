/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_invalidmsg_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:45:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	validmap(char *filename)
{
	t_vars	*var;

	var = NULL;
	if (mapchars(filename) <= 0)
	{
		ft_printf("Error\nInvalide/missing characters\n");
		free_pokemon(var);
	}
	if (wall_of_maria(filename) <= 0)
	{
		ft_printf("Error\nMap is not surrounded with walls\n");
		free_pokemon(var);
	}
	if (maprectangle(filename) <= 0)
	{
		ft_printf("Error\nMap is not rectangle\n");
		free_pokemon(var);
	}
	if (mapname(filename) != 0)
	{
		ft_printf("Error\nMap's name is not valid\n");
		free_pokemon(var);
	}
}
