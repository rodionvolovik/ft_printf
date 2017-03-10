/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:05:15 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 09:07:49 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init_format_struct(t_form **farg)
{
	int		i;

	i = 0;
	(*farg)->left = 0;
	(*farg)->pad = ' ';
	(*farg)->sign = 0;
	(*farg)->hash = 0;
	(*farg)->width = 0;
	(*farg)->precision = -1;
	(*farg)->size_mod = 0;
	(*farg)->zero = 0;
	(*farg)->arglen = 0;
	(*farg)->arg = NULL;
	(*farg)->size = (int *)malloc(sizeof(int) * 4);
	while (i < 4)
		(*farg)->size[i++] = 0;
}

void	get_format(va_list *args, const char **format, t_form **farg)
{
	if (*(*format)++ == '%')
	{
		while (ft_strchr("#0-+ lhjz.*1234567890", **format) &&
				!(ft_strchr("diDxXoOsScCp", **format)))
		{
			if (**format == '0' || **format == ' ' || **format == '#'
				|| **format == '+' || **format == '-')
				get_flags(*(*format)++, farg);
			else if (**format == '*' || ft_isdigit(**format))
				get_width(args, format, farg);
			else if (**format == '.')
				get_precision(args, format, farg);
			else if (**format && ft_strchr("hljz", **format))
				get_size_mod(format, farg);
		}
	}
	size_mod_choose(farg);
	print_arg(args, format, farg);
}

int		get_format_printf(va_list *args, const char *format, int ret)
{
	char	*fstart;
	char	*tmp;
	t_form	*farg;

	farg = (t_form*)malloc(sizeof(t_form));
	fstart = ft_strchr(format, '%');
	if (*format == '\0')
		return (ret);
	else if (fstart == NULL)
	{
		ft_putstr(format);
		return (ret + (int)ft_strlen(format));
	}
	else if (fstart > format)
	{
		ft_putstr(tmp = ft_strsub(format, 0, fstart - format));
		free(tmp);
		return (get_format_printf(args, fstart, ret + (int)(fstart - format)));
	}
	else
	{
		init_format_struct(&farg);
		get_format(args, &format, &farg);
		return (get_format_printf(args, format, ret + farg->arglen));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;

	ret = 0;
	va_start(args, format);
	if (!*format)
		return (0);
	ret = get_format_printf(&args, format, ret);
	va_end(args);
	return (ret);
}
