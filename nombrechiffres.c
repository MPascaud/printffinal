/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 19:13:12 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	signed_nombrechiffres2(int *result, int base, intmax_t nb)
{
	while (nb >= base)
	{
		nb /= base;
		(*result)++;
	}
}

int		signed_nombrechiffres(intmax_t nb, t_variables *variables)
{
	int		result;
	int		base;

	if (variables->spe == 'd' || variables->spe == 'i'
			|| variables->spe == 'D' || variables->spe == 'u')
		base = 10;
	if (variables->spe == 'o' || variables->spe == 'O')
		base = 8;
	if (variables->spe == 'x' || variables->spe == 'X')
		base = 16;
	result = 1;
	if (nb == 0)
	{
		if (variables->pre == 0)
			return (0);
		return (1);
	}
	if (nb < -9223372036854775807)
		return (19);
	if (nb < 0)
		nb = -nb;
	signed_nombrechiffres2(&result, base, nb);
	return (result);
}

void	unsigned_nombrechiffres2(int *result, unsigned long long base,
		unsigned long long nb)
{
	while (nb >= base)
	{
		nb /= base;
		(*result)++;
	}
}

int		nombrechiffres(unsigned long long nb, t_variables *variables)
{
	int					result;
	unsigned long long	base;

	if (variables->spe == 'd' || variables->spe == 'i'
			|| variables->spe == 'D' || variables->spe == 'u')
		base = 10;
	if (variables->spe == 'o' || variables->spe == 'O')
		base = 8;
	if (variables->spe == 'x' || variables->spe == 'X' || variables->spe == 'p')
		base = 16;
	result = 1;
	if (nb == 0)
	{
		if (variables->pre == 0 || (variables->pre == -1 && variables->die == 1
					&& variables->spe != 'x' && variables->spe != 'X'))
			return (0);
		return (1);
	}
	unsigned_nombrechiffres2(&result, base, nb);
	if ((variables->spe == 'o' || variables->spe == 'O') && variables->die == 1)
		result++;
	return (result);
}
