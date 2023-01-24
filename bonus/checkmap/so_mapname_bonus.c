/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mapname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:27:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/02 09:28:47 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	mapname(char *filename)
{
	char	*s;
	int		i;
	int		len;

	s = ".ber";
	i = 0;
	len = ft_strlen(filename);
	while (filename[len - 4] == s[i] && filename[len - 4] && s[i])
	{
		i++;
		len++;
	}
	return (filename[len - 4] - s[i]);
}
