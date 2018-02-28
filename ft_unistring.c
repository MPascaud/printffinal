/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:25:52 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 21:15:20 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_unisize(wchar_t c)
{
	int		ret;

	ret = 0;
	if (c <= 127)
		ret = ft_size_one(c);
	if (c >= 128 && c <= 2047)
		ret = ft_size_two(c);
	if (c >= 2048 && c <= 65535)
		ret = ft_size_three(c);
	if (c >= 65536)
		ret = ft_size_four(c);
	return (ret);
}

void	ft_uni_len(wchar_t *i, wchar_t *len, wchar_t **tmp)
{
	while ((*tmp)[(*i)])
	{
		if ((*tmp)[(*i)] <= 127)
			(*len)++;
		if ((*tmp)[(*i)] >= 128 && (*tmp)[(*i)] <= 2047)
			(*len) += 2;
		if ((*tmp)[(*i)] >= 2048 && (*tmp)[(*i)] <= 65535)
			(*len) += 3;
		if ((*tmp)[(*i)] >= 65536)
			(*len) += 4;
		(*i)++;
	}
}

int		uni_there_is_not(wchar_t *i, wchar_t *len,
		wchar_t **tmp, t_variables *variables)
{
	int		ret;

	ret = 0;
	while (((*i) + (*len)) < variables->gab)
	{
		write(1, " ", 1);
		ret++;
		(*i)++;
	}
	if (variables->pre == 0)
		return (ret);
	(*i) = 0;
	while ((*tmp)[(*i)])
	{
		ret += ft_unisize((*tmp)[(*i)]);
		(*i)++;
	}
	return (ret);
}

int		uni_there_is_min(wchar_t *i, wchar_t *len,
		wchar_t **tmp, t_variables *variables)
{
	int		ret;

	ret = 0;
	while ((*tmp)[(*i)])
	{
		ret += ft_unisize((*tmp)[(*i)]);
		(*i)++;
	}
	(*i) = 0;
	while (((*i) + (*len)) < variables->gab)
	{
		write(1, " ", 1);
		ret++;
		(*i)++;
	}
	return (ret);
}

int		ft_unistring(va_list args, t_variables *variables)
{
	int		ret;
	wchar_t	*tmp;
	wchar_t	i;
	wchar_t	len;
	wchar_t gabarit;

	gabarit = (wchar_t)variables->gab;
	i = 0;
	ret = 0;
	len = 0;
	tmp = (wchar_t*)va_arg(args, wchar_t*);
	if (tmp == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_uni_len(&i, &len, &tmp);
	i = 0;
	if (variables->pre == 0)
		len = 0;
	if (variables->moi == 0)
		ret = uni_there_is_not(&i, &len, &tmp, variables);
	if (variables->moi == 1)
		ret = uni_there_is_min(&i, &len, &tmp, variables);
	return (ret);
}
