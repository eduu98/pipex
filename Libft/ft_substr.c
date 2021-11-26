/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:48:41 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/12 13:48:43 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Reserva memoria y devuelve la cadena de caracteres que proviene de la cadena
 * pasada como argumento.
 * Esta nueva cadena comienza en el índice ’start’
 * y tiene como tamaño máximo ’len’
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	size;
	size_t			i;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		len = 0;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (*s && i < len)
	{
		*(ptr + i) = *(s + start + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
