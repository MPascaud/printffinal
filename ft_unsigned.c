/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 19:40:13 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_space(t_unsigned_vari *uv)
{
	write(1, " ", 1);
	uv->ret++;
	uv->i++;
}

void	uns_there_is_moi(t_variables *v, t_unsigned_vari *uv)
{
	if (v->esp == 1 || v->plu == 1)
		uv->i++;
	uv->j = uv->i;
	while (((uv->i < v->gab - v->pre) && (uv->i < v->gab - uv->chi)
				&& uv->i < v->pre + uv->j) || ((uv->i + uv->chi) < v->gab
					&& v->zer == 0 && (uv->i + v->pre) < v->gab))
		ft_space(uv);
	if (v->plu == 1 && v->spe != 'u' && v->spe != 'U')
	{
		write(1, "+", 1);
		uv->ret++;
	}
	uv->j = uv->i;
	uv->i = 0;
	while (((uv->i < v->pre - uv->chi) || (uv->j + uv->i + uv->chi) < v->gab))
	{
		write(1, "0", 1);
		uv->ret++;
		uv->i++;
	}
	ft_unsigned_putnbr(uv->tmp, v, uv->chi, 0);
	uv->ret += uv->chi;
}

void	ft_write_zero(t_unsigned_vari *uv)
{
	write(1, "0", 1);
	uv->ret++;
	uv->i++;
}

void	uns_there_is_not(t_variables *v, t_unsigned_vari *uv)
{
	if (v->plu == 1)
	{
		write(1, "+", 1);
		uv->ret++;
	}
	if (v->esp == 1 && v->plu == 0)
	{
		write(1, " ", 1);
		uv->ret++;
	}
	if (v->esp == 1)
		uv->i++;
	uv->i++;
	while (uv->i <= (v->pre - uv->chi))
		ft_write_zero(uv);
	ft_unsigned_putnbr(uv->tmp, v, uv->chi, 0);
	uv->ret += uv->chi;
	uv->i += uv->chi;
	if (v->plu == 0 && uv->j == 0)
		uv->i--;
	while (uv->i < v->gab)
		ft_space(uv);
}

int		ft_unsigned(va_list args, t_variables *v)
{
	t_unsigned_vari		*uv;

	uv = (t_unsigned_vari*)malloc(sizeof(t_unsigned_vari));
	uv->i = 0;
	uv->j = 0;
	uv->ret = 0;
	if (v->spe == 'O' || v->spe == 'U')
		v->mod = 'l';
	if (v->spe == 'O')
		v->spe = 'o';
	if (v->spe == 'U')
		v->spe = 'u';
	ft_unsigned_cast(args, v, &uv->tmp);
	uv->chi = nombrechiffres(uv->tmp, v);
	if (v->moi == 0)
		uns_there_is_moi(v, uv);
	if (v->moi == 1)
		uns_there_is_not(v, uv);
	if ((v->spe == 'o' || v->spe == 'O') && uv->tmp == 0 && v->die == 1)
		uv->ret++;
	free(uv);
	return (uv->ret);
}
