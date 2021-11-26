/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:50:15 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/16 10:50:17 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Reserva memoria (con malloc(3)) y devuelve un nuevo
 * elemento. La variable ’content’ se inicializa
 * mediante el valor del parámetro ’content’. La
 * variable ’next’ se inicializa con NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (nodo == NULL)
		return (NULL);
	if (!content)
	{
		nodo->content = NULL;
		nodo->next = NULL;
	}
	else
	{
		nodo->content = content;
		nodo->next = NULL;
	}
	return (nodo);
}
