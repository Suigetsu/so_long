/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:55:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:58 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
