/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:24:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/13 18:44:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_splitvar
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		count;
	char	**strings;
	char	*ptr;
}				t_splitvar;

static int	wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c)
				count += 1;
		}
	}
	return (count);
}

static int	wordlen(char *s, char c)
{
	static int	o;
	int			len;

	len = 1;
	while (s[o] != '\0')
	{
		while (s[o] == c)
			o++;
		while (s[o] != c && s[o] != '\0')
		{
			o++;
			len++;
			if (s[o] == c)
				return (len);
		}
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	t_splitvar	var;

	var.i = 0;
	var.k = 0;
	var.strings = ft_calloc ((wordcount((char *)s, c) + 1), sizeof(char *));
	if (var.strings == NULL)
		return (NULL);
	while (s[var.i] != '\0')
	{
		while (s[var.i] == c)
			var.i++;
		if (s[var.i] == '\0')
			break ;
		var.len = wordlen((char *)s, c);
		var.strings[var.k] = ft_calloc (((var.len) + 1), sizeof(char));
		if (var.strings[var.k] == NULL)
			return (NULL);
		var.j = 0;
		while (s[var.i] != c && s[var.i] != '\0')
			var.strings[var.k][var.j++] = s[var.i++];
		var.k++;
	}
	return (var.strings);
}
