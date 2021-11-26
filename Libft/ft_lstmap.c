/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:19:12 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/16 14:19:13 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Realiza una iteración sobre la lista ’lst’ y aplica
 * la función ’f’ al contenido de cada elemento. Crea
 * una nueva lista que resulta de las aplicaciones
 * sucesivas de ’f’. Disponemos de la función ’del’ si
 * hay que elminar el contenido de algún elemento.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstresult;
	t_list	*elem;
	t_list	*aux;

	lstresult = NULL;
	if (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
			return (NULL);
		lstresult = elem;
		aux = lst->next;
		while (aux)
		{
			elem = ft_lstnew(f(aux->content));
			if (!elem)
			{
				ft_lstclear(&lst, del);
				return (NULL);
			}
			aux = aux->next;
			ft_lstadd_back(&lstresult, elem);
		}
	}
	return (lstresult);
}
