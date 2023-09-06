/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 19:56:33 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 14:46:12 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	converse_d(t_info info)
{
	int x;
	int len;

	x = va_arg(info.list, int);
	len = ft_nbr_len(x);
	if (x < 0 && info.prec == -1 && info.pad_zero == 1)
		write(1, "-", 1);
	if (info.prec != -1)
		info.pad_zero = 0;
	info.ret = len;
	if (info.width > len && info.prec < info.width)
		info.ret = info.width;
	info = ft_width_for_d(info, x, len);
	if (info.left_just == 1)
	{
		info = ft_padzero(x, len, info);
		ft_write_nbr(x, info);
	}
	info = ft_padding(info, len);
	if (info.left_just == 0)
	{
		info = ft_padzero(x, len, info);
		ft_write_nbr(x, info);
	}
	return (info);
}

t_info	converse_u(t_info info)
{
	unsigned int	x;
	int				len;

	x = va_arg(info.list, unsigned int);
	len = ft_itoa_base_len(x, 0, 0, 10);
	if (info.prec != -1)
		info.pad_zero = 0;
	info.ret = len;
	if (info.width > len && info.prec < info.width)
		info.ret = info.width;
	info = ft_width_for_u(info, len);
	if (info.left_just == 1)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 0, 10);
	}
	info = ft_padding(info, len);
	if (info.left_just == 0)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 0, 10);
	}
	if (x == 0)
		info.ret++;
	return (info);
}

t_info	converse_x(t_info info)
{
	long int	x;
	int			len;

	x = va_arg(info.list, long int);
	len = ft_itoa_base_len(x, 0, 0, 16);
	if (info.prec != -1)
		info.pad_zero = 0;
	info.ret = len;
	if (info.width > len && info.prec < info.width)
		info.ret = info.width;
	info = ft_width_for_u(info, len);
	if (info.left_just == 1)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 0, 16);
	}
	info = ft_padding(info, len);
	if (info.left_just == 0)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 0, 16);
	}
	if (x == 0)
		info.ret++;
	return (info);
}

t_info	converse_x_upper(t_info info)
{
	long int	x;
	int			len;

	x = va_arg(info.list, long int);
	len = ft_itoa_base_len(x, 0, 1, 16);
	if (info.prec != -1)
		info.pad_zero = 0;
	info.ret = len;
	if (info.width > len && info.prec < info.width)
		info.ret = info.width;
	info = ft_width_for_u(info, len);
	if (info.left_just == 1)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 1, 16);
	}
	info = ft_padding(info, len);
	if (info.left_just == 0)
	{
		info = ft_padzero_unsigned(len, info);
		ft_itoa_base(x, 0, 1, 16);
	}
	if (x == 0)
		info.ret++;
	return (info);
}

t_info	converse_percent_sign(t_info info)
{
	info.ret = info.width;
	if (info.left_just == 1)
		write(1, "%", 1);
	info = ft_padding(info, 1);
	if (info.left_just == 0)
		write(1, "%", 1);
	if (info.ret < 1)
		info.ret = 1;
	return (info);
}
