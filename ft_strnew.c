/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewlefaux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:52:00 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/29 20:45:57 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*bla;
	size_t	i;

	i = 0;
	if (!(bla = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		bla[i] = '\0';
		i++;
	}
	bla[i] = '\0';
	return (bla);
}
