/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_nbr_string_parts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:07:50 by rvolovik          #+#    #+#             */
/*   Updated: 2017/03/10 18:08:35 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	form_1(t_form **farg, char *arg_string, char *hash_sign, char c)
{
	(*farg)->width -= (*farg)->sign >= 32 ? 1 : 0;
	(*farg)->pad = (*farg)->precision >= 0 ? ' ' : (*farg)->pad;
	if (((*farg)->precision -= (int)ft_strlen(arg_string)) > 0)
		(*farg)->width -= (*farg)->precision + (int)ft_strlen(arg_string);
	else
		(*farg)->width -= ft_strlen(arg_string);
	if ((c == 'x' || c == 'X' || c == 'o' || c == 'O')
		&& (*arg_string != '0') && (*farg)->hash)
	{
		if ((c == 'o' || c == 'O')
			&& (*farg)->precision >= (int)ft_strlen(hash_sign))
			(*farg)->precision -= (int)ft_strlen(hash_sign);
		else if ((*farg)->width >= (int)ft_strlen(hash_sign) ||
			(*farg)->width < 0)
			(*farg)->width -= (int)ft_strlen(hash_sign);
		else if ((*farg)->precision > (int)ft_strlen(hash_sign))
			(*farg)->precision -= (int)ft_strlen(hash_sign);
	}
}

void	form_2(t_form **farg, char c, char *arg_string, char *hash_sign)
{
	if ((*farg)->pad == '0' && (c == 'x' || c == 'X')
		&& *arg_string != '0' && *arg_string != '\0' && (*farg)->hash)
	{
		ft_putstr(hash_sign);
		(*farg)->arglen += (int)ft_strlen(hash_sign);
	}
	if ((*farg)->pad == '0' && (c == 'o' || c == 'O')
		&& *arg_string != '0' && (*farg)->hash)
	{
		ft_putstr(hash_sign);
		(*farg)->arglen += (int)ft_strlen(hash_sign);
	}
	if (!(*farg)->left)
	{
		(*farg)->arglen += putwidth((*farg)->width, (*farg)->pad, farg);
		(*farg)->sign = 0;
	}
	if ((*farg)->pad != '0' && (c == 'x' || c == 'X')
		&& *arg_string != '0' && *arg_string != '\0' && (*farg)->hash)
	{
		ft_putstr(hash_sign);
		(*farg)->arglen += (int)ft_strlen(hash_sign);
	}
}

void	form_3(t_form **farg, char c, char *arg_string, char *hash_sign)
{
	if ((*farg)->pad != '0' && (c == 'o' || c == 'O')
		&& *arg_string != '0' && (*farg)->hash)
	{
		ft_putstr(hash_sign);
		(*farg)->arglen += (int)ft_strlen(hash_sign);
	}
	if ((*farg)->left)
	{
		(*farg)->arglen += put_sign((*farg)->sign);
		(*farg)->sign = 0;
	}
	(*farg)->arglen += putprecision((*farg)->precision);
	ft_putstr(arg_string);
	if ((*farg)->left)
		(*farg)->arglen += putwidth((*farg)->width, (*farg)->pad, farg);
	(*farg)->arglen += ft_strlen(arg_string);
}
