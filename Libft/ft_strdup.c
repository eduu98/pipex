/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:38:42 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/12 13:38:44 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*new;

	len = ft_strlen (s1) + 1;
	new = malloc (len);
	if (new == NULL)
		return (NULL);
	return ((char *) ft_memcpy (new, s1, len));
}
