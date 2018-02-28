/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/01 00:06:50 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	mod_there_is_not(int *i, t_variables *variables, int *ret)
{
	while (((*i) + 1) < variables->gab)
	{
		if (variables->zer == 0)
			write(1, " ", 1);
		if (variables->zer == 1)
			write(1, "0", 1);
		(*i)++;
		(*ret)++;
	}
	ft_putchar(variables->spe);
}

int		ft_modulo(t_variables *variables)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	if (variables->moi == 0)
		mod_there_is_not(&i, variables, &ret);
	if (variables->moi == 1)
	{
		ft_putchar(variables->spe);
		while ((i + 1) < variables->gab)
		{
			write(1, " ", 1);
			i++;
			ret++;
		}
	}
	return (ret);
}

int		ft_argument2(t_variables *v)
{
	if ((v->spe >= 48 && v->spe <= 64) || (v->spe >= 65 && v->spe <= 91)
			|| (v->spe >= 93 && v->spe <= 126))
		return (ft_modulo(v));
	return (0);
}

int		ft_argument(va_list args, t_variables *v)
{
	int		ret;

	ret = 0;
	if (v->spe == 'd' || v->spe == 'i' || v->spe == 'D')
		ret = ft_decimal(args, v);
	else if (v->spe == 'c' && v->mod != 'l')
		ret = ft_character(args, v);
	else if (v->spe == 's' && v->mod != 'l')
		ret = ft_string(args, v);
	else if (v->spe == 'C' || (v->spe == 'c' && v->mod == 'l'))
		ret = ft_unicharacter(args);
	else if (v->spe == 'S' || (v->spe == 's' && v->mod == 'l'))
		ret = ft_unistring(args, v);
	else if (v->spe == 'o' || v->spe == 'O' || v->spe == 'u' || v->spe == 'U')
		ret = ft_unsigned(args, v);
	else if (v->spe == 'x' || v->spe == 'X')
		ret = ft_unsigned_hexa(args, v);
	else if (v->spe == 'p')
		ret = ft_pointer(args, v);
	else if (v->spe == '%')
		ret = ft_modulo(v);
	else
		ret = ft_argument2(v);
	return (ret);
}
