/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrlefaux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:10:01 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/25 22:36:39 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (n[i] == '\0')
	{
		return ((char*)h);
	}
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && (i + j) < len)
		{
			if (n[j + 1] == '\0')
			{
				return ((char*)(h + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
