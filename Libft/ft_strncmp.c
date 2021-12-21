/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:57:26 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/12/21 12:59:06 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Compara las dos cadenas pasadas por parametro.
 * El numero n es el numero de caracteres que se compara.
 * Retorna 0 si las cadenas son iguales
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	r;
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*dtr;

	str = (unsigned char *)s1;
	dtr = (unsigned char *)s2;
	i = 0;
	r = 0;
	while (i < n)
	{
		if (str[i] != dtr[i] || str[i] == '\0' || dtr[i] == '\0')
		{
			r = str[i] - dtr[i];
			return (r);
		}
		i++;
	}
	return (r);
}
