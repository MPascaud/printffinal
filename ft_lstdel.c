/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:39:45 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 14:00:03 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2;
	}
	*alst = NULL;
}
