/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:45:16 by rvolovik          #+#    #+#             */
/*   Updated: 2017/03/10 17:31:47 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_precision(int len)
{
	int		i;

	i = 0;
	while (i++ < len)
		ft_putchar('0');
	return (len > 0 ? len : 0);
}

int		print_width_add(int len, int pad)
{
	int		i;

	i = 0;
	while (i < len)
	{
		i++;
		ft_putchar(pad);
	}
	return (len > 0 ? len : 0);
}

void	print_address(va_list *args, const char **format,
						t_form **farg, size_t base)
{
	char	*str;

	str = ft_itoa_base((uintmax_t)va_arg(*args, void *), base);
	(*farg)->width -= ((*farg)->precision > (int)ft_strlen(str) ?
						(*farg)->precision : ft_strlen(str)) + 2;
	(*farg)->width += (*farg)->precision == 0 && *str == '0' ? 1 : 0;
	if (!(*farg)->left)
		(*farg)->arglen += print_width_add((*farg)->width, (*farg)->pad);
	ft_putstr("0x");
	(*farg)->arglen += 2;
	if (*str == '0' && (*farg)->precision == 0)
		ft_putstr("");
	else
	{
		(*farg)->arglen += print_precision((*farg)->precision -
							(int)ft_strlen(str));
		(*farg)->arglen += ft_strlen(str);
		ft_putstr(str);
	}
	if ((*farg)->left)
		(*farg)->arglen += print_width_add((*farg)->width, (*farg)->pad);
	(*format)++;
}
