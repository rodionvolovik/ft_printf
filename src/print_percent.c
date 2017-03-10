/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 10:15:24 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 10:16:08 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_percent(t_form **farg, const char **format)
{
	if ((*farg)->width > 1 && !(*farg)->left)
		put_width_char(farg, (*farg)->width - 1);
	ft_putchar('%');
	(*farg)->arglen += 1;
	if ((*farg)->width > 1 && (*farg)->left)
		put_width_char(farg, (*farg)->width - 1);
	(*format)++;
}
