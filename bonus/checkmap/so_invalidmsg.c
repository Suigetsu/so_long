/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_invalidmsg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:45:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/09 18:49:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	validmap(char *filename)
{
	int			i;
	t_errors	*s;

	s = malloc (sizeof (t_errors));
	s->inv_char = "Error\nInvalide/missing characters";
	s->map_wall = "Error\nMap is not surrounded with walls";
	s->rect_map = "Error\nMap is not rectangle";
	s->map_name = "Error\nMap's name is not valid";
	i = mapchars(filename);
	if (i <= 0)
	{
		ft_printf("%s\n", s->inv_char);
		free (s);
		exit(1);
	}
	i = wall_of_maria(filename);
	if (i <= 0)
	{
		ft_printf("%s\n", s->map_wall);
		free (s);
		exit(1);
	}
	i = maprectangle(filename);
	if (i <= 0)
	{
		ft_printf("%s\n", s->rect_map);
		free (s);
		exit(1);
	}
	i = mapname(filename);
	if (i != 0)
	{
		ft_printf("%s\n", s->map_name);
		free (s);
		exit(1);
	}
	else
		free (s);
}
