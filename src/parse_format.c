/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:19:54 by fculator          #+#    #+#             */
/*   Updated: 2019/11/11 20:51:40 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(t_tab *tab)
{
	tab->i++;
	initialisation(tab);
	parse_flag(tab);
	parse_mod(tab);
	parse_specifier(tab);
}

void	parse_specifier(t_tab *tab)
{
	if (tab->format[tab->i] == '%')
		format_percent(tab);
	else if (tab->format[tab->i] == 'd' || tab->format[tab->i] == 'i')
		format_int(tab);
	else if (tab->format[tab->i] == 's')
		format_str(tab);
	else if (tab->format[tab->i] == 'c')
		format_char(tab);
	else if (tab->format[tab->i] == 'x')
		format_base(tab);
	else if (tab->format[tab->i] == 'X')
		format_base(tab);
	else if (tab->format[tab->i] == 'o')
		format_base(tab);
	else if (tab->format[tab->i] == 'p')
		format_pointer(tab);
	else if (tab->format[tab->i] == 'u')
		format_base(tab);
	else if (tab->format[tab->i] == 'f')
		format_float(tab);
}

void	parse_mod(t_tab *tab)
{
	if (tab->format[tab->i] != 'h' && tab->format[tab->i] != 'l')
		tab->mod.nomod = 1;
	if (tab->format[tab->i] == 'l' && tab->format[tab->i + 1] == 'l')
	{
		tab->mod.ll = 1;
		tab->i += 2;
	}
	if (tab->format[tab->i] == 'l' && tab->format[tab->i + 1] != 'l')
	{
		tab->mod.l = 1;
		tab->i++;
	}
	if (tab->format[tab->i] == 'h' && tab->format[tab->i + 1] == 'h')
	{
		tab->mod.hh = 1;
		tab->i += 2;
	}
	if (tab->format[tab->i] == 'h' && tab->format[tab->i + 1] != 'h')
	{
		tab->mod.h = 1;
		tab->i++;
	}
	if (tab->format[tab->i] == 'L')
	{
		tab->mod.L = 1;
		tab->i++;
	}
}

void	parse_flag(t_tab *tab)
{
	while (ft_strchr("#-+0123456789. ", tab->format[tab->i]))
	{
		if (tab->format[tab->i] == ' ')
			(tab->flag.space = 1);
		if (tab->format[tab->i] == '-')
			(tab->flag.minus = 1);
		if (tab->format[tab->i] == '#')
			(tab->flag.hash = 1);
		if (tab->format[tab->i] == '+')
			(tab->flag.plus = 1);
		if (tab->format[tab->i] == '0')
			(tab->flag.zero = 1);
		if (tab->format[tab->i] == '.')
			tab->flag.precision = get_number_tab(tab);
		else if (tab->format[tab->i] > '0' && tab->format[tab->i] <= '9'
			&& tab->flag.precision < 0)
			tab->flag.width = get_number_tab(tab);
		else
			tab->i++;
	}
}

int		get_number_tab(t_tab *tab)
{
	int		num;

	num = 0;
	if (tab->format[tab->i] == '.')
		tab->i++;
	while (tab->format[tab->i] >= '0' && tab->format[tab->i] <= '9')
	{
		num = num * 10 + (tab->format[tab->i] - '0');
		++tab->i;
	}
	return (num);
}
