/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:45:42 by fculator          #+#    #+#             */
/*   Updated: 2019/11/11 20:46:08 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reload_output_with_pointer(t_tab *tab)
{
	char	*tmp;
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (int)ft_strlen(tab->out);
	if (tab->flag.precision > len)
	{
		tmp = ft_strnew(tab->flag.precision - len);
		while (++i < tab->flag.precision - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, tab->out);
		free(tab->out);
		free(tmp);
		tab->out = res;
	}
	tmp = ft_strjoin("0x", tab->out);
	free(tab->out);
	tab->out = tmp;
}

void 	printf_pointer_width(t_tab *tab)
{
	int len;

	len = ft_strlen(tab->out);
	while (tab->flag.width-- > len)
		tab->ret += write(tab->fd, " ", 1);
};