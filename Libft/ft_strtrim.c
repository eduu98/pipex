/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:51:12 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/13 10:51:14 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkstart(char const *set, char const *s1)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	return (i);
}

int	ft_checkend(char const *set, char const *s1, int size)
{
	while (ft_strchr(set, s1[size]) && size > 0)
		size--;
	size++;
	return (size);
}

/**
 * Reserva memoria y devuelve la cadena de caracteres que
 * es una copia de ’s1’, sin los caracteres indicados en el ’set’
 * al principio y al final de la cadena de caracteres.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		sizes1;
	int		start;
	int		end;
	char	*result;

	if (!s1)
		return (NULL);
	sizes1 = ft_strlen(s1);
	start = ft_checkstart(set, s1);
	if (start != sizes1)
		end = ft_checkend(set, s1, sizes1);
	else
		end = start;
	result = malloc(end - start + 1);
	if (!result)
		return (NULL);
	if (end == start)
		result[0] = '\0';
	else
		ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
