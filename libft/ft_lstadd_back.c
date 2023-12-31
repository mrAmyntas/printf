/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:46:27 by basz          #+#    #+#                 */
/*   Updated: 2020/11/15 20:37:56 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lastelem;

	if (*lst != NULL && new != NULL)
	{
		lastelem = ft_lstlast(*lst);
		if (lastelem != NULL)
			lastelem->next = new;
	}
	if (new != NULL && *lst == NULL)
		*lst = new;
}
