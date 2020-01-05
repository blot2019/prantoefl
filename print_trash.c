/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:10:48 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/07 16:48:02 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		trash_pc(char sp, int *i)
{
	ft_putchar(sp);
	(*i)++;
}

int				print_trash(char sp, int flags[])
{
	int i;

	i = 0;
	if (flags[5] >= 0 && flags[0] >= 0)
	{
		ft_putchar(sp);
		i++;
		to_side_di(flags[5] - 1, ' ', &i);
	}
	else if (flags[5] >= 0 && flags[0] < 0 && flags[4] >= 0)
	{
		to_side_di(flags[5] - 1, '0', &i);
		ft_putchar(sp);
		i++;
	}
	else if (flags[5] >= 0)
	{
		to_side_di(flags[5] - 1, ' ', &i);
		ft_putchar(sp);
		i++;
	}
	else
		trash_pc(sp, &i);
	return (i);
}
