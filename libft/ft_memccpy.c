/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 17:27:44 by bhoitzin      #+#    #+#                 */
/*   Updated: 2020/11/14 15:17:39 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dest;
	char			*sorc;
	unsigned int	i;

	sorc = (char*)src;
	dest = (char*)dst;
	i = 0;
	while ((i < n))
	{
		dest[i] = sorc[i];
		if (sorc[i] == (char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
