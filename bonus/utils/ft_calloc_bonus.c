/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:02:58 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc((count * size) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
