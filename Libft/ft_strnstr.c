/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:54:07 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/09 13:54:10 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (ptr);
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i + j] != '\0' && ptr[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (ptr + i);
			j++;
		}
		i++;
	}
	return (0);
}
