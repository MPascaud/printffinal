/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:45:20 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 13:58:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*blop;

	while (lst)
	{
		blop = lst->next;
		f(lst);
		lst = blop;
	}
}
