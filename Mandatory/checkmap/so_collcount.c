/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_collcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 04:12:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/03 04:38:41 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	collectibles(char *filename)
{
	char	*s;
	char	*joined;
	int		fd;
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	joined = ft_strdup(s);
	free (s);
	while (s)
	{
		s = get_next_line(fd);
		if (!s)
		{
			close (fd);
			free (s);
			break ;
		}
		joined = ft_strjoin(joined, s);
		free (s);
	}
	while (joined[i])
	{
		if (joined[i] == 'C')
			count += 1;
		i++;
	}
	free (joined);
	return (count);
}