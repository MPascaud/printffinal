/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:40:03 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 23:48:57 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unsigned_cast(va_list args, t_variables *variables, uintmax_t *tmp)
{
	if (variables->mod == 'a')
		*tmp = (unsigned int)va_arg(args, unsigned int);
	if (variables->mod == 'H')
		*tmp = (unsigned char)va_arg(args, unsigned int);
	if (variables->mod == 'h')
		*tmp = (unsigned short int)va_arg(args, unsigned int);
	if (variables->mod == 'l')
		*tmp = (unsigned long int)va_arg(args, unsigned long int);
	if (variables->mod == 'L')
		*tmp = (unsigned long long)va_arg(args, unsigned long long int);
	if (variables->mod == 'j')
		*tmp = (uintmax_t)va_arg(args, uintmax_t);
	if (variables->mod == 'z')
		*tmp = (size_t)va_arg(args, size_t);
}

void	ft_cast(va_list args, t_variables *variables, intmax_t *tmp)
{
	if (variables->mod == 'H')
		*tmp = (char)va_arg(args, int);
	if (variables->mod == 'h')
		*tmp = (short int)va_arg(args, int);
	if (variables->mod == 'l')
		*tmp = (long int)va_arg(args, long int);
	if (variables->mod == 'L')
		*tmp = (long long)va_arg(args, long long int);
	if (variables->mod == 'j')
		*tmp = (intmax_t)va_arg(args, intmax_t);
	if (variables->mod == 'z')
		*tmp = (size_t)va_arg(args, size_t);
}
