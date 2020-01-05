/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:44:06 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/07 16:42:44 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	only_wide_o(unsigned long long int *nbr, int flags[], int *i, int base)
{
	int wide;

	wide = flags[5] - flags[10];
	if (flags[4] >= 0 && flags[0] < 0)
	{
		wide = flags[5] - flags[10];
		flags_o(nbr, flags, i);
		to_side_o(((*nbr) && flags[3] >= 0) ? wide - 1 : wide, '0', i);
		(*i) += print_itoa((*nbr), base, (char)flags[9]);
	}
	else if (flags[0] < 0)
	{
		to_side_o(wide, ' ', i);
		flags_o(nbr, flags, i);
		(*i) += print_itoa((*nbr), base, (char)flags[9]);
	}
	else
	{
		flags_o(nbr, flags, i);
		(*i) += print_itoa((*nbr), base, (char)flags[9]);
		to_side_o(wide, ' ', i);
	}
}

void	only_precision_o(unsigned long long int *nbr, int flags[],\
						int *i, int base)
{
	int len;

	len = nbr_len((*nbr), base);
	if (flags[7] < len)
	{
		flags_o(nbr, flags, i);
		if (*nbr || (!(*nbr) && flags[3] > 0))
			(*i) += print_itoa((*nbr), base, (char)flags[9]);
	}
	else
	{
		flags_o(nbr, flags, i);
		to_side_o(flags[7] - len, '0', i);
		(*i) += print_itoa((*nbr), base, (char)flags[9]);
	}
}

void	precision_o(unsigned long long int *nbr, int flags[], int *i, int base)
{
	int len;

	len = flags[10];
	if (flags[7] >= len)
		len = flags[5] - flags[7];
	else
		len = flags[5] - len;
	if (flags[5] < 0 || flags[5] < flags[7])
		only_precision_o(nbr, flags, i, base);
	else
	{
		if (flags[0] < 0)
		{
			to_side_o(len, ' ', i);
			only_precision_o(nbr, flags, i, base);
		}
		else
		{
			only_precision_o(nbr, flags, i, base);
			to_side_o(len, ' ', i);
		}
	}
}

int		print_o(va_list *factor, int flags[], char sp)
{
	int						i;
	int						base;
	unsigned long long int	nbr;

	i = 0;
	base = 8;
	flags[9] = (int)sp;
	nbr = unsigned_arg(factor, flags);
	kill_wide_o(&nbr, flags);
	flags[10] = nbr_len(nbr, base);
	if (flags[7] > flags[10])
		flags[10] = flags[7];
	if (flags[5] < 0 && flags[7] < 0)
	{
		flags_o(&nbr, flags, &i);
		i += print_itoa(nbr, base, (char)flags[9]);
	}
	if (flags[5] >= 0 && flags[7] < 0)
		only_wide_o(&nbr, flags, &i, base);
	if (flags[7] >= 0)
		precision_o(&nbr, flags, &i, base);
	return (i);
}
