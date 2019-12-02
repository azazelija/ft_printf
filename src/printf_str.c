/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:42 by fculator          #+#    #+#             */
/*   Updated: 2019/11/18 15:42:55 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_str(t_tab *tab)
{
	char	*tmp;
	if (tab->flag.precision >= 0 && tab->flag.precision
			< (int)ft_strlen(tab->out))
	{
		tmp = ft_strsub(tab->out, 0, (tab->flag.precision));
		free(tab->out);
		tab->out = tmp;
	}
	if (tab->flag.minus)
	{
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
		printf_width_str(tab);
	}
	else
	{
		printf_width_str(tab);
		tab->ret += write(tab->fd, tab->out, ft_strlen(tab->out));
	}
	tab->i++;
	free(tab->out);
}

void	printf_char(t_tab *tab, char c)
{
	if (tab->flag.minus == 1)
	{
		tab->ret += write(tab->fd, &c, 1);
		printf_width_char(tab);
	}
	else
	{
		printf_width_char(tab);
		tab->ret += write(tab->fd, &c, 1);
	}
	tab->i++;
}

void	printf_null(t_tab *tab)
{
	tab->ret += write(tab->fd, "(null)", 6);
	tab->i++;
}
