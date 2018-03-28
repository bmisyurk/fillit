/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:07:33 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/18 21:07:34 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_tet_to_list(t_list **tl, char *tet, char c)
{
	t_list	*new;

	if (!(*tl))
		*tl = ft_lstnew(tet, c);
	else
	{
		new = ft_lstnew(tet, c);
		ft_lstpush(tl, new);
	}
}

int		solve_map(t_list *tl, t_map *tm)
{
	int			i;
	int			j;
	t_fillit	*tf;

	i = 0;
	if (tl == NULL)
		return (1);
	tf = init_fillit(get_coords(tl), tm, tl);
	while (i < tm->size)
	{
		j = 0;
		while (j < tm->size)
		{
			if (place_tet(tf, j, i))
			{
				if (solve_map(tl->next, tm))
					return (1);
				else
					clean_tet(tm, tl);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map	*solve_fillit(t_list *tl, t_map *tm)
{
	while (!solve_map(tl, tm))
	{
		tm->size++;
		tm = enlarge_map(tm, tm->size);
	}
	return (tm);
}

char	*read_file(int fd, char *f)
{
	char	buf[1];
	int		n;
	ssize_t	ret;
	char	*map;

	ret = 1;
	n = 0;
	while (ret)
	{
		ret = read(fd, buf, 1);
		n++;
	}
	map = (char *)malloc(sizeof(char) * (n + 1));
	ret = 1;
	n = 0;
	fd = open(f, O_RDONLY);
	while (ret)
	{
		ret = read(fd, buf, 1);
		map[n++] = buf[0];
	}
	map[n] = '\0';
	return (map);
}

int		tetr_cycle(char *map, t_list **tl, int *cnt)
{
	int		i;
	int		j;
	char	let;
	char	*tet;

	*cnt = 0;
	i = 0;
	let = 'A';
	tet = (char*)malloc(sizeof(char) * 22);
	while (map[i])
	{
		j = 0;
		while (j < 21)
		{
			tet[j] = map[i];
			j++;
			i++;
		}
		tet[j] = '\0';
		if (!tetrimino_is_correct(tet))
			return (0);
		add_tet_to_list(tl, tet, let++);
		(*cnt)++;
	}
	return (1);
}
