/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:08:10 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/27 15:56:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    map_read(t_vars *var)
{
	int     fd;
	char    *s;
	
	fd = open("../map/maptest.ber", O_RDONLY);
	s = get_next_line(fd);
    var->w_h.width = ft_strlen(s) - 1;
    var->w_h.height = 1;
    var->w_h.map = ft_strdup(s);
    free (s);
    while (s)
    {
        s = get_next_line(fd);
        if (!s)
            {
                close (fd);
                free (s);
                break;
            }
        var->w_h.map = ft_strjoin(var->w_h.map, s);
        free (s);
        var->w_h.height += 1;
    }
    var->w_h.game = ft_split(var->w_h.map, '\n');
    free (var->w_h.map);
}
