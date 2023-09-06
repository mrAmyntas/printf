/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/13 17:49:20 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 14:45:54 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info		ft_write_string(t_info info, int len, char *str)
{
	if (info.left_just == 1)
	{
		if (info.prec != -1 && info.prec < info.width)
			write(1, str, info.prec);
		else
			write(1, str, len);
	}
	if (info.width > info.ret)
	{
		info.ret = info.width;
		info = ft_padding(info, len);
	}
	if (info.left_just == 0)
	{
		if (info.prec != -1 && (info.prec < info.width || info.width == -1))
			write(1, str, info.prec);
		else
			write(1, str, len);
	}
	return (info);
}

static int	ft_nbr_len2(char *str)
{
	int index;
	int j;

	j = 0;
	index = 11;
	while (str[j] == '0')
	{
		index--;
		j++;
	}
	return (index);
}

int			ft_nbr_len(int n)
{
	int		x;
	long	mod;
	long	nbb;
	char	str[12];
	int		i;

	nbb = n;
	mod = 10;
	i = 10;
	if (nbb < 0)
		nbb = nbb * -1;
	while (i >= 0)
	{
		x = nbb % mod / (mod / 10) + 48;
		str[i] = x;
		mod = mod * 10;
		i--;
	}
	if (n < 0)
		return (ft_nbr_len2(str) + 1);
	return (ft_nbr_len2(str));
}

static int	ft_putstr(char *str)
{
	int index;
	int j;
	int ret;

	j = 0;
	index = 11;
	while (str[j] == '0')
	{
		index--;
		j++;
	}
	ret = index;
	while (index != 0)
	{
		write(1, &str[j], 1);
		index--;
		j++;
	}
	return (ret);
}

int			ft_write_nbr(int n, t_info info)
{
	int		x;
	long	mod;
	long	nbb;
	char	str[12];

	nbb = n;
	mod = 10;
	info.index = 10;
	if (nbb == 0 && info.prec != 0)
		write(1, &"0", 1);
	if (nbb < 0)
	{
		if (info.pad_zero == 0 && info.prec == -1)
			write(1, "-", 1);
		nbb = nbb * -1;
	}
	while (info.index >= 0)
	{
		x = nbb % mod / (mod / 10) + 48;
		str[info.index] = x;
		mod = mod * 10;
		info.index--;
	}
	x = ft_putstr(str);
	return (x);
}
