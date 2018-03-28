/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:59:28 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/19 17:59:29 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*enlarge_map(t_map *tm, int n)
{
	char	**s;
	int		i;
	int		j;

	i = 0;
	if (!(s = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		j = 0;
		if (!(s[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (NULL);
		while (j < n)
		{
			s[i][j] = '.';
			j++;
		}
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	tm->map = s;
	return (tm);
}

void		list_init(t_list **tl)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *tl;
	while (*tl)
	{
		(*tl)->tc = (t_coord *)malloc(sizeof(t_coord));
		while (i < 4)
		{
			(*tl)->tc->x[i] = 0;
			(*tl)->tc->y[i] = 0;
			i++;
		}
		*tl = (*tl)->next;
	}
	*tl = tmp;
}

t_fillit	*init_fillit(t_coord *tc, t_map *tm, t_list *tl)
{
	t_fillit	*tf;

	tf = (t_fillit *)malloc(sizeof(t_fillit));
	tf->tc = tc;
	tf->tl = tl;
	tf->tm = tm;
	return (tf);
}

int			place_tet(t_fillit *tf, int j, int i)
{
	if (i + tf->tc->y[0] < tf->tm->size && j + tf->tc->x[0] < tf->tm->size
		&& i + tf->tc->y[1] < tf->tm->size && j + tf->tc->x[1] < tf->tm->size
		&& i + tf->tc->y[2] < tf->tm->size && j + tf->tc->x[2] < tf->tm->size
		&& i + tf->tc->y[3] < tf->tm->size && j + tf->tc->x[3] < tf->tm->size)
		if (tf->tm->map[i + tf->tc->y[0]][j + tf->tc->x[0]] == '.'
			&& tf->tm->map[i + tf->tc->y[1]][j + tf->tc->x[1]] == '.'
			&& tf->tm->map[i + tf->tc->y[2]][j + tf->tc->x[2]] == '.'
			&& tf->tm->map[i + tf->tc->y[3]][j + tf->tc->x[3]] == '.')
		{
			tf->tm->map[i + tf->tc->y[0]][j + tf->tc->x[0]] = tf->tl->letter;
			tf->tm->map[i + tf->tc->y[1]][j + tf->tc->x[1]] = tf->tl->letter;
			tf->tm->map[i + tf->tc->y[2]][j + tf->tc->x[2]] = tf->tl->letter;
			tf->tm->map[i + tf->tc->y[3]][j + tf->tc->x[3]] = tf->tl->letter;
			tf->tl->tc->x[0] = j + tf->tc->x[0];
			tf->tl->tc->y[0] = i + tf->tc->y[0];
			tf->tl->tc->x[1] = j + tf->tc->x[1];
			tf->tl->tc->y[1] = i + tf->tc->y[1];
			tf->tl->tc->x[2] = j + tf->tc->x[2];
			tf->tl->tc->y[2] = i + tf->tc->y[2];
			tf->tl->tc->x[3] = j + tf->tc->x[3];
			tf->tl->tc->y[3] = i + tf->tc->y[3];
			return (1);
		}
	return (0);
}

void		clean_tet(t_map *tm, t_list *tl)
{
	if ((tl->tc->x[0] >= 0 && tl->tc->x[0] < tm->size)
		&& (tl->tc->y[0] >= 0 && tl->tc->y[0] < tm->size)
		&& (tl->tc->x[1] >= 0 && tl->tc->x[1] < tm->size)
		&& (tl->tc->y[1] >= 0 && tl->tc->y[1] < tm->size)
		&& (tl->tc->x[2] >= 0 && tl->tc->x[2] < tm->size)
		&& (tl->tc->y[2] >= 0 && tl->tc->y[2] < tm->size)
		&& (tl->tc->x[3] >= 0 && tl->tc->x[3] < tm->size)
		&& (tl->tc->y[3] >= 0 && tl->tc->y[3] < tm->size))
		if ((tm->map[tl->tc->y[0]][tl->tc->x[0]] == tl->letter)
			&& (tm->map[tl->tc->y[1]][tl->tc->x[1]] == tl->letter)
			&& (tm->map[tl->tc->y[2]][tl->tc->x[2]] == tl->letter)
			&& (tm->map[tl->tc->y[3]][tl->tc->x[3]] == tl->letter))
		{
			tm->map[tl->tc->y[0]][tl->tc->x[0]] = '.';
			tm->map[tl->tc->y[1]][tl->tc->x[1]] = '.';
			tm->map[tl->tc->y[2]][tl->tc->x[2]] = '.';
			tm->map[tl->tc->y[3]][tl->tc->x[3]] = '.';
		}
}
