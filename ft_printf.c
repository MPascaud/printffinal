/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:03:47 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 16:30:02 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_v2(t_vari2 *v2)
{
	v2->i = 0;
	v2->j = 0;
	v2->modulo = 0;
	v2->point = 0;
	v2->ret = 0;
}

void	ft_flags(t_variables *variables, t_vari2 *v2, char *b)
{
	if (b[v2->i] == '#')
		variables->diese = 1;
	if (b[v2->i] == ' ')
		variables->espace = 1;
	if (b[v2->i] == '0')
		variables->zero = 1;
	if (b[v2->i] == '-')
		variables->moins = 1;
	if (b[v2->i] == '+')
		variables->plus = 1;
	v2->i++;
}

void	ft_gabarit(t_variables *variables, t_vari2 *v2, char *b)
{
	v2->j = v2->i;
	while (b[v2->j] >= '0' && b[v2->j] <= '9')
		v2->j++;
	v2->gabarit_str = (char*)malloc(sizeof(char) * (v2->j + 1));
	v2->j = 0;
	while (b[v2->i] >= '0' && b[v2->i] <= '9')
	{
		v2->gabarit_str[v2->j] = b[v2->i];
		v2->j++;
		v2->i++;
	}
	v2->gabarit_str[v2->j] = '\0';
	variables->gabarit = ft_atoi(v2->gabarit_str);
	free(v2->gabarit_str);
}

void	ft_precision(t_variables *variables, t_vari2 *v2, char *b)
{
	v2->i++;
	v2->j = v2->i;
	while (b[v2->j] >= '0' && b[v2->j] <= '9')
		v2->j++;
	v2->precision_str = (char*)malloc(sizeof(char) * (v2->j + 1));
	v2->j = 0;
	while (b[v2->i] >= '0' && b[v2->i] <= '9')
	{
		v2->precision_str[v2->j] = b[v2->i];
		v2->j++;
		v2->i++;
	}
	v2->precision_str[v2->j] = '\0';
	variables->precision = ft_atoi(v2->precision_str);
	v2->point = 1;
	free(v2->precision_str);
}

void	ft_modificateur(t_variables *variables, t_vari2 *v2, char *b)
{
	variables->modificateur = b[v2->i];
	v2->i++;
	if (b[v2->i] == 'h' || b[v2->i] == 'l')
	{
		variables->modificateur -= 32;
		v2->i++;
	}
}

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
