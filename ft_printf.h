/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:04:02 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/14 23:36:37 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

//# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
//# include "./printest.c"

int					ft_printf(char *blabla, ...);

typedef struct		s_variables
{
	int		diese;
	int		espace;
	int		zero;
	int		moins;
	int		plus;
	int		gabarit;
	int		precision;
	char	modificateur;
	char	specificateur;

}					t_variables;


#endif
