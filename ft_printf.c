/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:03:47 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/27 17:39:20 by mpascaud         ###   ########.fr       */
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



int		ft_printf(char *blabla, ...)
{
	va_list			args;
	t_variables		*variables;
	t_vari2			*v2;
//	int				i;
//	int				modulo;
//	char			*gabarit_str;
//	char			*precision_str;
//	int				j;
//	int				point;
//	int				ret;

	//i = 0;
	//j = 0;
	//modulo = 0;
	//point = 0;
	//ret = 0;
	variables = (t_variables*)malloc(sizeof(t_variables));
	v2 = (t_vari2*)malloc(sizeof(t_vari2));
	initialisation(variables);
	ft_init_v2(v2);
	va_start (args, blabla);
	while (blabla[v2->i])
	{
		while (blabla[v2->i] != '%' && blabla[v2->i])
		{
			ft_putchar(blabla[v2->i]);
			v2->ret++;
			v2->i++;
		}
		if (blabla[v2->i] == '%')
		{
			v2->modulo = 1;
			if (v2->modulo == 1)
			{
				v2->i++;
				while (blabla[v2->i] == '#' || blabla[v2->i] == ' ' || blabla[v2->i] == '0' || blabla[v2->i] == '-' || blabla[v2->i] == '+')
				{
					if (blabla[v2->i] == '#')
						variables->diese = 1;
					if (blabla[v2->i] == ' ')
						variables->espace = 1;
					if (blabla[v2->i] == '0')
						variables->zero = 1;
					if (blabla[v2->i] == '-')
						variables->moins = 1;
					if (blabla[v2->i] == '+')
						variables->plus = 1;
					v2->i++;
				}
				if (blabla[v2->i] >= '0' && blabla[v2->i] <= '9')
				{
					v2->j = v2->i;
					while (blabla[v2->j] >= '0' && blabla[v2->j] <= '9')
					{
						v2->j++;
					}
					v2->gabarit_str = (char*)malloc(sizeof(char) * (v2->j + 1));
					v2->j = 0;
					while (blabla[v2->i] >= '0' && blabla[v2->i] <= '9')
					{
						v2->gabarit_str[v2->j] = blabla[v2->i];
						v2->j++;
						v2->i++;
					}
					v2->gabarit_str[v2->j] = '\0';
					variables->gabarit = ft_atoi(v2->gabarit_str);
					free(v2->gabarit_str);
				}
				if (blabla[v2->i] == '.')
				{
					v2->i++;
					v2->j = v2->i;
					while (blabla[v2->j] >= '0' && blabla[v2->j] <= '9')
						v2->j++;
					v2->precision_str = (char*)malloc(sizeof(char) * (v2->j + 1));
					v2->j = 0;
					while (blabla[v2->i] >= '0' && blabla[v2->i] <= '9')
					{
						v2->precision_str[v2->j] = blabla[v2->i];
						v2->j++;
						v2->i++;
					}
					v2->precision_str[v2->j] = '\0';
					variables->precision = ft_atoi(v2->precision_str);
					v2->point = 1;
					free(v2->precision_str);
				}
				if (blabla[v2->i] == 'h' || blabla[v2->i] == 'l' || blabla[v2->i] == 'j' || blabla[v2->i] == 'z')
				{
					variables->modificateur = blabla[v2->i];
					v2->i++;
					if (blabla[v2->i] == 'h' || blabla[v2->i] == 'l')
					{
						variables->modificateur -= 32;
						v2->i++;
					}
				}
				variables->specificateur = blabla[v2->i];
				if (v2->point == 0 && variables->specificateur == 's')
				   variables->precision	= -1;
				v2->ret += ft_argument(args, variables);
				initialisation(variables);				
				v2->modulo = 0;
				v2->point = 0;
			}
			
		}
		if (blabla[v2->i])
			v2->i++;
	}
	va_end (args);
	free(variables);
	free(v2);
	return (v2->ret);
}

