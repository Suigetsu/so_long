/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:42:54 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/07 19:14:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	collectibles_nbr(char *s)
{
	t_mapchar	c;
	int			index;

	index = 0;
	c.col_count = 0;
	while (s[index] && s[index] != '\n')
	{
		if (s[index] == 'C')
			c.col_count += 1;
		index++;
	}
	if (c.col_count > 0)
		return (1);
	else
		return (0);
}

int	exits(char *s)
{
	t_mapchar	c;
	int			index;

	index = 0;
	c.ext_count = 0;
	while (s[index] && s[index] != '\n')
	{
		if (s[index] == 'E')
			c.ext_count += 1;
		index++;
	}
	return (c.ext_count);
}

int	starting_pt(char *s)
{
	t_mapchar	c;
	int			index;

	index = 0;
	c.strt_count = 0;
	while (s[index] && s[index] != '\n')
	{
		if (s[index] == 'P')
			c.strt_count += 1;
		index++;
	}
	return (c.strt_count);
}

int	strangechars(char *s)
{
	int			index;

	index = 0;
	while (s[index] && s[index] != '\n')
	{
		if (s[index] != 'C' && s[index] != 'E' && s[index] != 'P'
			&& s[index] != '0' && s[index] != '1')
			return (1);
		index++;
	}
	return (0);
}
