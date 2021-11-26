/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:51:16 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/16 09:51:17 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/**
 * Escribe la cadena de caracteres ’s’ sobre el
 * descriptor de fichero proporcionado.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
