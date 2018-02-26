/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloclefaux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:30:41 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:05:46 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if (size > 4294967295)
	{
		return (NULL);
	}
	if (!(mem = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
