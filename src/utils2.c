/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 20:01:40 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 14:46:02 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	ft_padzero_unsigned(int len, t_info info)
{
	while (info.prec > len)
	{
		write(1, "0", 1);
		len++;
		info.ret++;
	}
	return (info);
}

t_info	ft_padzero(int x, int len, t_info info)
{
	if (x < 0 && info.prec != -1)
	{
		write(1, "-", 1);
		info.ret++;
		len--;
	}
	while (info.prec > len)
	{
		write(1, "0", 1);
		len++;
		info.ret++;
	}
	return (info);
}

t_info	ft_padding(t_info info, int len)
{
	if (info.pad_zero == 1)
	{
		while (info.width > len && info.left_just == 0)
		{
			write(1, "0", 1);
			info.width--;
		}
	}
	if (info.pad_zero == 0 || (info.pad_zero == 1 && info.left_just == 1))
	{
		while (info.width > len)
		{
			write(1, " ", 1);
			info.width--;
		}
	}
	return (info);
}

t_info	ft_width_for_d(t_info info, int x, int len)
{
	if (x < 0 && info.prec != -1)
	{
		len--;
		info.ret--;
	}
	if (info.prec > len)
	{
		if (info.width > info.prec)
			info.ret = info.ret - (info.prec - len);
		info.width = info.width - (info.prec - len);
	}
	return (info);
}

t_info	ft_width_for_u(t_info info, int len)
{
	if (info.prec > len)
	{
		if (info.width > info.prec)
			info.ret = info.ret - (info.prec - len);
		info.width = info.width - (info.prec - len);
	}
	return (info);
}
