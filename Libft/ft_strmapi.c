/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:46:38 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/15 13:46:40 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*resultado;
	int				len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	resultado = malloc(len + 1);
	if (!resultado)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		resultado[i] = f(i, s[i]);
		i++;
	}
	resultado[i] = '\0';
	return (resultado);
}
