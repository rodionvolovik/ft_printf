/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_uns_oct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:13:25 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 10:15:12 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_hex_uns_oct(va_list *args, const char **format,
							t_form **farg, size_t base)
{
	uint64_t	nbr;

	nbr = 0;
	if (!(*farg)->size_mod && **format != 'O' && **format != 'U')
		nbr = va_arg(*args, unsigned);
	else if ((*farg)->size_mod == 'l')
		nbr = va_arg(*args, unsigned long);
	else if ((*farg)->size_mod == 2 * 'l' || **format == 'O' || **format == 'U')
		nbr = va_arg(*args, unsigned long long);
	else if ((*farg)->size_mod == 'h')
		nbr = (unsigned short)va_arg(*args, unsigned int);
	else if ((*farg)->size_mod == 2 * 'h')
		nbr = (unsigned char)va_arg(*args, unsigned int);
	else if ((*farg)->size_mod == 'j')
		nbr = va_arg(*args, uintmax_t);
	else if ((*farg)->size_mod == 'z')
		nbr = va_arg(*args, size_t);
	form_nbr_string(nbr, farg, base, **format);
	(*format)++;
}
