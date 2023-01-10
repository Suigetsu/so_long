/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:18:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/08 15:06:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc(len * sizeof(char) + 1);
	if (s == NULL || sub == NULL)
		return (NULL);
	while (s[start] != '\0' && i < (int )len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
