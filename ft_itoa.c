/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoalefaux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:03:56 by mpascaud          #+#    #+#             */
/*   Updated: 2017/11/25 17:16:28 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int			ft_count(int n)
{
	int		nb;
	int		count;

	nb = n;
	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char			*ft_itoa_zero(void)
{
	char	*bla;

	if (!(bla = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	bla[0] = (char)('0');
	bla[1] = '\0';
	return (bla);
}

static char			*ft_itoa_min(int n)
{
	char	*bla;

	if (n == 0)
		return (ft_itoa_zero());
	if (!(bla = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	bla[0] = '-';
	bla[1] = '2';
	bla[2] = '1';
	bla[3] = '4';
	bla[4] = '7';
	bla[5] = '4';
	bla[6] = '8';
	bla[7] = '3';
	bla[8] = '6';
	bla[9] = '4';
	bla[10] = '8';
	bla[11] = '\0';
	return (bla);
}

char				*ft_itoa(int n)
{
	char	*bla;
	int		i;
	int		nb;
	int		neg;

	i = -1;
	neg = 0;
	if (n == -2147483648 || n == 0 || n == -0)
		return (ft_itoa_min(n));
	if (n < 0)
		neg++;
	if (n < 0)
		n = n * (-1);
	nb = ft_count(n);
	if (!(bla = (char*)malloc(sizeof(char) * (nb + neg + 1))))
		return (NULL);
	if (neg == 1)
		bla[0] = '-';
	while (++i < nb)
	{
		bla[nb + neg - i - 1] = (char)((n % 10) + 48);
		n = n / 10;
	}
	bla[i + neg] = '\0';
	return (bla);
}
