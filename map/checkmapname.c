/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:25:19 by mlagrini          #+#    #+#             */
/*   Updated: 2022/12/24 08:58:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int mapname(char *filename)
{
    char    *s;
    int     i;
    int     len;

    s = ".ber";
    i = 0;
    len = ft_strlen(filename);
    while (filename[len - 4] == s[i] && filename[len - 4] && s[i])
    {
        i++;
        len++;
    }
    return(filename[len - 4] - s[i]);
}
