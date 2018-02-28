/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:46:56 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 17:40:48 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int		ft_string(va_list args, t_variables *variables)
{
	char    *tmp;
	int     len;
	int     i;
	int		ret;

	len = 0;
	i = 0;
	ret = 0;
	tmp = (char*)va_arg(args, char*);
	if (tmp == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(tmp);
	if (len > variables->pre && variables->pre != -1)
		len = variables->pre;
	if (variables->moi == 0)
	{
		while ((i + len) < variables->gab)
		{
			write (1, " ", 1);
			ret++;
			i++;
		}
		i = 0;
		while (i < len)
		{
			ft_putchar(tmp[i]);
			ret++;
			i++;
		}
	}
	if (variables->moi == 1)
	{
		while (i < len)
		{
			ft_putchar(tmp[i]);
			ret++;
			i++;
		}
		while (i < variables->gab)
		{
			write(1, " ", 1);
			ret++;
			i++;
		}
	}
	return (ret);
}

