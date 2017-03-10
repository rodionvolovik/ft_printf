/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:49:00 by rvolovik          #+#    #+#             */
/*   Updated: 2017/03/10 17:30:08 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_width_char(t_form **farg, int width)
{
	int		i;

	i = 0;
	while (i++ < width)
	{
		ft_putchar((*farg)->pad);
		(*farg)->arglen++;
	}
}

void	ft_wputchar(uint64_t c, int width, t_form **farg)
{
	if (width == 1)
		ft_putchar(c);
	else
	{
		if (width == 2)
			ft_putchar((c >> 6) + 192);
		else if (width == 3)
		{
			ft_putchar((c >> 12) + 224);
			ft_putchar(((c >> 6) & 63) + 128);
		}
		else if (width == 4)
		{
			ft_putchar((c >> 18) + 240);
			ft_putchar(((c >> 12) & 63) + 192);
			ft_putchar(((c >> 6) & 63) + 128);
		}
		ft_putchar((c & 63) + 128);
	}
	(*farg)->arglen += width;
}

void	print_chars(uint64_t c, const char **format, t_form **farg)
{
	if ((*farg)->width > 1 && !(*farg)->left)
		put_width_char(farg, (*farg)->width - 1);
	ft_putchar(c);
	(*farg)->arglen++;
	if ((*farg)->width > 1 && (*farg)->left)
		put_width_char(farg, (*farg)->width - 1);
	(*format)++;
}
