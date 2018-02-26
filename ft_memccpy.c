/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpylefaux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:35:32 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/13 19:03:39 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*blop;
	const unsigned char	*pfiou;

	blop = dest;
	pfiou = src;
	i = 0;
	while (i < n)
	{
		blop[i] = pfiou[i];
		if (pfiou[i] == (unsigned char)c)
		{
			return (&blop[i + 1]);
		}
		i++;
	}
	return (NULL);
}
