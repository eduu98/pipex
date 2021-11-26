/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:10:47 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/16 14:10:48 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Realiza una iteración sobre la lista ’lst’ y aplica
 * la función ’f’ al contenido de cada elemento.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst->next)
		{
			f(lst->content);
			lst = lst->next;
		}
		f(lst->content);
	}
}
