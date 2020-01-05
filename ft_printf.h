/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemerald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:20:02 by gemerald          #+#    #+#             */
/*   Updated: 2019/11/09 18:16:22 by gemerald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int						voyage(char *str, va_list *factor, int *jindex);
int						print_int(va_list *factor, char sp, int flags[]);
int						print_float(va_list *factor, char sp, int flags[]);
int						print_str(va_list *factor, char sp, int flags[]);
int						print_itoa(unsigned long long int n, int base, char sp);
int						nbr_len(unsigned long long nbr, int base);
unsigned long long int	unsigned_arg(va_list *factor, int flags[]);
long long int			signed_arg(va_list *factor, int flags[]);
void					kill_wide_di(long long int *nbr, int flags[]);
void					kill_wide_o(unsigned long long int *nbr, int flags[]);
void					flags_di(long long int *nbr, int flags[], int *i);
void					to_side_di(int wide, char field, int *i);
void					to_side_o(int wide, char field, int *i);
void					flags_u(unsigned long long int *nbr, int flags[],\
								int *i);
void					flags_o(unsigned long long int *nbr, int flags[],\
								int *i);
void					kill_wide(unsigned long long int *nbr, int flags[]);
void					to_side_u(int wide, char field, int *i);
void					only_wide_di_next(long long int *nbr,\
							int flags[], int *i, int wide);
void					only_wide_u_next(unsigned long long int *nbr,\
								int flags[], int *i, int base);
void					only_wide_u(unsigned long long int *nbr,\
									int flags[], int *i, int base);
int						print_u(va_list *factor, int flags[], char sp);
int						print_trash(char sp, int flags[]);
int						voyager_wp(char *str, int flags[], va_list *factor);
void					move_wild(int flags[], int *to_wp);
int						voyager_size(char *str, int flags[]);
int						find_type(va_list *factor, char sp, int flags[]);
int						print_str(va_list *factor, char sp, int flags[]);
int						print_char(va_list *factor, char sp, int flags[]);
int						print_o(va_list *factor, int flags[], char sp);
long double				signed_float(va_list *factor, int flags[]);
void					nbr_double_len(long double nbr, int flags[]);
void					kill_wide_f(long double *nbr, int flags[]);
void					flags_f(int flags[], int *i);
void					evolution(long double *evo, int flags[]);

#endif
