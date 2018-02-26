/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdlefaux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:08:21 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:02:10 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		ft_putchar_fd((char)s[i], fd);
		i++;
	}
}
