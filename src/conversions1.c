/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 20:06:58 by basz          #+#    #+#                 */
/*   Updated: 2022/10/25 18:40:24 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	ft_start_convers(t_info info)
{
	int							number;
	static	t_convers_fts_array	convers_fts[20] = {
		[character] = &converse_c,
		[string] = &converse_s,
		[address] = &converse_p,
		[decimal_int] = &converse_d,
		[unsign_decimal_int] = &converse_u,
		[unsign_hexa_int_lc] = &converse_x,
		[unsign_hexa_int_uc] = &converse_x_upper,
		[percent_char] = &converse_percent_sign};

	if (info.str[info.pos] == '-' || ft_isdigit(info.str[info.pos]) == 1 ||
	info.str[info.pos] == '.' || info.str[info.pos] == '*')
		info = ft_flags(info);
	number = ft_assign_c(info.str[info.pos]);
	if (number == 8)
		return (info);
	info = convers_fts[number](info);
	return (info);
}

int		ft_assign_c(char c)
{
	if (c == 'c')
		return (0);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (2);
	if (c == 'd' || c == 'i')
		return (3);
	if (c == 'u')
		return (4);
	if (c == 'x')
		return (5);
	if (c == 'X')
		return (6);
	if (c == '%')
		return (7);
	else
		return (8);
}

t_info	converse_c(t_info info)
{
	char x;

	x = va_arg(info.list, int);
	info.ret = info.width;
	if (info.width != -1)
	{
		if (info.left_just == 1)
			write(1, &x, 1);
		info = ft_padding(info, 1);
	}
	if (info.left_just == 0 || info.width == -1)
		write(1, &x, 1);
	if (info.ret < 1)
		info.ret = 1;
	return (info);
}

t_info	converse_s(t_info info)
{
	char	*str;
	int		len;

	str = va_arg(info.list, char *);
	len = ft_strlen(str);
	info.ret = len;
	if (info.prec != -1 && info.prec < len && info.prec < info.width)
		info.width = info.width + len - info.prec;
	info = ft_write_string(info, len, str);
	if (info.prec != -1 && info.prec < len &&
	(info.prec < info.width || info.width == -1))
		info.ret = info.ret - len + info.prec;
	return (info);
}

t_info	converse_p(t_info info)
{
	void	*x;
	int		len;

	x = va_arg(info.list, void *);
	len = ft_itoa_hex_address(x, 0, 0) + 2;
	info.ret = len;
	if (info.width > len)
		info.ret = info.width;
	if (info.left_just == 1)
	{
		write(1, "0x", 2);
		len = ft_itoa_hex_address(x, 0, 1) + 2;
		info = ft_padding(info, len);
	}
	while (info.width > len)
		info = ft_padding(info, len);
	if (info.left_just == 0)
	{
		write(1, "0x", 2);
		ft_itoa_hex_address(x, 0, 1);
	}
	return (info);
}
