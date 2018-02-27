/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:02:32 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/27 17:27:34 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <inttypes.h>


# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_vari2
{
	int		i;
	int		modulo;
	char	*gabarit_str;
	char	*precision_str;
	int		j;
	int		point;
	int		ret;

}				t_vari2;
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
int				ft_printf(char *blabla, ...);
typedef struct	s_variables
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
}				t_variables;
void    ft_unsigned_putnbr(uintmax_t nb, t_variables *variables, int nbchiffres, int tmp);
int		ft_unsigned(va_list args, t_variables *variables);
int		ft_unsigned_hexa(va_list args, t_variables *variables);
void	ft_unsigned_cast(va_list args, t_variables *variables, uintmax_t *tmp);
void			ft_putnbr(intmax_t nb, t_variables *variables, int nbchiffres, int tmp);
int		ft_size_one(wchar_t c);
int		ft_size_two(wchar_t c);
int		ft_size_three(wchar_t c);
int		ft_size_four(wchar_t c);
int		ft_unicharacter(va_list args, t_variables *variables);
int		ft_unistring(va_list args, t_variables *variables);
int		ft_string(va_list args, t_variables *variables);
int		ft_character(va_list args, t_variables *variables);
int			nombrechiffres(unsigned long long nb, t_variables *variables);
int		signed_nombrechiffres(intmax_t nb, t_variables *variables);
int		ft_decimal(va_list args, t_variables *variables);
void			initialisation(t_variables *variables);
int			ft_argument(va_list args, t_variables *variables);
void		ft_cast(va_list args, t_variables *variables, intmax_t *tmp);

#endif
