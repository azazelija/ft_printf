/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_additional_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:46:26 by fculator          #+#    #+#             */
/*   Updated: 2019/11/18 15:38:31 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_width_str(t_tab *tab)
{
	int len;

	len = (int)ft_strlen(tab->out);
	while (tab->flag.width-- > len)
	{
		if (tab->flag.zero == 1)
			tab->ret += write(tab->fd, "0", 1);
		if (tab->flag.zero == 0)
			tab->ret += write(tab->fd, " ", 1);
	}
}

void	printf_width_char(t_tab *tab)
{
	while (tab->flag.width-- > 1)
	{
		if (tab->flag.zero == 1)
			tab->ret += write(tab->fd, "0", 1);
		if (tab->flag.zero == 0)
			tab->ret += write(tab->fd, " ", 1);
	}
}
