/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:31:01 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/14 10:31:03 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_allocmem(char const *s, char c)
{
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (malloc((count + 1) * sizeof(char *)));
}

/**
 * Reserva memoria y devuelve una tabla de cadenas
 * de caracteres obtenida separando
 * ’s’ con el carácter ’c’, que se utiliza como
 * delimitador. La tabla debe terminar con NULL
*/
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**result;

	result = ft_allocmem(s, c);
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i])
				i++;
			result[k] = ft_substr(s, j, i - j);
			k++;
		}
		if (s[i] != '\0')
			i++;
	}
	result[k] = NULL;
	return (result);
}
