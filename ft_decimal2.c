/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 22:33:14 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	d_space1(t_signed_vari *d)
{
	write(1, " ", 1);
	d->ret++;
	d->i++;
}

void	d_neg(t_signed_vari *d)
{
	if (d->tmp < 0)
	{
		write(1, "-", 1);
		d->tmp = -d->tmp;
		d->ret++;
	}
}

void	d_zero(t_signed_vari *d)
{
	write(1, "0", 1);
	d->ret++;
	d->i++;
}

void	d_space2(t_signed_vari *d)
{
	write(1, " ", 1);
	d->ret++;
}

void	d_neg2(t_signed_vari *d)
{
	write(1, "-", 1);
	d->tmp = -d->tmp;
	d->ret++;
	d->j++;
	d->i++;
}
