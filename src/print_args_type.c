/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:46:48 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 09:48:47 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_arg(va_list *args, const char **format, t_form **farg)
{
	if (**format == 'd' || **format == 'i' || **format == 'D')
		print_decimal(args, format, farg);
	else if ((**format == 'x' || **format == 'X') && !((*farg)->sign = 0))
		print_hex_uns_oct(args, format, farg, 16);
	else if ((**format == 'o' || **format == 'O') && !((*farg)->sign = 0))
		print_hex_uns_oct(args, format, farg, 8);
	else if ((**format == 'u' || **format == 'U') && !((*farg)->sign = 0))
		print_hex_uns_oct(args, format, farg, 10);
	else if (**format == 'p')
		print_address(args, format, farg, 16);
	else if (**format == '%')
		print_percent(farg, format);
	else if (**format == 'c' || **format == 'C')
		print_chars((unsigned char)va_arg(*args, int), format, farg);
	else if (**format == 's' || **format == 'S')
		print_string(args, format, farg);
	else if (**format != '\0')
		print_chars(**format, format, farg);
	else
		return ;
}
