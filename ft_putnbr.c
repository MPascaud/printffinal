/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:24:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 20:03:45 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void	ft_putnbr(intmax_t nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}*/


void	ft_putnbr(intmax_t nb, t_variables *variables, int nbchiffres, int tmp)
{
	char	*table;
	int		base;
//	unsigned long long nb2;
//	if (variables->specificateur == 'o' && variables->modificateur == 'l')
//		nb2 = nb;

	table = "0123456789abcdef";
	base = 10;
	if (variables->precision == 0 && nb == 0)
	{
	//	write(1, " ", 1);
		return ;
	}
//	printf("modificateur = %c, specificateur = %c, nbchiffres = %d, nb en o : %o\n", variables->modificateur, variables->specificateur, nbchiffres, nb);
	if (variables->specificateur == 'o')
		base = 8;
	if ((variables->specificateur == 'o') &&/* variables->gabarit >= nbchiffres &&*/ tmp == 0 && variables->diese == 1)
	{
		write(1, "0", 1);
		tmp = 1;
	}
	if (nb < 0 /*&& variables->specificateur != 'o'*/)
	{
	//	printf("coucou");
		//ft_putchar('-');
		if (nb < -9223372036854775807)
		{
			ft_putchar('9');
			nb = -223372036854775808;
		}
		else
			ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
	{
		ft_putnbr(nb / base, variables, nbchiffres, tmp);
	}
//	printf("avant %jo\n", nb);
	ft_putchar(table[nb % base]);
//	printf("apres %jo\n", nb);
}

/*
void	ft_putnbr(intmax_t *tmp, t_variables *variables)
{
	ft_putnbrint((intmax_t)*tmp);
}*/

