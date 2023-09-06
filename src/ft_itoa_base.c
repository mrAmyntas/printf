/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 15:23:42 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 16:13:00 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_itoa_hex_address(void *pointer, int index, int put_add)
{
	uintptr_t			dec_value;
	unsigned long int	x;
	char				hex_number[100];

	dec_value = (uintptr_t)pointer;
	while (dec_value != 0)
	{
		x = dec_value % 16;
		if (x < 10)
			hex_number[index] = 48 + x;
		else
			hex_number[index] = 87 + x;
		index++;
		dec_value = dec_value / 16;
	}
	x = index;
	while (index >= 0 && put_add == 1)
	{
		write(1, &hex_number[index], 1);
		index--;
	}
	return (x);
}

int		ft_itoa_base(long int dec_value, int index, int upper, int base)
{
	unsigned long int	x;
	char				base_number[100];

	if (dec_value == 0)
		write(1, "0", 1);
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
	x = index;
	while (index >= 1)
	{
		write(1, &base_number[index - 1], 1);
		index--;
	}
	return (x);
}

char	*ft_malloc_string(char const *s1)
{
	char	*buff;
	int		x;

	if (s1 == NULL)
		return (NULL);
	x = ft_strlen(s1) + 1;
	buff = (char*)malloc(sizeof(char) * x);
	if (buff == NULL)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		buff[x] = s1[x];
		x++;
	}
	buff[x] = '\0';
	return (buff);
}
