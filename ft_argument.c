/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 23:21:18 by mpascaud         ###   ########.fr       */
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

	if (variables->moi == 0)
	{
	//	i = 2;
		while (((i < variables->gab - variables->pre) && (i < variables->gab - nbchiffres) && i < variables->pre + j) || ((i + nbchiffres) < variables->gab && variables->zer == 0 && (i + variables->pre) < variables->gab))
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
		write (1, "0x", 2);
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;

	}
	if (variables->moi == 1)
	{
		write(1, "0x", 2);
		ft_unsigned_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;
		i += nbchiffres;
		while (i < variables->gab)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);
}



int		ft_modulo(t_variables *variables)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	if (variables->moi == 0)
	{
		while ((i + 1) < variables->gab)
		{
			if (variables->zer == 0)
				write(1, " ", 1);
			if (variables->zer == 1)
				write(1, "0", 1);
			i++;
			ret++;
		}
		ft_putchar(variables->spe);
	}
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

int		ft_argument(va_list args, t_variables *variables)
{
	int		ret;

	ret = 0;
	if (variables->spe == 'd' || variables->spe == 'i' || variables->spe == 'D')
		ret = ft_decimal(args, variables);
	else if (variables->spe == 'c' && variables->mod != 'l')
		ret = ft_character(args, variables);
	else if (variables->spe == 's' && variables->mod != 'l')
		ret = ft_string(args, variables);
	else if (variables->spe == 'C' || (variables->spe == 'c' && variables->mod == 'l'))
		ret = ft_unicharacter(args);
	else if (variables->spe == 'S' || (variables->spe == 's' && variables->mod == 'l'))
		ret = ft_unistring(args, variables);
	else if (variables->spe == 'o' || variables->spe == 'O' || variables->spe == 'u' || variables->spe == 'U')
		ret = ft_unsigned(args, variables);
	else if (variables->spe == 'x' || variables->spe == 'X')
		ret = ft_unsigned_hexa(args, variables);
	else if (variables->spe == 'p')
		ret = ft_pointeur(args, variables);
	else if (variables->spe == '%')
		ret = ft_modulo(variables);
	else
	{
		if ((variables->spe >= 48 && variables->spe <= 64) || (variables->spe >= 65 && variables->spe <= 91) || (variables->spe >= 93 && variables->spe <= 126))
		{
			ret = ft_modulo(variables);
		}
	}
	return (ret);
}












