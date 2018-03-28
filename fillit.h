/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:19:47 by akupriia          #+#    #+#             */
/*   Updated: 2017/11/18 20:19:49 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include "libft/libft.h"

void		add_tet_to_list(t_list **tl, char *tet, char c);
char		*read_file(int fd, char *f);
int			tetrimino_is_correct(const char *s);
int			input_algorithm(char *file);
t_map		*create_map(int tn, t_map *tm);
t_coord		*get_coords(t_list *tl);
int			place_tet(t_fillit *tf, int x, int y);
void		clean_tet(t_map *tm, t_list *tl);
void		list_init(t_list **tl);
int			solve_map(t_list *tl, t_map *tm);
t_map		*enlarge_map(t_map *tm, int n);
t_map		*solve_fillit(t_list *tl, t_map *tm);
t_fillit	*init_fillit(t_coord *tc, t_map *tm, t_list *tl);
int			tetr_cycle(char *map, t_list **tl, int *cnt);
void		print_res(char **s);
int			same_tet(t_list *tl);
int			same_str(char *s1, char *s2);
int			place_same_tet(t_list *tl, t_map *tm);
t_map		*solve_fill(t_list *tl, t_map *tm);

#endif
