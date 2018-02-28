/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:03:47 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 16:33:07 by mpascaud         ###   ########.fr       */
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
