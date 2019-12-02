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

void	reload_float(t_tab *tab, long double output)
{
	char	*tmp;
	char	*nb;
	long	num;
	int		precis;

	tmp = ft_float_itoa((long)output);
	precis = ft_strlen(tmp);
	num = get_prec_num_f(output, (tab->flag.precision >= 0 ? tab->flag.precision : 6));
	nb = (num == 0 ? ft_strdup("0.000000") : ft_float_itoa(num));
	if (tab->flag.precision == 0)
		tab->out = ft_strdup(tmp);
	else
		tab->out = ft_str_prec(nb, precis, tab->flag.precision >= 0 ?
										   precis + tab->flag.precision : precis + 6, tab->flag.hash);
	free(nb);
	free(tmp);
}

long	get_prec_num_f(long double d, int prec)
{
	int		neg;
	int		i;

	i = -1;
	neg = (d < 0 ? -1 : 1);
	d *= neg;
	while (++i < prec)
		d *= 10;
	d += 0.5;
	d *= neg;
	return ((long)d);
}

char	*ft_str_prec(char *s1, int dot, int end, int hash)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + 1);
	while (s1[++i] != '\0')
	{
		tmp[j++] = s1[i];
		if ((i == dot - 1 && end > 0) || hash == 1)
		{
			tmp[j++] = '.';
			hash = 0;
		}
		if (i > end)
		{
			tmp[j] = '\0';
			break ;
		}
	}
	return (tmp);
}