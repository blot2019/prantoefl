/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:09:22 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/07 16:23:30 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_after_dot(long double *nbr, int flags[], int *i)
{
	int				printer;

	while (flags[7]-- && flags[7] >= 0)
	{
		(*nbr) *= 10;
		printer = (int)((*nbr));
		(*i) += print_itoa(printer, 10, 'x');
		(*nbr) -= (long double)((int)(*nbr));
	}
}

void						print_f(long double *nbr, int flags[], int *i)
{
	long long		to_typo;
	long double		evo;

	evolution(&evo, flags);
	(*nbr) += evo;
	while (flags[11]-- > 0)
		*nbr /= 10;
	flags[11] = flags[10] - 16;
	to_typo = (long long int)((*nbr));
	(*i) += print_itoa(to_typo, 10, 'x');
	while (flags[11]-- > 0)
	{
		ft_putchar('0');
		(*i)++;
	}
	(*nbr) -= (long double)to_typo;
	if ((flags[6] >= 0 && flags[7] > 0) || (flags[6] < 0 && flags[7] == 6) ||
					flags[3] >= 0)
	{
		ft_putchar('.');
		(*i)++;
	}
	ft_after_dot(nbr, flags, i);
}

void						to_side_f(int wide, char field, int *i)
{
	while (wide-- && wide >= 0)
	{
		ft_putchar(field);
		(*i)++;
	}
}

void						only_wide_f(long double *nbr, int flags[], int *i)
{
	if (flags[5 > 0] && flags[0] > 0)
	{
		flags_f(flags, i);
		print_f(nbr, flags, i);
		to_side_f(flags[5], (char)(' '), i);
	}
	else
	{
		flags_f(flags, i);
		print_f(nbr, flags, i);
	}
}

int							print_float(va_list *factor, char sp, int flags[])
{
	int				i;
	long double		nbr;

	i = 0;
	if (sp != 'f')
		return (0);
	nbr = signed_float(factor, flags);
	kill_wide_f(&nbr, flags);
	if (flags[5 > 0] && flags[0] < 0 && flags[4] < 0)
	{
		to_side_f(flags[5], ' ', &i);
		flags_f(flags, &i);
		print_f(&nbr, flags, &i);
	}
	else if (flags[5 > 0] && flags[0] < 0 && flags[4] > 0)
	{
		flags_f(flags, &i);
		to_side_f(flags[5], '0', &i);
		print_f(&nbr, flags, &i);
	}
	else
		only_wide_f(&nbr, flags, &i);
	return (i);
}
