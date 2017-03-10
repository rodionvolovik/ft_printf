/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:29:58 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 09:38:46 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#define H 0
#define L 1
#define J 2
#define Z 3

void	get_flags(char format, t_form **farg)
{
	if (format == '-')
		(*farg)->left = 1;
	else if (format == ' ' && !(*farg)->sign)
		(*farg)->sign = ' ';
	else if (format == '#')
		(*farg)->hash = 1;
	else if (format == '+')
		(*farg)->sign = '+';
	else if (format == '0' && !(*farg)->left)
		(*farg)->pad = 48;
}

void	get_width(va_list *args, const char **format, t_form **farg)
{
	if (**format == '*')
	{
		(*farg)->width = va_arg(*args, int);
		if ((*farg)->width < 0)
		{
			(*farg)->width *= -1;
			(*farg)->left = 1;
		}
		(*format)++;
	}
	else
	{
		(*farg)->width = 0;
		while (ft_isdigit(**format))
			(*farg)->width = (*farg)->width * 10 + (*(*format)++ - '0');
	}
}

void	get_precision(va_list *args, const char **format, t_form **farg)
{
	if (*(*format)++ == '.')
	{
		if (**format == '*')
		{
			(*farg)->precision = va_arg(*args, int);
			(*format)++;
		}
		else
		{
			(*farg)->precision = 0;
			while (ft_isdigit(**format))
				(*farg)->precision = (*farg)->precision * 10
									+ (*(*format)++ - '0');
		}
	}
}

void	get_size_mod(const char **format, t_form **farg)
{
	if (**format == 'h')
		(*farg)->size[H] += 1;
	else if (**format == 'l')
		(*farg)->size[L] += 1;
	else if (**format == 'j')
		(*farg)->size[J] += 1;
	else if (**format == 'z')
		(*farg)->size[Z] += 1;
	(*format)++;
}

void	size_mod_choose(t_form **farg)
{
	if ((*farg)->size[Z])
		(*farg)->size_mod = 'z';
	else if ((*farg)->size[J])
		(*farg)->size_mod = 'j';
	else if ((*farg)->size[L])
	{
		if ((*farg)->size[L] >= 2)
			(*farg)->size_mod = 2 * 'l';
		else
			(*farg)->size_mod = 'l';
	}
	else if ((*farg)->size[H])
	{
		if ((*farg)->size[H] >= 2)
			(*farg)->size_mod = 2 * 'h';
		else
			(*farg)->size_mod = 'h';
	}
}
