/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:19:54 by fculator          #+#    #+#             */
/*   Updated: 2019/11/11 20:38:25 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_int(t_tab *tab)
{
	long long	output;

	if (tab->flag.minus == 1)
		tab->flag.zero = 0;
	if (tab->flag.precision > 0)
		tab->flag.zero = 0;
	output = va_arg(tab->list, long long);
	if (output == LLONG_MIN || output == LONG_MIN)
		tab->out = ft_strdup("-9223372036854775808");
	if (tab->mod.hh == 1)
		tab->out = ft_itoa((char)output);
	if (tab->mod.h == 1)
		tab->out = ft_itoa((short)output);
	if (tab->mod.l == 1 || tab->mod.ll == 1)
		tab->out = ft_long_itoa((long)output);
	if (tab->mod.nomod == 1)
		tab->out = ft_itoa((int)output);
	printf_int(tab);
}

void	format_str(t_tab *tab)
{
	char	*output;

	if (tab->flag.minus == 1)
		tab->flag.zero = 0;
	output = va_arg(tab->list, char *);
	if (output == NULL)
		return (printf_null(tab));
	tab->out = ft_strdup(output);
	printf_str(tab);
}

void	format_char(t_tab *tab)
{
	int		output;

	if (tab->flag.minus == 1)
		tab->flag.zero = 0;
	output = va_arg(tab->list, int);
	printf_char(tab, output);
}

void	format_base(t_tab *tab)
{
	unsigned long	output;

	if (tab->flag.minus == 1)
		tab->flag.zero = 0;
	output = va_arg(tab->list, unsigned long);
	if (tab->mod.h == 1)
		output = (unsigned short)output;
	tab->mod.hh == 1 ? output = (unsigned char)output : 0;
	tab->mod.nomod == 1 ? output = (unsigned int)output : 0;
	tab->format[tab->i] == 'x' ? tab->out = ft_itoa_base(output, 16) : 0;
	tab->format[tab->i] == 'X' ? tab->out = ft_itoa_up_base(output, 16) : 0;
	tab->format[tab->i] == 'o' ? tab->out = ft_itoa_base(output, 8) : 0;
	tab->format[tab->i] == 'u' ? tab->out = ft_itoa_base(output, 10) : 0;
	printf_base(tab);
}

void	format_pointer(t_tab *tab)
{
	unsigned long	output;

	output = va_arg(tab->list, unsigned long);
	if (tab->flag.precision == 0)
		tab->out = ft_strdup("\0");
	else
		tab->out = ft_itoa_base(output, 16);
	printf_pointer(tab);
}
