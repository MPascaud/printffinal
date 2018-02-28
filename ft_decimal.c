/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 22:33:41 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	d_there_is_not(t_variables *v, t_signed_vari *d)
{
	if ((v->esp == 1 || v->plu == 1) && d->tmp >= 0)
		d->i++;
	if (d->tmp < 0)
		d->i++;
	d->j = d->i;
	while (((d->i < v->gab - v->pre) && (d->i < v->gab - d->chi)
				&& d->i < v->pre + d->j) || ((d->i + d->chi) < v->gab
					&& v->zer == 0 && (d->i + v->pre) < v->gab))
		d_space1(d);
	if (v->plu == 1 && d->tmp >= 0)
	{
		write(1, "+", 1);
		d->ret++;
	}
	if (v->esp == 1 && v->plu == 0 && d->tmp >= 0)
		d_space2(d);
	d_neg(d);
	d->j = d->i;
	d->i = 0;
	while (((d->i < v->pre - d->chi) || (d->j + d->i + d->chi) < v->gab))
		d_zero(d);
	ft_putnbr(d->tmp, v, d->chi, 0);
	d->ret += d->chi;
}

void	d_there_is_min(t_variables *v, t_signed_vari *d)
{
	if (v->plu == 1 && d->tmp >= 0)
	{
		write(1, "+", 1);
		d->ret++;
	}
	if (v->esp == 1 && v->plu == 0 && d->tmp >= 0)
		d_space2(d);
	if ((v->esp == 1 || v->plu == 1) && d->tmp >= 0)
		d->i++;
	if (v->plu == 0 && d->tmp >= 0)
		d->i++;
	if (d->tmp < 0)
		d_neg2(d);
	while (d->i <= (v->pre - d->chi))
		d_zero(d);
	ft_putnbr(d->tmp, v, d->chi, 0);
	d->ret += d->chi;
	d->i += d->chi;
	if (v->plu == 0 && d->j == 0)
		d->i--;
	while (d->i < v->gab)
		d_space1(d);
}

int		ft_decimal(va_list args, t_variables *v)
{
	t_signed_vari		*d;

	d = (t_signed_vari*)malloc(sizeof(t_signed_vari));
	d->i = 0;
	d->j = 0;
	d->ret = 0;
	if (v->mod != 'a' && v->spe != 'D')
		ft_cast(args, v, &d->tmp);
	if (v->mod == 'a' && (v->spe == 'd' || v->spe == 'i'))
		d->tmp = va_arg(args, int);
	if (v->spe == 'D')
		d->tmp = va_arg(args, long int);
	d->chi = signed_nombrechiffres(d->tmp, v);
	if (v->moi == 0)
		d_there_is_not(v, d);
	if (v->moi == 1)
		d_there_is_min(v, d);
	free(d);
	return (d->ret);
}
