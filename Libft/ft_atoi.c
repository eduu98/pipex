/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:19:35 by ecruz-go          #+#    #+#             */
/*   Updated: 2021/04/10 13:19:36 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	resultado;
	long	signo;

	i = 0;
	resultado = 0;
	signo = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		resultado = resultado * 10 + (*(str + i) - '0');
		if (resultado * signo > 2147483647)
			return (-1);
		if (resultado * signo < -2147483648)
			return (0);
		i++;
	}
	return (resultado * signo);
}
