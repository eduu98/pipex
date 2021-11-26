/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:10:31 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/13 10:10:33 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Reserva memoria y devuelve la cadena de caracteres que
 * que resulta de la concatenación de ’s1’ y ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*s;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < len1)
	{
		s[i] = s1[i];
	}
	j = -1;
	while (++j < len2 + 1)
	{
		s[i] = s2[j];
		i++;
	}
	return (s);
}
