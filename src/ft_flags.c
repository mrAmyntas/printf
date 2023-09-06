/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 17:46:14 by basz          #+#    #+#                 */
/*   Updated: 2021/04/16 18:21:23 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	ft_determine_prec(t_info info)
{
	int		store;
	char	*prec;

	store = info.pos;
	while (info.str[info.pos] >= '0' && info.str[info.pos] <= '9')
	{
		info.index++;
		info.pos++;
	}
	if (info.str[info.pos] == '*')
	{
		info.pos++;
		info.prec = va_arg(info.list, int);
		if (info.prec < 0)
			info.prec = -1;
		return (info);
	}
	if (info.index == 0)
	{
		info.prec = 0;
		return (info);
	}
	prec = ft_substr(info.str, store, info.index);
	info.prec = ft_atoi(prec);
	return (info);
}

t_info	ft_determine_width(t_info info)
{
	int		store;
	char	*width;

	store = info.pos;
	while (info.str[info.pos] >= '0' && info.str[info.pos] <= '9')
	{
		info.index++;
		info.pos++;
	}
	if (info.str[info.pos] == '*')
	{
		info.width = va_arg(info.list, int);
		if (info.width < 0)
		{
			info.width = info.width * -1;
			info.left_just = 1;
		}
		info.pos++;
	}
	if (info.index == 0)
		return (info);
	width = ft_substr(info.str, store, info.index);
	info.width = ft_atoi(width);
	return (info);
}

t_info	ft_flags(t_info info)
{
	while (info.str[info.pos] == '-')
	{
		info.left_just = 1;
		info.pos++;
	}
	while (info.str[info.pos] == '0')
	{
		info.pad_zero = 1;
		info.pos++;
		while (info.str[info.pos] == '-')
		{
			info.left_just = 1;
			info.pos++;
		}
	}
	info = ft_determine_width(info);
	info.prec = -1;
	if (info.str[info.pos] == '.')
	{
		info.pos++;
		info.index = 0;
		info = ft_determine_prec(info);
	}
	return (info);
}

int		ft_itoa_base_len(long int dec_value, int index, int upper, int base)
{
	unsigned long int	x;
	char				base_number[100];

	while (dec_value != 0)
	{
		x = dec_value % base;
		if (x < 10)
			base_number[index] = 48 + x;
		else if (x >= 10 && upper == 0)
			base_number[index] = 87 + x;
		else
			base_number[index] = 55 + x;
		index++;
		dec_value = dec_value / base;
	}
	return (index);
}
