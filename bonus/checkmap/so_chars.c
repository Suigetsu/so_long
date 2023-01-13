/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:39:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/13 19:04:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	mapchars(char *filename)
{
	t_mapchar	test;
	int			fd;
	char		*s;

	test.col_count = 0;
	test.ext_count = 0;
	test.strt_count = 0;
	test.schar_count = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strchr(s, '0') == 0 && ft_strchr(s, '1') == 0)
		{
			free (s);
			return (0);
		}
		test.col_count += collectibles_nbr(s);
		test.strt_count += starting_pt(s);
		test.ext_count += exits(s);
		test.schar_count += strangechars(s);
		free (s);
		s = get_next_line(fd);
	}
	free (s);
	close(fd);
	if (test.col_count <= 0 || test.ext_count <= 0 || test.ext_count > 1
		|| test.strt_count <= 0 || test.strt_count > 1 || test.schar_count > 0)
		return (0);
	return (1);
}
