/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:46:22 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/07 16:44:59 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_wide(int w, int flags[], int *j)
{
	if (flags[5] > w)
	{
		w = flags[5] - w;
		while (w-- && w >= 0)
		{
			ft_putchar(' ');
			(*j)++;
		}
	}
}

void	str_put(char *str, int flags[], int *i)
{
	if (flags[7] < 0)
	{
		while (str[(*i)])
			ft_putchar(str[(*i)++]);
	}
	else if (flags[7] >= 0)
	{
		while (*i < flags[7] && str[(*i)])
			ft_putchar(str[(*i)++]);
	}
}

int		print_str(va_list *factor, char sp, int flags[])
{
	int		i;
	int		j;
	int		w;
	char	*str;

	i = 0;
	j = 0;
	w = 0;
	str = va_arg((*factor), char *);
	if (str)
		w = ft_strlen(str);
	else
		w = 6;
	if (flags[7] < w && flags[7] >= 0 && sp)
		w = flags[7];
	if (flags[0] < 0)
		str_wide(w, flags, &j);
	if (!str)
		str_put("(null)", flags, &i);
	else
		str_put(str, flags, &i);
	if (flags[0] >= 0)
		str_wide(w, flags, &j);
	return (i + j);
}
