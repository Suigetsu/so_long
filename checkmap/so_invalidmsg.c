/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_invalidmsg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:45:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/02 09:48:13 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	validmap(char *filename)
{
	int			i;
	t_errors	*s;

	s->inv_char = "Error\nInvalide/missing characters";
	s->map_wall = "Error\nMap is not surrounded with walls";
	s->rect_map = "Error\nMap is not rectangle";
	s->map_name = "Error\nMap's name is not valid";
	i = mapchars(filename);
	if (i <= 0)
		ft_printf("%s\n", s->inv_char);
	i = wall_of_maria(filename);
	if (i <= 0)
		ft_printf("%s\n", s->map_wall);
	i = maprectangle(filename);
	if (i <= 0)
		ft_printf("%s\n", s->rect_map);
	i = mapname(filename);
	if (i != 0)
		ft_printf("%s\n", s->map_name);
}
