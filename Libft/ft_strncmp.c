/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:57:26 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/10 11:57:31 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
