/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:18:39 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/16 13:18:41 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Suprime y libera la memoria del elemento pasado
 * como parámetro y de todos los elementos siguientes,
 * con ’del’ y free (3)
 * Por último, el puntero inicial debe pasar a NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
	{
		aux = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = aux;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}
