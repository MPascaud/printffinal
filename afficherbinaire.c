/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficherbinaire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:59:12 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 00:04:38 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	achage_binaire(unsigned int n)
{
	int		i;

	i = 31;
	printf("%d en binaire : ", n);
	while (i >= 0)
	{
		printf("%d", (n >> i) & 1);
		i--;
	}
	printf("\n");
}

