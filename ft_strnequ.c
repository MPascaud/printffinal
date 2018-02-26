/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:20:27 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/21 21:49:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			return (0);
		}
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
