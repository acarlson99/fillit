/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:18:44 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/04 16:27:09 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid(t_map *map, int i, int j, t_lst *piece)
{
	int a;
	int b;

	a = -1;
	while (++a + piece->i < 4)
	{
		b = -1;
		while (++b + piece->j < 4)
		{
			if (piece->p[piece->i + a][piece->j + b] == '.')
				continue ;
			if (i + a >= map->size || j + b >= map->size)
				return (0);
			if (piece->p[a + piece->i][b + piece->j] == '#'\
				&& map->board[i + a][j + b] != '.')
				return (0);
		}
	}
	return (1);
}

void	place_piece(t_map *map, int i, int j, t_lst *piece)
{
	int a;
	int b;

	a = -1;
	while (++a + piece->i < 4)
	{
		b = -1;
		while (++b + piece->j < 4)
		{
			if (piece->p[a + piece->i][b + piece->j] == '#')
				map->board[i + a][j + b] = piece->c;
		}
	}
}

void	reset_piece(t_map *map, t_lst *piece)
{
	int		y;
	char	*str;

	y = 0;
	while (y < map->size)
	{
		str = ft_strchr(map->board[y], piece->c);
		if (str)
			*str = '.';
		else
			y++;
	}
}

int		solve_box(t_map *map, t_lst *lst, int size)
{
	int		i;
	int		j;
	int		placed;

	RET_IF(lst == NULL, 1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			placed = 0;
			if (is_valid(map, i, j, lst))
			{
				placed = 1;
				place_piece(map, i, j, lst);
				RET_IF(solve_box(map, lst->next, size), 1);
			}
			if (placed)
				reset_piece(map, lst);
		}
	}
	return (0);
}
