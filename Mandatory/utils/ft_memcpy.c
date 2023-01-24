/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:44:20 by mlagrini          #+#    #+#             */
/*   Updated: 2023/01/21 17:49:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (0);
	while (n--)
	{
		*((char *)dst + n) = *((const char *)src + n);
	}
	return (dst);
}
