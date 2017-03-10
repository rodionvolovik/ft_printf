/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:32:19 by rvolovik          #+#    #+#             */
/*   Updated: 2017/03/10 17:33:25 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_str_prec(t_form **farg, char *s)
{
	int		i;

	i = 0;
	if ((*farg)->precision < (int)ft_strlen(s) && (*farg)->precision >= 0)
	{
		while (i++ < (*farg)->precision)
		{
			ft_putchar(*s++);
			(*farg)->arglen++;
		}
	}
	else
	{
		ft_putstr(s);
		(*farg)->arglen += ft_strlen(s);
	}
}

int		print_width(int width, char pad)
{
	int		i;

	i = 0;
	while (i++ < width)
		ft_putchar(pad);
	return (width > 0 ? width : 0);
}

void	print_str(va_list *args, t_form **farg)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	if ((*farg)->precision < (int)ft_strlen(s) && (*farg)->precision > 1)
		(*farg)->width -= (*farg)->precision;
	else
		(*farg)->width -= ft_strlen(s);
	if (!(*farg)->left)
		(*farg)->arglen += print_width((*farg)->width, (*farg)->pad);
	print_str_prec(farg, s);
	if ((*farg)->left)
		(*farg)->arglen += print_width((*farg)->width, ' ');
}

void	print_wstr(va_list *args, t_form **farg)
{
	wchar_t	*s;
	int		width;

	s = va_arg(*args, wchar_t *);
	while (*s != '\0')
	{
		if (*s <= 0x7F)
			width = 1;
		else if (*s <= 0x7FF)
			width = 2;
		else if (*s <= 0xFFFF)
			width = 3;
		else if (*s <= 0x1FFFFF)
			width = 4;
		ft_wputchar(*s++, width, farg);
	}
}

void	print_string(va_list *args, const char **format, t_form **farg)
{
	if (**format == 'S' || (**format == 's' && (*farg)->size_mod == 'l'))
		print_wstr(args, farg);
	else
		print_str(args, farg);
	(*format)++;
}
