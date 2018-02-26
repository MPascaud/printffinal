/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:00:07 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/22 18:06:56 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*blop;
	int		i;

	i = 0;
	blop = (char*)s;
	if (!*s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (&blop[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return (&blop[i]);
	}
	return (NULL);
}
