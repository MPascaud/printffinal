/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:03:20 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:07:16 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp[n];

	if (n > 134217727)
	{
		return (0);
	}
	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	return (dest);
}
