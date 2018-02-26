/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:58:50 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/13 19:12:48 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*blop;
	size_t			i;

	i = 0;
	blop = (unsigned char*)s;
	while (i < n)
	{
		if (*blop == (unsigned char)c)
		{
			return (blop);
		}
		blop++;
		i++;
	}
	return (NULL);
}
