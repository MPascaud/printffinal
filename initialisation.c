/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:16:54 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/26 19:27:54 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

void	initialisation(t_variables *variables)
{
	variables->diese = 0;
	variables->espace = 0;
	variables->zero = 0;
	variables->moins = 0;
	variables->plus = 0;
	variables->gabarit = 0;
	variables->precision = -1;
	variables->modificateur = 'a';
}
