/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_maputils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:42:54 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/20 22:31:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	collectibles_nbr(char *s)
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

static int	exits(char *s)
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

static int	starting_pt(char *s)
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

static int	strangechars(char *s)
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

int	mapchars(char *filename)
{
	t_mapchar	test;
	int			fd;
	char		*s;

	test.col_count = 0;
	test.schar_count = 0;
	test.ext_count = 0;
	test.strt_count = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strchr(s, '0') == 0 && ft_strchr(s, '1') == 0)
			return (0);
		test.col_count += collectibles_nbr(s);
		test.strt_count += starting_pt(s);
		test.ext_count += exits(s);
		test.schar_count += strangechars(s);
		free (s);
		s = get_next_line(fd);
	}
	free (s);
	if (test.col_count <= 0 || test.ext_count <= 0 || test.ext_count > 1
		|| test.strt_count <= 0 || test.strt_count > 1 || test.schar_count > 0)
		return (0);
	return (1);
}
