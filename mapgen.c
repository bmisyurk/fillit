/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:38:05 by akupriia          #+#    #+#             */
/*   Updated: 2017/12/09 16:38:06 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**screw_norme2(char **s, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		if (!(s[i] = (char*)malloc(sizeof(char) * (n + 1))))
		{
			s[0] = NULL;
			return (s);
		}
		while (j < n)
		{
			s[i][j] = '.';
			j++;
		}
		s[i][j] = '\0';
		i++;
	}
	s[i] = NULL;
	return (s);
}

t_map			*create_map(int tn, t_map *tm)
{
	int		i;
	char	**s;
	int		n;

	i = 0;
	if (tn > 26)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	n = ft_sqrt(tn * 4);
	if (!(s = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	s = screw_norme2(s, n);
	if (s[0] == NULL)
		return (NULL);
	tm->map = s;
	tm->size = n;
	return (tm);
}

static void		calc_coords2(char **map, int x, int y, t_coord *tc)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (map[i][k] == '#')
			{
				tc->y[j] = i - y;
				tc->x[j] = k - x;
				j++;
			}
			k++;
		}
		i++;
	}
}

static void		calc_coords1(char **map, t_coord *tc)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (map[y][x] == '#')
				break ;
			x++;
		}
		if (map[y][x] == '#')
			break ;
		y++;
	}
	calc_coords2(map, x, y, tc);
}

t_coord			*get_coords(t_list *tl)
{
	t_coord	*tc;
	int		i;
	char	**map;
	int		ind;

	tc = (t_coord *)malloc(sizeof(t_coord));
	map = ft_strsplit(tl->content, '\n');
	calc_coords1(map, tc);
	i = 0;
	while (i < 4)
	{
		if (tc->x[i] == -1)
			ind = -1;
		i++;
	}
	i = 0;
	if (ind == -1)
		while (i < 4)
		{
			tc->x[i++]++;
		}
	return (tc);
}
