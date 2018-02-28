/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 17:02:21 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"


int		signed_nombrechiffres(intmax_t nb, t_variables *variables)
{
	int		result;
//	int		tmp;
	int		base;

	if (variables->specificateur == 'd' || variables->specificateur == 'i' || variables->specificateur == 'D' || variables->specificateur == 'u')
		base = 10;
	if (variables->specificateur == 'o' || variables->specificateur == 'O')
		base = 8;
	if (variables->specificateur == 'x' || variables->specificateur == 'X')
		base = 16;
	result = 1;
	if (nb == 0)
	{
		if (variables->precision == 0)
			return (0);
		return (1);
	}
	if (nb < -9223372036854775807)
		return (19);
	if (nb < 0)
		nb = -nb;
	while (nb >= base)
	{
		nb /= base;
		result++;
	}
	return (result);
}




int		nombrechiffres(unsigned long long nb, t_variables *variables)
{
	int		result;
//	int		tmp;???????????????????????
//	unsigned long long tmp;	
	unsigned long long		base;

	if (variables->specificateur == 'd' || variables->specificateur == 'i' || variables->specificateur == 'D' || variables->specificateur == 'u')
		base = 10;
	if (variables->specificateur == 'o' || variables->specificateur == 'O')
		base = 8;
	if (variables->specificateur == 'x' || variables->specificateur == 'X' || variables->specificateur == 'p')
		base = 16;
	result = 1;
//	tmp = (int)nb;////??????????????????????????
//	printf("tmp = %d, nb = %d\n", tmp, nb);
//	tmp = nb;	
	if (nb == 0)
	{
		if (variables->precision == 0 || (variables->precision == -1 && variables->diese == 1 && variables->specificateur != 'x' && variables->specificateur != 'X'))//!!!!!attention la
			return (0);
		return (1);
	}
/*	while (tmp != 0)
	{
		tmp /= base;
		result++;
	}*/
	while (nb >= base)
	{
	//	printf("nb = %d, base = %d, nbchiffres = %d\n", nb, base, result);
		nb /= base;
		result++;
	}
	/*while (tmp >= base)
	{
		tmp /= base;
		result++;
	}*/
	if ((variables->specificateur == 'o' || variables->specificateur == 'O') && variables->diese == 1)
		result++;
//	if ((variables->specificateur == 'x' || variables->specificateur == 'X') && variables->diese == 1)
//		result += 2;
	return (result);
}


