/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:03:47 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 16:41:04 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_modulo2(t_variables *variables, t_vari2 *v2, char *b, va_list args)
{
	v2->modulo = 1;
	if (v2->modulo == 1)
	{
		v2->i++;
		while (b[v2->i] == '#' || b[v2->i] == ' ' || b[v2->i] == '0'
				|| b[v2->i] == '-' || b[v2->i] == '+')
			ft_flags(variables, v2, b);
		if (b[v2->i] >= '0' && b[v2->i] <= '9')
			ft_gabarit(variables, v2, b);
		if (b[v2->i] == '.')
			ft_precision(variables, v2, b);
		if (b[v2->i] == 'h' || b[v2->i] == 'l'
				|| b[v2->i] == 'j' || b[v2->i] == 'z')
			ft_modificateur(variables, v2, b);
		variables->specificateur = b[v2->i];
		if (v2->point == 0 && variables->specificateur == 's')
			variables->precision = -1;
		v2->ret += ft_argument(args, variables);
		initialisation(variables);
		v2->modulo = 0;
		v2->point = 0;
	}
}

void	ft_parsing(t_variables *variables, t_vari2 *v2, char *b, va_list args)
{
	while (b[v2->i] != '%' && b[v2->i])
	{
		ft_putchar(b[v2->i]);
		v2->ret++;
		v2->i++;
	}
	if (b[v2->i] == '%')
		ft_modulo2(variables, v2, b, args);
	if (b[v2->i])
		v2->i++;
}

int		ft_printf(char *b, ...)
{
	va_list			args;
	t_variables		*variables;
	t_vari2			*v2;

	variables = (t_variables*)malloc(sizeof(t_variables));
	v2 = (t_vari2*)malloc(sizeof(t_vari2));
	initialisation(variables);
	ft_init_v2(v2);
	va_start(args, b);
	while (b[v2->i])
		ft_parsing(variables, v2, b, args);
	va_end(args);
	free(variables);
	free(v2);
	return (v2->ret);
}
