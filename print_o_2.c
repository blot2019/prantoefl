/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:11:01 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:19:57 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_o(unsigned long long int *nbr, int flags[], int *i)
{
	if ((char)flags[9] == 'o' && (*nbr) && flags[3] >= 0)
	{
		if (flags[4] >= 0)
			flags[5]--;
		ft_putchar('0');
		(*i)++;
	}
}

void	kill_wide_o(unsigned long long int *nbr, int flags[])
{
	if (!(*nbr) && flags[7] == 0 && flags[9] == 'o' && flags[3] < 0)
		flags[5]++;
	else if (flags[3] >= 0 && (char)flags[9] == 'o' &&
			(*nbr) && flags[6] >= 0 && flags[7] >= 0)
	{
		flags[10]--;
		flags[7]--;
		flags[5]--;
	}
	if (*nbr && flags[3] >= 0 && flags[4] < 0 && flags[5] > 0 &&
			flags[6] < 0 && flags[7] < 0)
		flags[5]--;
}

void	to_side_o(int wide, char field, int *i)
{
	while (wide-- && wide >= 0)
	{
		ft_putchar(field);
		(*i)++;
	}
}
