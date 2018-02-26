/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:13:55 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 18:07:35 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libftprintf.h"



int    ft_character(va_list args, t_variables *variables)
{
	intmax_t    tmp;
	int         i;
	int			ret;

	i = 1;
	ret = 0;
	if (variables->modificateur != 'a')
		ft_cast(args, variables, &tmp);
	else
		tmp = va_arg(args, int);
	if (variables->moins == 0)
	{
		while (i < variables->gabarit)
		{
			if (variables->zero == 0)
				write(1, " ", 1);
			if (variables->zero == 1)
				write(1, "0", 1);
			ret++;
			i++;
		}
		ft_putchar(tmp);
		ret++;
	}
	if (variables->moins == 1)
	{
		ft_putchar(tmp);
		ret++;
		while (i < variables->gabarit)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);
}


