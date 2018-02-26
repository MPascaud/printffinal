/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:58:18 by mpascaud          #+#    #+#             */
/*   Updated: 2018/01/27 21:00:17 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"
#include <stdint.h>
/*int		ft_printf(char *blabla, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start (args, blabla);
	while (blabla[i])
	{
		if (blabla[i] == '%')
		{
			if (blabla[i + 1] == '%')
			{
				ft_putchar('%');
			}
			if (blabla[i + 1] == 'd' || blabla[i + 1] == 'i')
			{
				ft_putnbr(va_arg(args, int));
				i++;
			}

		}
		else
			ft_putchar(blabla[i]);
		i++;
	}
	va_end (args);
	return (0);
}
*/
/*
int		ft_printf(char *blabla, ...)
{
	va_list		args;
	

	int			i;

	i = 0;
	va_start(args, blabla);
}
*/

int		main(void)
{
//	float	nb;

//	nb = 2.36;
	uintmax_t	a;

	a = 'a';
	printf("%jd\n", a);
	printf("%j\n", int_max);
	return (0);
}

