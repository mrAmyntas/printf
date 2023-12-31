/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 14:55:29 by basz          #+#    #+#                 */
/*   Updated: 2020/11/14 15:18:21 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tempdst;
	size_t	i;

	tempdst = (char*)dest;
	i = 0;
	if ((tempdst == NULL) && ((char*)src == NULL))
		return (NULL);
	while (n > i)
	{
		tempdst[i] = ((char*)src)[i];
		i++;
	}
	return (tempdst);
}
