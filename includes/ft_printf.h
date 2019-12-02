/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:08:40 by fculator          #+#    #+#             */
/*   Updated: 2019/10/30 20:29:54 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdint.h>
# include <wchar.h>

typedef struct			s_mod
{
	int	nomod;
	int h;
	int hh;
	int	l;
	int ll;
	int L;

}						t_mod;

typedef struct			s_flag
{
	int	hash;
	int zero;
	int minus;
	int plus;
	int precision;
	int width;
	int space;
}						t_flag;

typedef struct			s_tab
{
	char	*format;
	char	*out;
	int		ret;
	int		fd;
	int		i;
	int 	sign;
	va_list	list;
	t_flag	flag;
	t_mod	mod;
}						t_tab;

int		ft_printf(const char *s, ...);
void	parse_format(t_tab *tab);
void	parse_mod(t_tab *tab);
void	parse_flag(t_tab *tab);
void	parse_specifier(t_tab *tab);
void	format_int(t_tab *tab);
void	printf_int(t_tab *tab);
void	format_str(t_tab *tab);
void	printf_str(t_tab *tab);
void	format_char(t_tab *tab);
void	printf_char(t_tab *tab, char c);
void	format_base(t_tab *tab);
void	printf_base(t_tab *tab);
void	format_pointer(t_tab *tab);
void	printf_pointer(t_tab *tab);
int		get_number_tab(t_tab *tab);
void	printf_null(t_tab *tab);
void	printf_width(t_tab *tab);
void	ft_put_space(t_tab *tab);
void	ft_put_space_zero(t_tab *tab);
void	printf_hash(t_tab *tab);
void	reload_output_with_precision(t_tab *tab);
void	format_percent(t_tab *tab);
void	ft_check_sign(t_tab *tab);
void	printf_sign(t_tab *tab);
void	initialisation(t_tab *tab);
void	printf_width_str(t_tab *tab);
void	printf_width_char(t_tab *tab);
void	reload_output_with_pointer(t_tab *tab);
void 	printf_pointer_width(t_tab *tab);
void	format_float(t_tab *tab);
void	printf_float(t_tab *tab, long double output);
void	reload_float(t_tab *tab, long double output);
long	get_prec_num_f(long double d, int prec);
char	*ft_float_itoa(long double d);
char	*ft_str_prec(char *s1, int dot, int end, int hash);
void	print_prec_width(t_tab *tab);
#endif
