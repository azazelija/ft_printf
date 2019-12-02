/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:27:43 by fculator          #+#    #+#             */
/*   Updated: 2019/11/18 15:36:18 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_put_space(t_tab *tab)
{
	int		count;

	count = 0;
	if (tab->flag.hash == 1 && (tab->out[0] != '\0' && tab->out[0] != '0'))
	{
		tab->format[tab->i] == 'o' ? tab->flag.width-- : 0;
		tab->format[tab->i] == 'x' || tab->format[tab->i] == 'X' ?
				tab->flag.width -= 2 : 0;
	}
	tab->flag.plus || tab->sign == 1 || tab->sign == -1 || tab->flag.space
	? tab->flag.width-- : 0;
	if (tab->flag.width > (int)ft_strlen(tab->out))
	{
		count = tab->flag.width - (int)ft_strlen(tab->out);
		while (--count >= 0)
		{
			tab->ret += write(tab->fd, " ", 1);
		}
	}
}

void		ft_put_space_zero(t_tab *tab)
{
	int count;
	int	len;

	count = 0;
	len = ((int)ft_strlen(tab->out) > tab->flag.precision ?
		(int)ft_strlen(tab->out) : tab->flag.precision);
	if (tab->flag.hash == 1)
	{
		tab->format[tab->i] == 'o' ? tab->flag.width-- : 0;
		tab->format[tab->i] == 'x' || tab->format[tab->i] == 'X' ?
			tab->flag.width -= 2 : 0;
	}
	tab->flag.plus || tab->sign == 1 || tab->sign == -1 || tab->flag.space
		? tab->flag.width-- : 0;
	if (tab->flag.width > (int)ft_strlen(tab->out))
	{
		count = tab->flag.width - (int)ft_strlen(tab->out);
		while (--count >= 0)
		{
			tab->ret += write(tab->fd, "0", 1);
		}
	}
}
