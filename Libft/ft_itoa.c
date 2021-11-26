/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:04:01 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/15 10:04:03 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_countchars(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		size = 11;
	else if (n <= 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}	
	return (size);
}

/*
 * Reserva memoria y devuelve la cadena de
 * caracteres que representa el integer
 * pasado como argumento.
 * Se deben gestionar los números negativos.
*/
char	*ft_itoa(int n)
{
	char	*resultado;
	int		size;
	long	nlong;

	size = ft_countchars(n);
	resultado = malloc(size + 1);
	if (!resultado)
		return (NULL);
	resultado[size] = '\0';
	nlong = (long) n;
	if (nlong < 0)
	{
		resultado[0] = '-';
		nlong *= -1;
	}
	else if (nlong == 0)
		resultado[0] = '0';
	while (nlong > 0)
	{
		size--;
		resultado[size] = nlong % 10 + '0';
		nlong /= 10;
	}
	return (resultado);
}
