/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:11:18 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:28:12 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printer(char *str, int *jindex, int *i)
{
	while (str[(*jindex)] != '%' && str[(*jindex)])
	{
		ft_putchar(str[(*jindex)++]);
		(*i)++;
	}
}

int				ft_printf(char *str, ...)
{
	int			i;
	int			jindex;
	va_list		factor;

	i = 0;
	jindex = 0;
	va_start(factor, str);
	while (str[jindex])
	{
		ft_printer(str, &jindex, &i);
		if (str[jindex] == '%')
		{
			if (str[jindex + 1] == '%')
			{
				ft_putchar(str[jindex++]);
				i++;
			}
			else if (str[jindex + 1])
				i += voyage(&str[++jindex], &factor, &jindex);
			if (str[jindex])
				jindex++;
		}
	}
	va_end(factor);
	return (i);
}
