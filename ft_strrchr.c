/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrlefaux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:12:19 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/25 19:23:28 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*blop;
	int		i;
	int		j;
	int		k;

	blop = (char*)s;
	i = 0;
	j = 0;
	k = 0;
	if (!*s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			j = i;
			k = 1;
		}
		i++;
	}
	if (c == '\0')
		return (&blop[i]);
	if (j == 0 && k == 0)
		return (NULL);
	return (&blop[j]);
}
