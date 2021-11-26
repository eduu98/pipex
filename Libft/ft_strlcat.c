/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:40:30 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/08 12:40:32 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Concatena dos cadenas de forma segura.
 * Devuelve la longitud total de la cadena que se intenta crear.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	destlen;

	destlen = ft_strlen(dst);
	i = destlen;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize && dstsize >= 2)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (dstsize < destlen)
		destlen = dstsize;
	else
		dst[i] = '\0';
	return (destlen + ft_strlen(src));
}
