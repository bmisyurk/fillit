/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:39:35 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/12 20:39:37 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (alst && new)
	{
		if (*alst)
		{
			tmp = *alst;
			while ((*alst)->next)
			{
				*alst = (*alst)->next;
			}
			(*alst)->next = new;
			*alst = tmp;
		}
		else
			*alst = new;
	}
}
