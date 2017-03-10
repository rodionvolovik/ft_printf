/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolovik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 08:32:54 by rvolovik          #+#    #+#             */
/*   Updated: 2017/03/10 17:34:09 by rvolovik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_form
{
	int			left;
	int			pad;
	int			sign;
	int			hash;
	int			width;
	int			precision;
	int			size_mod;
	int			zero;
	int			arglen;
	char		*arg;
	int			*size;
}				t_form;

void			ft_memdel_struct(t_form **farg);
void			get_size_mod(const char **format, t_form **farg);
void			size_mod_choose(t_form **farg);
char			*to_upper_string(char *s);
void			division_base(uint64_t value, size_t base, char *ans, int *p);
char			*ft_itoa_base(uint64_t value, size_t base);
char			*form_nbr_string(uint64_t nbr, t_form **farg,
								size_t base, char c);
void			print_address(va_list *args, const char **format,
								t_form **farg, size_t base);
void			print_percent(t_form **farg, const char **format);
void			ft_wputchar(uint64_t c, int width, t_form **farg);
void			print_chars(uint64_t c, const char **format, t_form **farg);
void			print_string(va_list *args, const char **format, t_form **farg);
void			print_hex_uns_oct(va_list *args, const char **format,
									t_form **farg, size_t base);
void			print_decimal(va_list *args, const char **format,
								t_form **farg);
void			print_arg(va_list *args, const char **format, t_form **farg);
void			get_flags(char format, t_form **farg);
void			get_width(va_list *args, const char **format, t_form **farg);
void			get_precision(va_list *args, const char **format,
								t_form **farg);
void			get_format(va_list *args, const char **format, t_form **farg);
int				get_format_printf(va_list *args, const char *format, int ret);
void			init_format_struct(t_form **farg);
int				ft_printf(const char *format, ...);
void			put_width_char(t_form **farg, int width);
int				print_width(int width, char pad);
int				put_sign(int sign);
int				putprecision(int len);
int				putwidth(int len, char pad, t_form **farg);
void			form_1(t_form **farg, char *arg_string, char *hash_sign,
						char c);
void			form_2(t_form **farg, char c, char *arg_string,
						char *hash_sign);
void			form_3(t_form **farg, char c, char *arg_string,
						char *hash_sign);
#endif
