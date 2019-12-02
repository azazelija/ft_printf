/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:19:54 by fculator          #+#    #+#             */
/*   Updated: 2019/11/18 15:36:49 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reload_output_with_precision(t_tab *tab)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	len = (int)ft_strlen(tab->out);
	tab->format[tab->i] == 'o' && tab->flag.hash == 1 ?
		tab->flag.precision-- : 0;
	if (tab->flag.precision == 0 && tab->out[0] == '0')
	{
		tab->out[0] = '\0';
		tab->flag.hash = 0;
	}
	else if (tab->flag.precision > len)
	{
		i = tab->flag.precision - len;
		tmp = ft_strnew(i);
		while (i-- > 0)
			tmp[i] = '0';
		res = ft_strjoin(tmp, tab->out);
		free(tmp);
		free(tab->out);
		tab->out = res;
	}
}

void	initialisation(t_tab *tab)
{
	tab->sign = 0;
	tab->flag.plus = 0;
	tab->flag.precision = -1;
	tab->flag.width = 0;
	tab->flag.hash = 0;
	tab->flag.minus = 0;
	tab->flag.zero = 0;
	tab->flag.space = 0;
}

void	format_percent(t_tab *tab)
{
	if (tab->flag.minus)
	{
		tab->ret += write(tab->fd, "%", 1);
		while (tab->flag.width-- > 1)
			tab->ret += write(tab->fd, " ", 1);
	}
	else
	{
		while (tab->flag.width-- > 1)
			if (tab->flag.zero)
				tab->ret += write(tab->fd, "0", 1);
			else
				tab->ret += write(tab->fd, " ", 1);
		tab->ret += write(tab->fd, "%", 1);
	}
	++tab->i;
}
