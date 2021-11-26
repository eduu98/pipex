/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:05:53 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/08 14:05:55 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/**
 * Busca cierta letra dentro de una cadena de texto
 */
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != (char)c && *ptr != '\0')
	{
		ptr++;
	}
	if (*ptr == '\0' && (char)c != '\0')
		return (NULL);
	return (ptr);
}
