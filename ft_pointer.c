/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 23:47:22 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	p_there_is_not(t_variables *v, t_unsigned_vari *p)
{
	while (((p->i < v->gab - v->pre) && (p->i < v->gab - p->chi)
				&& p->i < v->pre + p->j) || ((p->i + p->chi) <
					v->gab && v->zer == 0 && (p->i + v->pre) < v->gab))
	{
		write(1, " ", 1);
		p->ret++;
		p->i++;
	}
	write(1, "0x", 2);
	ft_unsigned_putnbr(p->tmp, v, p->chi, 0);
	p->ret += p->chi;
}

int		ft_pointer(va_list args, t_variables *v)
{
	t_unsigned_vari		*p;

	p = (t_unsigned_vari*)malloc(sizeof(t_unsigned_vari));
	p->i = 2;
	p->j = 0;
	p->ret = 2;
	p->tmp = (unsigned long long)va_arg(args, void*);
	p->chi = nombrechiffres(p->tmp, v);
	if (v->moi == 0)
		p_there_is_not(v, p);
	if (v->moi == 1)
	{
		write(1, "0x", 2);
		ft_unsigned_putnbr(p->tmp, v, p->chi, 0);
		p->ret += p->chi;
		p->i += p->chi;
		while (p->i < v->gab)
		{
			write(1, " ", 1);
			p->ret++;
			p->i++;
		}
	}
	free(p);
	return (p->ret);
}
