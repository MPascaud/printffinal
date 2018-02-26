/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:05:05 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:02:50 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static int					ft_count_words(char const *str, char c)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int					ft_len(char const *str, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char						**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s || !(tab = (char**)malloc(sizeof(char*)
					* (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count_words(s, c))
	{
		k = 0;
		if (!(tab[i] = ft_strnew(ft_len(&s[j], c) + 1)))
			tab[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
