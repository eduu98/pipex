/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:45:49 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/07 13:45:51 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ret;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	else
	{
		ret = (unsigned char *)dst;
		if (src < dst)
		{
			while (len--)
			{
				*((unsigned char *)dst + len) = *((unsigned char *)src + len);
			}
		}
		else
			ft_memcpy(dst, src, len);
		return (ret);
	}
}
