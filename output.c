/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:51:20 by akupriia          #+#    #+#             */
/*   Updated: 2017/12/09 21:51:21 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_res(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
			write(1, &s[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int		same_tet(t_list *tl)
{
	t_list	*tmp;
	char	*tet;

	tmp = tl;
	if (tl)
		tet = tl->content;
	while (tmp)
	{
		if (!same_str(tet, tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		same_str(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int		place_same_tet(t_list *tl, t_map *tm)
{
	t_fillit	*tf;
	int			i;
	int			j;

	i = 0;
	tf = init_fillit(get_coords(tl), tm, tl);
	while (i < tm->size)
	{
		j = 0;
		while (j < tm->size)
		{
			if (place_tet(tf, j, i))
			{
				if (!(tl->next))
					return (1);
				tl = tl->next;
				tf = init_fillit(get_coords(tl), tm, tl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map	*solve_fill(t_list *tl, t_map *tm)
{
	while (!place_same_tet(tl, tm))
	{
		tm->size++;
		tm = enlarge_map(tm, tm->size);
	}
	return (tm);
}
