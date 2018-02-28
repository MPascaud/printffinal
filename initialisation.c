/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:16:54 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 17:44:11 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void	initialisation(t_variables *variables)
{
	variables->die = 0;
	variables->esp = 0;
	variables->zer = 0;
	variables->moi = 0;
	variables->plu = 0;
	variables->gab = 0;
	variables->pre = -1;
	variables->mod = 'a';
}
