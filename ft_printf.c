/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:03:47 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 17:13:14 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *blabla, ...)
{
	va_list			args;
	t_variables		*variables;
	int				i;
	int				modulo;
	char			*gabarit_str;
	char			*precision_str;
	int				j;
	int				point;
	int				ret;

	i = 0;
	j = 0;
	modulo = 0;
	point = 0;
	ret = 0;
	variables = (t_variables*)malloc(sizeof(t_variables));
	initialisation(variables);
	va_start (args, blabla);
	while (blabla[i])
	{
		while (blabla[i] != '%' && blabla[i])
		{
			ft_putchar(blabla[i]);
			ret++;
			i++;
		}
		if (blabla[i] == '%')
		{
			modulo = 1;
			if (blabla[i + 1] == '%')
			{
				//i++;
				//ret++;
				//write(1, "%", 1);
			//	modulo = 0;
			}
			if (modulo == 1)
			{
				i++;
				while (blabla[i] == '#' || blabla[i] == ' ' || blabla[i] == '0' || blabla[i] == '-' || blabla[i] == '+')
				{
					if (blabla[i] == '#')
						variables->diese = 1;
					if (blabla[i] == ' ')
						variables->espace = 1;
					if (blabla[i] == '0')
						variables->zero = 1;
					if (blabla[i] == '-')
						variables->moins = 1;
					if (blabla[i] == '+')
						variables->plus = 1;
					i++;
				}
				if (blabla[i] >= '0' && blabla[i] <= '9')
				{
					j = i;
					while (blabla[j] >= '0' && blabla[j] <= '9')
					{
						j++;
					}
					gabarit_str = (char*)malloc(sizeof(char) * (j + 1));
					j = 0;
					while (blabla[i] >= '0' && blabla[i] <= '9')
					{
						gabarit_str[j] = blabla[i];
						j++;
						i++;
					}
					gabarit_str[j] = '\0';
					variables->gabarit = ft_atoi(gabarit_str);
					free(gabarit_str);
				}
				if (blabla[i] == '.')
				{
					i++;
					j = i;
					while (blabla[j] >= '0' && blabla[j] <= '9')
						j++;
					precision_str = (char*)malloc(sizeof(char) * (j + 1));
					j = 0;
					while (blabla[i] >= '0' && blabla[i] <= '9')
					{
						precision_str[j] = blabla[i];
						j++;
						i++;
					}
					precision_str[j] = '\0';
					variables->precision = ft_atoi(precision_str);
					point = 1;
					free(precision_str);
				}
				if (blabla[i] == 'h' || blabla[i] == 'l' || blabla[i] == 'j' || blabla[i] == 'z')
				{
					variables->modificateur = blabla[i];
					i++;
					if (blabla[i] == 'h' || blabla[i] == 'l')
					{
						variables->modificateur -= 32;
						i++;
					}
				}
				variables->specificateur = blabla[i];
				if (point == 0 && variables->specificateur == 's')
				   variables->precision	= -1;
			/*	printf("variables->diese = %d\n", variables->diese);
				printf("variables->espace = %d\n", variables->espace);
				printf("variables->zero = %d\n", variables->zero);
				printf("variables->moins = %d\n", variables->moins);
				printf("variables->plus = %d\n", variables->plus);
				printf("variables->gabarit = %d\n", variables->gabarit);
				printf("variables->precision = %d\n", variables->precision);
				printf("variables->modificateur = %c\n", variables->modificateur);
				printf("variables->specificateur = %c\n", variables->specificateur);*/
				ret += ft_argument(args, variables);
				initialisation(variables);				
				modulo = 0;
				point = 0;
			}
			
		}
		if (blabla[i])
			i++;
	}
	va_end (args);
	free(variables);
//	printf("ret = %d\n", ret);
	return (ret);
}

