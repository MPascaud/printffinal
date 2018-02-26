/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcatlefauxlefaux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:39:03 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:06:37 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (dest[i] && i < size)
	{
		i++;
	}
	k = i;
	while (src[j] && i < size - 1)
	{
		dest[i++] = src[j++];
	}
	if (k < size)
	{
		dest[i] = '\0';
	}
	return (k + ft_strlen(src));
}
