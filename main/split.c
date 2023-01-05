
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:04 by mlagrini          #+#    #+#             */
/*   Updated: 2022/10/15 21:14:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char *s, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 1;
	len = ft_strlen(s);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] != c && i < len)
		{
			i++;
			if (s[i] == c)
				count++;
		}
	}
	return (count);
}

static void	my_allocator(char **dst, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	dst[i] = malloc ((len + 1) * sizeof(char));
	ft_memcpy(dst[i], s, (ft_strlen(s) + 1));
    // free (s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**strings;
	char	*ptr;

	i = 0;
	k = 0;
	strings = ft_calloc((wordcount((char *)s, c) + 1), sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
		j = 0;
		if (s[i] == c)
			i++;
		while (s[i] != c && (size_t)i < ft_strlen(s))
			ptr[j++] = ((char *)s)[i++];
		if (j > 0)
			my_allocator(&strings[k++], ptr);
	}
	return (strings);
}