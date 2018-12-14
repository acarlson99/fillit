/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:57:28 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/04 13:06:29 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	kill_map(t_map **map)
{
	int i;

	i = (*map)->size;
	while (i--)
		free((*map)->board[i]);
	free((*map)->board);
	free(*map);
}

void	print_map(t_map *map)
{
	int y;

	y = -1;
	while (++y < map->size)
		ft_putendl(map->board[y]);
}

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;

	NULL_CHECK(!(map = (t_map *)malloc(sizeof(t_map))));
	i = -1;
	if (!(map->board = (char **)malloc(sizeof(char *) * size)))
	{
		free(map);
		return (NULL);
	}
	while (++i < size)
		map->board[i] = (char *)ft_memset(ft_strnew(size), '.', size);
	map->size = size;
	return (map);
}
