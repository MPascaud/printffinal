/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:46:56 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 23:20:07 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	string_space(int *i, int *ret)
{
	write(1, " ", 1);
	(*ret)++;
	(*i)++;
}

void	string_print(char **tmp, int *ret, int *i)
{
	ft_putchar((*tmp)[(*i)]);
	(*ret)++;
	(*i)++;
}

void	string_there_is_min(t_variables *variables, int *len,
		char **tmp, int *ret)
{
	int		i;

	i = 0;
	while (i < (*len))
		string_print(&(*tmp), &(*ret), &i);
	while (i < variables->gab)
		string_space(&i, &(*ret));
}

int		string_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int		ft_string(va_list args, t_variables *variables)
{
	char	*tmp;
	int		len;
	int		i;
	int		ret;

	len = 0;
	i = 0;
	ret = 0;
	tmp = (char*)va_arg(args, char*);
	if (tmp == NULL)
		return (string_null());
	len = ft_strlen(tmp);
	if (len > variables->pre && variables->pre != -1)
		len = variables->pre;
	if (variables->moi == 0)
	{
		while ((i + len) < variables->gab)
			string_space(&i, &ret);
		i = 0;
		while (i < len)
			string_print(&tmp, &ret, &i);
	}
	if (variables->moi == 1)
		string_there_is_min(variables, &len, &tmp, &ret);
	return (ret);
}
