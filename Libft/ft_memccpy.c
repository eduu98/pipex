/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:44:52 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/23 12:48:34 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	i = 0;
	dstptr = (unsigned char *)dst;
	srcptr = (unsigned char *)src;
	while (i < n && srcptr[i] != (unsigned char)c)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	if (srcptr[i] == (unsigned char)c && i < n)
	{
		dstptr[i] = srcptr[i];
		return (dst + i + 1);
	}
	else
		return (NULL);
}
