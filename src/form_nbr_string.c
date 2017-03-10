/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_nbr_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 08:50:47 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 08:50:49 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int		put_sign(int sign)
{
	if (sign)
	{
		ft_putchar(sign);
		return (1);
	}
	return (0);
}

int		putprecision(int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		i++;
		ft_putchar('0');
	}
	return (len > 0 ? len : 0);
}

int		putwidth(int len, char pad, t_form **farg)
{
	int		i;

	i = 0;
	if (pad == '0' && (*farg)->sign)
	{
		(*farg)->arglen += put_sign((*farg)->sign);
	}
	while (i < len)
	{
		i++;
		ft_putchar(pad);
	}
	if (pad == ' ' && (*farg)->sign)
	{
		(*farg)->arglen += put_sign((*farg)->sign);
	}
	return (len > 0 ? len : 0);
}

char	*form_nbr_string(uint64_t nbr, t_form **farg, size_t base, char c)
{
	char	*arg_string;
	char	*hash_sign;

	hash_sign = NULL;
	if (c == 'x' && (*farg)->hash)
		hash_sign = "0x";
	else if (c == 'X' && (*farg)->hash)
		hash_sign = "0X";
	else if (c == 'o' || c == 'O')
		hash_sign = "0";
	arg_string = ft_itoa_base(nbr, base);
	arg_string = ((*farg)->precision == 0 && *arg_string == '0')
					? "" : arg_string;
	if (c == 'X')
		arg_string = to_upper_string(arg_string);
	form_1(farg, arg_string, hash_sign, c);
	form_2(farg, c, arg_string, hash_sign);
	form_3(farg, c, arg_string, hash_sign);
	return (arg_string);
}
