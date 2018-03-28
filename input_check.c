/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:08:27 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/13 18:08:28 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>  // Для printf
#include <time.h> 

static int	screw_norme(int cnt, const char *s)
{
	int	i;
	int	cnt1;

	i = 0;
	cnt1 = 0;
	while (s[i])
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			cnt++;
		else if (s[i] == '.')
			cnt1++;
		i++;
	}
	if (cnt != 4)
		return (0);
	if (cnt1 != 12)
		return (0);
	return (1);
}

static int	is_tetr(const char *s, int cnt)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if ((s[i + 1] != '#') && (s[i - 1] != '#')
				&& (s[i + 5] != '#') && (s[i - 5] != '#'))
				return (0);
			if ((s[i + 1] == '#' && s[i + 5] == '#') ||
				(s[i + 1] == '#' && s[i - 5] == '#') ||
				(s[i + 1] == '#' && s[i - 1] == '#') ||
				(s[i - 1] == '#' && s[i + 5] == '#') ||
				(s[i - 1] == '#' && s[i - 5] == '#') ||
				(s[i + 5] == '#' && s[i - 5] == '#'))
				cnt++;
		}
		i++;
	}
	if (!cnt)
		return (0);
	return (1);
}

int			tetrimino_is_correct(const char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
		i++;
	if (i != 21)
		return (0);
	else if ((s[18] != '.' && s[18] != '#')
			|| s[4] != '\n' || s[9] != '\n'
			|| s[14] != '\n' || s[19] != '\n' || s[20] != '\n')
		return (0);
	if (!(screw_norme(cnt, s)))
		return (0);
	cnt = 0;
	if (!(is_tetr(s, cnt)))
		return (0);
	return (1);
}

int			input_algorithm(char *file)
{
	char	*map;
	t_list	*tl;
	t_map	*tm;
	int		cnt;

	tl = NULL;
	cnt = open(file, O_RDONLY);
	if (cnt != -1)
		map = read_file(cnt, file);
	else
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (!tetr_cycle(map, &tl, &cnt))
		return (0);
	tm = (t_map*)malloc(sizeof(t_map));
	tm = create_map(cnt, tm);
	list_init(&tl);
	if (!same_tet(tl))
		solve_fillit(tl, tm);
	else
		solve_fill(tl, tm);
	print_res(tm->map);
	return (1);
}

int			main(int argc, char **argv)
{
 time_t start, end;
  
  time(&start);
	if (argc != 2)
		write(1, "usage: fillit input_file\n", 25);
	else
	{
		if (!input_algorithm(argv[1]))
			write(1, "error\n", 6);
	}
	time(&end);
	double seconds = difftime(end, start);
  printf("The time: %f seconds\n", seconds);
	return (0);
}
