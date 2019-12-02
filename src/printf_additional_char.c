/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_additional_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:46:26 by fculator          #+#    #+#             */
/*   Updated: 2019/11/18 15:37:38 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_width(t_tab *tab)
{
	if (tab->flag.width >= 0 && tab->flag.zero == 0)
		ft_put_space(tab);
	if (tab->flag.width >= 0 && tab->flag.zero == 1)
		ft_put_space_zero(tab);
}

void	printf_hash(t_tab *tab)
{
	if (tab->flag.hash == 1 && tab->out != '\0' && ft_atoi(tab->out) != 0)
	{
		tab->ret += (tab->format[tab->i] == 'o') ? write(tab->fd, "0", 1) : 0;
		tab->ret += (tab->format[tab->i] == 'x') ? write(tab->fd, "0x", 2) : 0;
		tab->ret += (tab->format[tab->i] == 'X') ? write(tab->fd, "0X", 2) : 0;
	}
	else if (tab->format[tab->i] == 'o' && tab->flag.hash == 1
			&& tab->flag.precision >= 0)
	{
		tab->ret += write(tab->fd, "0", 1);
	}
}

void	ft_check_sign(t_tab *tab)
{
	char *tmp;

	if (tab->out[0] == '-')
	{
		tmp = ft_strdup(tab->out + 1);
		free(tab->out);
		tab->out = tmp;
		tab->sign = -1;
		tab->flag.plus = 0;
		tab->flag.space = 0;
	}
	else if (tab->flag.plus == 1)
	{
		tab->sign = 1;
		tab->flag.space = 0;
	}
}

void	printf_sign(t_tab *tab)
{
	if (tab->sign == 1 || tab->flag.space == 1)
	{
		if (tab->flag.plus == 1)
			tab->ret += write(tab->fd, "+", 1);
		else
			tab->ret += write(tab->fd, " ", 1);
	}
	else if (tab->sign == -1)
		tab->ret += write(tab->fd, "-", 1);
}
