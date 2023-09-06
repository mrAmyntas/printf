/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 18:18:27 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 14:45:06 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	ft_set_info_values(t_info info, const char *str)
{
	info.ret = 0;
	info.left_just = 0;
	info.pad_zero = 0;
	info.pos = 0;
	info.prec = -1;
	info.width = -1;
	info.str = ft_malloc_string(str);
	info.index = 0;
	return (info);
}

int		ft_printf(const char *str, ...)
{
	t_info info;

	va_start(info.list, str);
	info = ft_set_info_values(info, str);
	while (info.str[info.pos] != '\0')
	{
		if (info.str[info.pos] == '%')
		{
			info.pos++;
			info = ft_start_convers(info);
		}
		else
		{
			write(1, &info.str[info.pos], 1);
			info.ret = info.ret + 1;
		}
		info.pos++;
	}
	free(info.str);
	return (info.ret);
}
