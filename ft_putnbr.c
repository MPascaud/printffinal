/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 17:24:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 21:36:39 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_extremum(intmax_t *nb)
{
	ft_putchar('9');
	(*nb) = -223372036854775808;
}

void	ft_putnbr(intmax_t nb, t_variables *variables, int nbchiffres, int tmp)
{
	char	*table;
	int		base;

	table = "0123456789abcdef";
	base = 10;
	if (variables->pre == 0 && nb == 0)
		return ;
	if (variables->spe == 'o')
		base = 8;
	if ((variables->spe == 'o') && tmp == 0 && variables->die == 1)
	{
		write(1, "0", 1);
		tmp = 1;
	}
	if (nb < 0)
	{
		if (nb < -9223372036854775807)
			ft_put_extremum(&nb);
		else
			ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
		ft_putnbr(nb / base, variables, nbchiffres, tmp);
	ft_putchar(table[nb % base]);
}

void	ft_unsigned_putnbr(uintmax_t nb, t_variables *v, int ch, int tmp)
{
	char		*table;
	uintmax_t	base;

	if (v->spe != 'X')
		table = "0123456789abcdef";
	if (v->spe == 'X')
		table = "0123456789ABCDEF";
	base = 10;
	if (v->spe == 'o' || v->spe == 'O')
		base = 8;
	if (v->spe == 'x' || v->spe == 'X' || v->spe == 'p')
		base = 16;
	if ((v->spe == 'o' || v->spe == 'O') && tmp == 0 && v->die == 1)
	{
		write(1, "0", 1);
		if (v->pre == -1 && nb == 0)
			return ;
		tmp = 1;
	}
	if ((v->pre == 0) && nb == 0)
		return ;
	if (nb >= base)
		ft_unsigned_putnbr(nb / base, v, ch, tmp);
	ft_putchar(table[nb % base]);
}
