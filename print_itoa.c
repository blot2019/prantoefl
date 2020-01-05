/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:42:16 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/07 16:07:34 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int								nbr_len(unsigned long long int nbr,\
											int base)
{
	int len;
	int mark;

	len = 0;
	mark = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / base;
		len++;
	}
	return (len + mark);
}

static unsigned long long int	ft_pow(int len, int base)
{
	unsigned long long int c;

	c = 1;
	while (len > 0)
	{
		c = c * base;
		len--;
	}
	return (c);
}

static void						ft_upload(unsigned long long nbr,\
											int len, int base, char sp)
{
	int		i;
	char	*digit;

	digit = "0123456789abcdef";
	i = 0;
	while (--len > 0)
	{
		if (sp == 'X')
			ft_putchar(ft_toupper(digit[nbr / ft_pow(len, base)]));
		else
			ft_putchar(digit[nbr / ft_pow(len, base)]);
		nbr = nbr - (nbr / ft_pow(len, base)) * ft_pow(len, base);
		i++;
	}
	if (sp == 'X')
		ft_putchar(ft_toupper(digit[nbr]));
	else
		ft_putchar(digit[nbr]);
}

int								print_itoa(unsigned long long int n,\
											int base, char sp)
{
	int						i;
	int						len;
	unsigned long long int	nbr;

	nbr = n;
	i = 0;
	len = nbr_len(nbr, base);
	ft_upload(nbr, len, base, sp);
	return (len);
}
