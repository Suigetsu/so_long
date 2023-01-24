/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_invalidmsg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:45:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/23 23:37:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	validmap(char *filename)
{
	if (mapchars(filename) <= 0)
	{
		ft_printf("Error\nInvalide/missing characters\n");
		exit (1);
	}
	if (wall_of_maria(filename) <= 0)
	{
		ft_printf("Error\nMap is not surrounded with walls\n");
		exit (1);
	}
	if (maprectangle(filename) <= 0)
	{
		ft_printf("Error\nMap is not rectangle\n");
		exit (1);
	}
	if (mapname(filename) != 0)
	{
		ft_printf("Error\nMap's name is not valid\n");
		exit (1);
	}
}
