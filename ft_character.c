/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:13:55 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/01 00:13:18 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ch_there_is_not(int *i, t_variables *variables, int *ret, intmax_t *tmp)
{
	while ((*i) < variables->gab)
	{
		if (variables->zer == 0)
			write(1, " ", 1);
		if (variables->zer == 1)
			write(1, "0", 1);
		(*ret)++;
		(*i)++;
	}
	ft_putchar((*tmp));
	(*ret)++;
}

int		ft_character(va_list args, t_variables *variables)
{
	intmax_t	tmp;
	int			i;
	int			ret;

	i = 1;
	ret = 0;
	if (variables->mod != 'a')
		ft_cast(args, variables, &tmp);
	else
		tmp = va_arg(args, int);
	if (variables->moi == 0)
		ch_there_is_not(&i, variables, &ret, &tmp);
	if (variables->moi == 1)
	{
		ft_putchar(tmp);
		ret++;
		while (i < variables->gab)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);
}
