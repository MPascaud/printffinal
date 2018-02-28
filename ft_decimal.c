/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 17:37:17 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"


int		ft_decimal(va_list args, t_variables *variables)
{
	//int					cast;
   	intmax_t				tmp;
 //  unsigned long long int	tmp;
	int					nbchiffres;
	int					i;
	int					j;
	int					ret;

	//cast = 0;
	i = 0;
	j = 0;
	ret = 0;
//	tmp = va_arg(args, long int);
//	printf("1--->%lld\n", tmp);
	if (variables->mod != 'a' && variables->spe != 'D')
		ft_cast(args, variables, &tmp);
		//cast = 1;
	if (variables->mod == 'a' && (variables->spe == 'd' || variables->spe == 'i') )
		tmp = va_arg(args, int);
//	if (variables->specificateur == 'o' && variables->modificateur != 'l')
//		tmp = va_arg(args, unsigned int);
	if (variables->spe == 'D')
		tmp = va_arg(args, long int);
//	if (variables->specificateur == 'o' && variables->modificateur == 'l')
//		tmp = va_arg(args, unsigned long);
	nbchiffres = signed_nombrechiffres(tmp, variables);
//	printf("nombre : %d\n", tmp);
//	printf("nbchiffres = %d\n", nbchiffres);
//	printf("test%llo\n", tmp);
	if (variables->moi == 0)
	{
		if ((variables->esp == 1 || variables->plu == 1) && tmp >= 0)
			i++;
		if (tmp < 0)
			i++;
		j = i;
		//printf("i = %d, nbchiffres = %d, variables->gabarit = %d\n", i, nbchiffres, variables->gabarit);
		while (((i < variables->gab - variables->pre) && (i < variables->gab - nbchiffres) && i < variables->pre + j) || ((i + nbchiffres) < variables->gab && variables->zer == 0 && (i + variables->pre) < variables->gab))
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
		if (variables->plu == 1 && tmp >= 0)
		{
			write(1, "+", 1);
			ret++;
		}
		if (variables->esp == 1 && variables->plu == 0 && tmp >= 0)
		{
			write(1, " ", 1);
			ret++;
		}
		if (tmp < 0 /*&& variables->specificateur != 'o'*/)
		{
			//printf("coucou");
			write(1, "-", 1);
			tmp = -tmp;
			ret++;
		}
//		printf("i = %d\n", i);
		j = i;
		i = 0;
//		printf("i, j, nbchiffres, gabarit: %d / %d /%d / %d\n", i, j, nbchiffres, variables->gabarit);
		while (((i < variables->pre - nbchiffres) || (j + i + nbchiffres) < variables->gab) /*&& (i < variables->gabarit - nbchiffres)*/)
		{
			write(1, "0", 1);
			ret++;
			i++;
		}
	//	printf("avant%llo\n", tmp);
		ft_putnbr(tmp, variables, nbchiffres, 0);
	//	printf("apres%llo\n", tmp);
		ret += nbchiffres;
//		printf("nombrechiffres = %d\n", nbchiffres);

	}
	if (variables->moi == 1)
	{
		if (variables->plu == 1 && tmp >= 0)
		{
			write(1, "+", 1);
			ret++;
		}
		if (variables->esp == 1 && variables->plu == 0 && tmp >= 0)
		{
			write(1, " ", 1);
			ret++;
		}
		if ((variables->esp == 1 || variables->plu == 1) && tmp >= 0)
			i++;
		if (variables->plu == 0 && tmp >= 0)
			i++;
		if (tmp < 0)
		{
			write(1, "-", 1);
			tmp = -tmp;
			ret++;
			j++;
			i++;
		}
		while (i <= (variables->pre - nbchiffres))
		{
			write(1, "0", 1);
			ret++;
			i++;
		}
		ft_putnbr(tmp, variables, nbchiffres, 0);
		ret += nbchiffres;
		i += nbchiffres;
//		printf("i = %d\n", i);
		if (variables->plu == 0 && j == 0)
			i--;
		while (i < variables->gab)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);	

}
