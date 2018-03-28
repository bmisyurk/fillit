/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:09:58 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/07 17:09:59 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, char c)
{
	t_list *list;
	size_t content_size;

	content_size = 21;
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy((list->content), content, content_size);
		list->letter = c;
	}
	list->next = NULL;
	return (list);
}
