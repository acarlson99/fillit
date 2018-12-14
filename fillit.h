/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:32:51 by callen            #+#    #+#             */
/*   Updated: 2018/11/04 20:06:30 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_lst
{
	char			c;
	char			*p[4];
	int				i;
	int				j;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	char		**board;
	int			size;
}				t_map;

/*
** Tetromino Checkers [check_errs.c]
*/

void			check_all(t_lst *lst);

/*
** List Functions [lst_funcs]
*/

void			print_list(t_lst *lst);
t_lst			*lst_new(char c, int fd);
void			lst_addtail(t_lst **alst, t_lst *new);
void			lst_free(t_lst **head);
void			print_err(char *error);

/*
** Solver Functions [solve_box.c]
*/

int				is_valid(t_map *map, int i, int j, t_lst *list);
void			place_piece(t_map *map, int i, int j, t_lst *list);
void			reset_piece(t_map *map, t_lst *piece);
int				solve_box(t_map *map, t_lst *lst, int size);

/*
** Map Functions [map_funcs.c]
*/

void			print_map(t_map *map);
void			kill_map(t_map **map);
t_map			*create_map(int size);

#endif
