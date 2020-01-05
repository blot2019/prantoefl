/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:10:27 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:19:14 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double					signed_float(va_list *factor, int flags[])
{
	if (flags[6] >= 0 && flags[7] < 0)
		flags[7] = 0;
	else if (flags[6] < 0 && flags[7] < 0)
		flags[7] = 6;
	if (flags[8] == 111)
		return ((long double)va_arg((*factor), long double));
	else
		return ((long double)va_arg((*factor), double));
}

void						nbr_double_len(long double nbr, int flags[])
{
	int i;

	i = 0;
	while (nbr > 1)
	{
		nbr /= 10;
		i++;
	}
	flags[10] = i;
	if (i > 16)
		flags[11] = i - 16;
}

void						kill_wide_f(long double *nbr, int flags[])
{
	if ((flags[6] >= 0 && flags[7] > 0) || (flags[6] < 0 && flags[7] == 6) ||
			flags[3] >= 0)
		flags[5]--;
	if (*nbr < 0)
	{
		flags[5]--;
		flags[9] = 1;
		*nbr = -(*nbr);
	}
	if (flags[1] >= 0 && flags[9] < 0)
		flags[5]--;
	else if (flags[2] >= 0 && flags[9] < 0 && flags[1] < 0)
		flags[5]--;
	nbr_double_len((*nbr), flags);
	flags[5] -= (flags[10] + flags[7]);
}

void						flags_f(int flags[], int *i)
{
	if (flags[1] >= 0 && flags[9] < 0)
	{
		ft_putchar('+');
		(*i)++;
	}
	else if (flags[2] >= 0 && flags[9] < 0 && flags[1] < 0)
	{
		ft_putchar(' ');
		(*i)++;
	}
	if (flags[9] >= 0)
	{
		ft_putchar('-');
		(*i)++;
	}
}

void						evolution(long double *evo, int flags[])
{
	int i;

	i = flags[7] + 1;
	if (flags[7] == 0)
		(*evo) = 0.41;
	else
		(*evo) = 0.5;
	while (i-- && i > 0)
		(*evo) /= 10;
}
