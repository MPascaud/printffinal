/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 20:49:31 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"



void	ft_unsigned_putnbr(uintmax_t nb, t_variables *variables, int nbchiffres, int tmp)
{
	char	*table;
	int		base;
	
	if (variables->specificateur != 'X')
		table = "0123456789abcdef";
	if (variables->specificateur == 'X')
		table = "0123456789ABCDEF";
	base = 10;
//	printf("COUCOU ||| nb = %x\n", nb);
	if (variables->specificateur == 'o' || variables->specificateur == 'O')
		base = 8;
	if (variables->specificateur == 'x' || variables->specificateur == 'X' || variables->specificateur == 'p')
		base = 16;
	if ((variables->specificateur == 'o' || variables->specificateur == 'O') && tmp == 0 && variables->diese == 1)
	{
		//if (variables->gabarit != 0 || variables->precision != -1)
		//if (nb != 0)
		write(1, "0", 1);
		if (variables->precision == -1 && nb == 0)
			return ;
	/*	if (variables->specificateur == 'x')
			write(1, "x", 1);
		if (variables->specificateur == 'X')
			write(1, "X", 1);*/
		tmp = 1;
	}
	if ((variables->precision == 0) && nb == 0)
		return ;
//	printf("base = %d\n", base);
	if (nb >= base)
	{
		ft_unsigned_putnbr(nb / base, variables, nbchiffres, tmp);
	}
	ft_putchar (table[nb % base]);
}


int		ft_unsigned(va_list args, t_variables *variables)
{
	uintmax_t	tmp;
	int			nbchiffres;
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	if (variables->specificateur == 'O' || variables->specificateur == 'U')
		variables->modificateur = 'l';
	if (variables->specificateur == 'O')
		variables->specificateur = 'o';
	if (variables->specificateur == 'U')
		variables->specificateur = 'u';
	ft_unsigned_cast(args, variables, &tmp);
	nbchiffres = nombrechiffres(tmp, variables);
//	if (variables->specificateur == 'x' || variables->specificateur == 'X')
//		nbchiffres++;
//	if (variables->specificateur == 'x')
//		write(1, "0x", 2);
//	if (variables->specificateur == 'X')
//		write(1, "0X", 2);

//	printf("nbchiffres = %d\n", nbchiffres);
	if (variables->moins == 0)
	{
		if (variables->espace == 1 || variables->plus == 1)
			i++;
		j = i;
		while (((i < variables->gabarit - variables->precision) && (i < variables->gabarit - nbchiffres) && i < variables->precision + j) || ((i + nbchiffres) < variables->gabarit && variables->zero == 0 && (i + variables->precision) < variables->gabarit))
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
		/*if (variables->diese == 1 && (variables->specificateur == 'x' || variables->specificateur == 'X'))
		{
			if (variables->specificateur == 'x')
				write(1, "0x", 2);
			if (variables->specificateur == 'X')
				write(1, "0X", 2);
			i += 2;
		}*/
		if (variables->plus == 1 && variables->specificateur != 'u' && variables->specificateur != 'U')
		{
			write(1, "+", 1);
			ret++;
		}
		j = i;
		i = 0;
		while (((i < variables->precision - nbchiffres) || (j + i + nbchiffres) < variables->gabarit))
		{
			write(1, "0", 1);
			ret++;
			i++;
		}
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
	//	printf("diese = %d", variables->diese);
	//	if (variables->diese == -1)
	//		variables->diese = 0;
		ret += (nbchiffres /*+ variables->diese*/);
	}
	if (variables->moins == 1)
	{
		if (variables->plus == 1)
		{
			write(1, "+", 1);
			ret++;
		}
		if (variables->espace == 1 && variables->plus == 0)
		{
			write(1, " ", 1);
			ret++;
		}
		if (variables->espace == 1 || variables->plus == 1)
			i++;
		if (variables->plus == 0)
			i++;
		/*if (variables->diese == 1 && (variables->specificateur == 'x' || variables->specificateur == 'X'))
		{
			if (variables->specificateur == 'x')
				write(1, "0x", 2);
			if (variables->specificateur == 'X')
				write(1, "0X", 2);
			i += 2;
		}*/
		while (i <= (variables->precision - nbchiffres))
		{
			write(1, "0", 1);
			//if (variables->specificateur != 'x' && variables->specificateur != 'X')
			//	write(1, " ", 1);
			//if (variables->specificateur == 'x' || variables->specificateur == 'X')
			//	write(1, "0", 1);
			ret++;
			i++;
		}
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;
		i += nbchiffres;
		if (variables->plus == 0 && j == 0)
			i--;
		while (i < variables->gabarit)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	if ((variables->specificateur == 'o' || variables->specificateur == 'O') && tmp == 0 && variables->diese == 1)
		ret++;
	return (ret);
}








