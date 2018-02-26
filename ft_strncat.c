/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncatlefaux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:18:30 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/14 19:53:56 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	while (dest[i])
	{
		i++;
	}
	len = i;
	i = 0;
	while (src[i] && i < n)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}
