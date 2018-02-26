/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:05:55 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/15 13:59:15 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*ptr;

	if (!f || !lst)
		return (NULL);
	ptr = f(lst);
	if (!ptr || !(lst2 = ft_lstnew(ptr->content, ptr->content_size)))
		return (NULL);
	if (lst->next)
		lst2->next = ft_lstmap(lst->next, f);
	return (lst2);
}
