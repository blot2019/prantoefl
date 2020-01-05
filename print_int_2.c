/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:10:45 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:10:48 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					kill_wide_di(long long int *nbr, int flags[])
{
	if (((flags[7] > 0 || flags[6] < 0)))
	{
		if (*nbr < 0)
		{
			flags[10]++;
			flags[9] = 1;
			*nbr = -(*nbr);
		}
		if (flags[1] >= 0 && *nbr >= 0 && flags[9] < 0)
			flags[10]++;
		else if (flags[2] >= 0 && *nbr >= 0 && flags[1] < 0 && flags[9] < 0)
			flags[10]++;
	}
	if (!(*nbr) && flags[7] == 0 && flags[1] < 0)
		flags[5]++;
}

void					flags_di(long long int *nbr, int flags[], int *i)
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
	if (flags[9] >= 0 && (*nbr))
	{
		ft_putchar('-');
		(*i)++;
	}
}

void					to_side_di(int wide, char field, int *i)
{
	while (wide-- && wide >= 0)
	{
		ft_putchar(field);
		(*i)++;
	}
}

void					only_wide_di_next(long long int *nbr,\
							int flags[], int *i, int wide)
{
	flags_di(nbr, flags, i);
	if (!(*nbr) && flags[6] >= 0)
		;
	else
		(*i) += print_itoa((*nbr), 10, 'x');
	to_side_di(wide, ' ', i);
}
