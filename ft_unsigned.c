/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 17:05:02 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unsigned_putnbr(uintmax_t nb, t_variables *v, int ch, int tmp)
{
	char	*table;
	uintmax_t		base;

	if (v->specificateur != 'X')
		table = "0123456789abcdef";
	if (v->specificateur == 'X')
		table = "0123456789ABCDEF";
	base = 10;
	if (v->specificateur == 'o' || v->specificateur == 'O')
		base = 8;
	if (v->specificateur == 'x' || v->specificateur == 'X' || v->specificateur == 'p')
		base = 16;
	if ((v->specificateur == 'o' || v->specificateur == 'O') && tmp == 0 && v->diese == 1)
	{
		write(1, "0", 1);
		if (v->precision == -1 && nb == 0)
			return ;
		tmp = 1;
	}
	if ((v->precision == 0) && nb == 0)
		return ;
	if (nb >= base)
		ft_unsigned_putnbr(nb / base, v, ch, tmp);
	ft_putchar(table[nb % base]);
}

int		ft_unsigned(va_list args, t_variables *v)
{
	uintmax_t	tmp;
	int			nbchiffres;
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	if (v->specificateur == 'O' || v->specificateur == 'U')
		v->modificateur = 'l';
	if (v->specificateur == 'O')
		v->specificateur = 'o';
	if (v->specificateur == 'U')
		v->specificateur = 'u';
	ft_unsigned_cast(args, v, &tmp);
	nbchiffres = nombrechiffres(tmp, v);
	if (v->moins == 0)
	{
		if (v->espace == 1 || v->plus == 1)
			i++;
		j = i;
		while (((i < v->gabarit - v->precision) && (i < v->gabarit - nbchiffres) && i < v->precision + j) || ((i + nbchiffres) < v->gabarit && v->zero == 0 && (i + v->precision) < v->gabarit))
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
		if (v->plus == 1 && v->specificateur != 'u' && v->specificateur != 'U')
		{
			write(1, "+", 1);
			ret++;
		}
		j = i;
		i = 0;
		while (((i < v->precision - nbchiffres) || (j + i + nbchiffres) < v->gabarit))
		{
			write(1, "0", 1);
			ret++;
			i++;
		}
		ft_unsigned_putnbr(tmp, v, nbchiffres, 0);
		ret += nbchiffres;
	}
	if (v->moins == 1)
	{
		if (v->plus == 1)
		{
			write(1, "+", 1);
			ret++;
		}
		if (v->espace == 1 && v->plus == 0)
		{
			write(1, " ", 1);
			ret++;
		}
		if (v->espace == 1 || v->plus == 1)
			i++;
		if (v->plus == 0)
			i++;
		while (i <= (v->precision - nbchiffres))
		{
			write(1, "0", 1);
			ret++;
			i++;
		}
		ft_unsigned_putnbr(tmp, v, nbchiffres, 0);
		ret += nbchiffres;
		i += nbchiffres;
		if (v->plus == 0 && j == 0)
			i--;
		while (i < v->gabarit)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	if ((v->specificateur == 'o' || v->specificateur == 'O') && tmp == 0 && v->diese == 1)
		ret++;
	return (ret);
}
