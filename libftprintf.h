/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:02:32 by mpascaud          #+#    #+#             */
/*   Updated: 2018/02/28 19:41:56 by mpascaud         ###   ########.fr       */
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
typedef struct	s_variables
{
	int		die;
	int		esp;
	int		zer;
	int		moi;
	int		plu;
	int		gab;
	int		pre;
	char	mod;
	char	spe;
}				t_variables;
typedef struct	s_unsigned_vari
{
	uintmax_t	tmp;
	int			chi;
	int			i;
	int			j;
	int			ret;
}				t_unsigned_vari;
/*typedef struct	s_unsigned_hexa
{
	uintmax_t	tmp;
	int			chi;
	int			i;
	int			j;
	int			ret;
}				t_unsigned_hexa;*/
void	ft_space(t_unsigned_vari *uv);
void	ft_write_zero(t_unsigned_vari *uv);








void	ft_init_v2(t_vari2 *v2);
void    ft_flags(t_variables *variables, t_vari2 *v2, char *b);
void    ft_gabarit(t_variables *variables, t_vari2 *v2, char *b);
void    ft_precision(t_variables *variables, t_vari2 *v2, char *b);
void    ft_modificateur(t_variables *variables, t_vari2 *v2, char *b);
int				ft_printf(char *b, ...);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void    ft_unsigned_putnbr(uintmax_t nb, t_variables *variables, int nbchiffres, int tmp);
int		ft_unsigned(va_list args, t_variables *variables);
int		ft_unsigned_hexa(va_list args, t_variables *variables);
void	ft_unsigned_cast(va_list args, t_variables *variables, uintmax_t *tmp);
void			ft_putnbr(intmax_t nb, t_variables *variables, int nbchiffres, int tmp);
int		ft_size_one(wchar_t c);
int		ft_size_two(wchar_t c);
int		ft_size_three(wchar_t c);
int		ft_size_four(wchar_t c);
int		ft_unicharacter(va_list args);
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
