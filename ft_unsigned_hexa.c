/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 20:10:26 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	uh_there_is_not(t_variables *v, t_unsigned_vari *uv)
{
	if (v->die == 1)
		uv->i = 2;
	uv->j = uv->i;
	while (((uv->i < v->gab - v->pre) && (uv->i < v->gab - uv->chi)
				&& uv->i < v->pre + uv->j) || ((uv->i + uv->chi) < v->gab
					&& v->zer == 0 && (uv->i + v->pre) < v->gab))
		ft_space(uv);
	uv->j = uv->i;
	uv->i = 0;
	if (v->die == 1 && uv->tmp != 0)
	{
		if (v->spe == 'x')
			write(1, "0x", 2);
		if (v->spe == 'X')
			write(1, "0X", 2);
		uv->ret += 2;
	}
	while (((uv->i < v->pre - uv->chi)
				|| (uv->j + uv->i + uv->chi) < v->gab))
		ft_write_zero(uv);
	ft_unsigned_putnbr(uv->tmp, v, uv->chi, 0);
	uv->ret += uv->chi;
}

void	uh_there_is_min(t_variables *v, t_unsigned_vari *uv)
{
	if (v->die == 1 && v->spe == 'x' && uv->tmp != 0)
	{
		write(1, "0x", 2);
		uv->ret += 2;
	}
	if (v->die == 1 && v->spe == 'X' && uv->tmp != 0)
	{
		write(1, "0X", 2);
		uv->ret += 2;
	}
	uv->j = uv->i;
	while (uv->i < (v->pre - uv->chi))
		ft_write_zero(uv);
	ft_unsigned_putnbr(uv->tmp, v, uv->chi, 0);
	uv->ret += uv->chi;
	uv->i += uv->chi;
	if (v->die == 1)
		uv->i += 2;
	while (uv->i < v->gab)
		ft_space(uv);
}

int		ft_unsigned_hexa(va_list args, t_variables *v)
{
	t_unsigned_vari		*uv;

	uv = (t_unsigned_vari*)malloc(sizeof(t_unsigned_vari));
	uv->i = 0;
	uv->j = 0;
	uv->ret = 0;
	ft_unsigned_cast(args, v, &uv->tmp);
	uv->chi = nombrechiffres(uv->tmp, v);
	if (v->moi == 0)
		uh_there_is_not(v, uv);
	if (v->moi == 1)
		uh_there_is_min(v, uv);
	free(uv);
	return (uv->ret);
}
