/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:36:57 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:17:49 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			signed_arg(va_list *factor, int flags[])
{
	if (flags[8] == 4)
		return ((short int)va_arg((*factor), int));
	else if (flags[8] == 44)
		return ((char)va_arg((*factor), int));
	else if (flags[8] == 1)
		return (va_arg((*factor), long int));
	else if (flags[8] == 11)
		return (va_arg((*factor), long long int));
	else
		return (va_arg((*factor), int));
}

unsigned long long int	unsigned_arg(va_list *factor, int flags[])
{
	if (flags[8] == 4)
		return ((unsigned short int)va_arg((*factor), unsigned int));
	else if (flags[8] == 44)
		return ((unsigned char)va_arg((*factor), unsigned int));
	else if (flags[8] == 1)
		return (va_arg((*factor), unsigned long int));
	else if (flags[8] == 11)
		return (va_arg((*factor), unsigned long long int));
	else if (flags[9] == 'p')
		return ((unsigned long long int)va_arg((*factor), void *));
	else
		return (va_arg((*factor), unsigned int));
}

int						print_char(va_list *factor, char sp, int flags[])
{
	int		i;
	char	c;

	i = 0;
	c = (char)va_arg((*factor), int);
	if (sp && flags[5] < 0)
	{
		ft_putchar(c);
		i++;
	}
	else if (flags[0] >= 0)
	{
		ft_putchar(c);
		while (++i < flags[5])
			ft_putchar(' ');
	}
	else
	{
		while (++i < flags[5])
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (i);
}
