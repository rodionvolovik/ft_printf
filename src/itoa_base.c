/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 09:41:27 by rvolovik          #+#    #+#             */
/*   Updated: 2017/02/24 09:44:59 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	division_base(uint64_t value, size_t base, char *ans, int *p)
{
	char	*base_s;

	base_s = "0123456789abcdef";
	if (base <= value)
		division_base(value / base, base, ans, p);
	ans[(*p)++] = base_s[value % base > 0 ? value % base : -(value % base)];
}

char	*ft_itoa_base(uint64_t value, size_t base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	division_base(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
