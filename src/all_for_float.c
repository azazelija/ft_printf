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

void	format_float(t_tab *tab)
{
	long double		output;
	double 			long_output;

	if (tab->mod.L)
	{
		output = va_arg(tab->list, long double);
	}
	else {
		long_output = va_arg(tab->list, double);
		output = (long double)long_output;
	}
	printf_float(tab, output);
}

void	printf_float(t_tab *tab, long double output)
{
	reload_float(tab, output);
	if (tab->flag.minus)
	{
		if (output > 0 && (tab->flag.plus || tab->flag.space))
		{
			if (tab->flag.plus == 1)
				tab->ret += write(tab->fd, "+", 1);
			else
				write(tab->fd, " ", 1);
		}
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		print_prec_width(tab);
	}
	else
	{
		if (ft_atoi(tab->out) > 0 && (tab->flag.plus || tab->flag.space))
		{
			if (tab->flag.plus == 1)
				tab->ret += write(tab->fd, "+", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
		}
		print_prec_width(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	++tab->i;
	free(tab->out);
}

void	print_prec_width(t_tab *tab)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(tab->out) + tab->flag.plus + tab->flag.space;
	if (tab->flag.precision >= 0)
	{
		while (tab->flag.width - ++i > len)
			if (tab->flag.zero)
				tab->ret += write(tab->fd, "0", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
		i = 0;
		while ((int)ft_strlen(tab->out) < len - ++i)
			tab->ret += write(tab->fd, "0", 1);
	}
	else
		while (tab->flag.width - ++i > len)
			if (tab->flag.zero == 1)
				tab->ret += write(tab->fd, "0", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
}