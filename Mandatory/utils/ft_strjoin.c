/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:54:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		s1 = malloc (1);
		*s1 = '\0';
	}
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
		cat[i++] = s2[j++];
	cat[i] = '\0';
	return (cat);
}
