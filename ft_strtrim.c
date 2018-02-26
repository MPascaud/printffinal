/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimlefaux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 22:57:06 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:03:09 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static size_t		ft2(const char *s)
{
	size_t		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*
**i[0] = i ; i[1] = cases ; i[2] = debut ; i[3] = fin
*/

char				*ft_strtrim(char const *s)
{
	char	*str1;
	size_t	i[4];

	i[0] = -1;
	i[1] = 0;
	i[2] = -1;
	i[3] = 0;
	if (!s)
		return (NULL);
	while (s[++i[2]] == ' ' || s[i[2]] == '\n' || s[i[2]] == '\t')
		;
	while (s[ft2(s) - 1 - i[3]] == ' ' || s[ft2(s) - 1 - i[3]] == '\n'
				|| s[ft2(s) - 1 - i[3]] == '\t')
		i[3]++;
	if (ft2(s) == i[3])
		i[3] = 0;
	if (!(str1 = (char*)malloc(sizeof(char) * ((ft2(s) - i[3] - i[2]) + 1))))
		return (NULL);
	while (s[++i[0]])
		if (i[0] >= i[2] && i[0] < (ft2(s) - i[3]))
			str1[i[1]++] = s[i[0]];
	str1[i[1]] = '\0';
	return (str1);
}
