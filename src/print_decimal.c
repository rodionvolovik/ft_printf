/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:11:49 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 10:12:19 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_decimal(va_list *args, const char **format, t_form **farg)
{
	int64_t		n;
	uint64_t	nbr;

	n = 0;
	nbr = 0;
	if (**format != 'D' && !(*farg)->size_mod)
		n = va_arg(*args, int);
	else if ((*farg)->size_mod == 'l')
		n = va_arg(*args, long);
	else if (**format == 'D' || (*farg)->size_mod == 2 * 'l')
		n = va_arg(*args, long long);
	else if ((*farg)->size_mod == 'h')
		n = (short)va_arg(*args, int);
	else if ((*farg)->size_mod == 2 * 'h')
		n = (char)va_arg(*args, int);
	else if ((*farg)->size_mod == 'j')
		n = va_arg(*args, intmax_t);
	else if ((*farg)->size_mod == 'z')
		n = va_arg(*args, size_t);
	(*farg)->sign = (n < 0) ? '-' : (*farg)->sign;
	nbr = ((*farg)->sign == '-') ? -n : n;
	(*farg)->zero = (n == 0) ? 1 : 0;
	form_nbr_string(nbr, farg, 10, **format);
	(*format)++;
}
