/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 19:11:08 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"



int		ft_pointeur(va_list args, t_variables *variables)
{
	uintmax_t	tmp;
	int         nbchiffres;
	int         i;
	int         j;
	int         ret;

	i = 2;
	j = 0;
	ret = 2;
	//	unsigned int	*tmp;
	tmp = (unsigned long long)va_arg(args, void*);
//	printf("coucou%p\n", tmp);
//	ft_printf("coucou%x\n", tmp);
	nbchiffres = nombrechiffres(tmp, variables);
//	printf("tmp = %llx, nbchiffres = %d\n", tmp, nbchiffres);

	if (variables->moins == 0)
	{
	//	i = 2;
		while (((i < variables->gabarit - variables->precision) && (i < variables->gabarit - nbchiffres) && i < variables->precision + j) || ((i + nbchiffres) < variables->gabarit && variables->zero == 0 && (i + variables->precision) < variables->gabarit))
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
		write (1, "0x", 2);
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;

	}
	if (variables->moins == 1)
	{
		write(1, "0x", 2);
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;
		i += nbchiffres;
		while (i < variables->gabarit)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);
}



int		ft_modulo(va_list args, t_variables *variables)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	if (variables->moins == 0)
	{
		while ((i + 1) < variables->gabarit)
		{
			if (variables->zero == 0)
				write(1, " ", 1);
			if (variables->zero == 1)
				write(1, "0", 1);
			i++;
			ret++;
		}
		ft_putchar(variables->specificateur);
	}
	if (variables->moins == 1)
	{
		ft_putchar(variables->specificateur);
		while ((i + 1) < variables->gabarit)
		{
			write(1, " ", 1);
			i++;
			ret++;
		}
	}
	return (ret);
}

int		ft_specificateur_invalide(va_list args, t_variables *variables)
{
	int		ret;

	ret = 0;

	if (variables->moins == 0)
	{

	}
	return (ret);
}

int		ft_argument(va_list args, t_variables *variables)
{
	int		tmp;
	int		ret;

	ret = 0;
	if (variables->specificateur == 'd' || variables->specificateur == 'i' || variables->specificateur == 'D')
		ret = ft_decimal(args, variables);
	else if (variables->specificateur == 'c' && variables->modificateur != 'l')
		ret = ft_character(args, variables);
	else if (variables->specificateur == 's' && variables->modificateur != 'l')
		ret = ft_string(args, variables);
	else if (variables->specificateur == 'C' || (variables->specificateur == 'c' && variables->modificateur == 'l'))
		ret = ft_unicharacter(args, variables);
	else if (variables->specificateur == 'S' || (variables->specificateur == 's' && variables->modificateur == 'l'))
		ret = ft_unistring(args, variables);
	else if (variables->specificateur == 'o' || variables->specificateur == 'O' || variables->specificateur == 'u' || variables->specificateur == 'U')
		ret = ft_unsigned(args, variables);
	else if (variables->specificateur == 'x' || variables->specificateur == 'X')
		ret = ft_unsigned_hexa(args, variables);
	else if (variables->specificateur == 'p')
		ret = ft_pointeur(args, variables);
	else if (variables->specificateur == '%')
		ret = ft_modulo(args, variables);
	else
	{
		if ((variables->specificateur >= 48 && variables->specificateur <= 64) || (variables->specificateur >= 65 && variables->specificateur <= 91) || (variables->specificateur>= 93 && variables->specificateur <= 126))
		{
			ret = ft_modulo(args, variables);

				//ft_putchar(variables->specificateur);
				//return (1);
		}
	}
	return (ret);
}












