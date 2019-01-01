/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: callen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:44:33 by callen            #+#    #+#             */
/*   Updated: 2018/11/04 20:27:35 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** valid file of 26 tets == 145 lines
*/

t_lst	*pull_pieces(int fd)
{
	t_lst	*pieces;
	t_lst	*new;
	char	*tmp;
	char	c;

	c = '@';
	pieces = NULL;
	if (fd < 0)
		print_err("error\n");
	while ((new = lst_new(++c, fd)))
	{
		if (c > 'Z')
			print_err("error\n");
		lst_addtail(&pieces, new);
		if (get_next_line(fd, &tmp) < 1)
			break ;
		if (tmp[0] != '\0')
			print_err("error\n");
		free(tmp);
	}
	return (pieces);
}

int		main(int ac, char **av)
{
	t_lst	*pieces;
	t_map	*map;
	int		size;

	size = 2;
	if (ac != 2)
		print_err("usage: ./fillit tetromino_file\n");
	pieces = pull_pieces(open(av[1], O_RDONLY));
	check_all(pieces);
	map = create_map(size);
	while (!(solve_box(map, pieces, size)))
		map = create_map(++size);
	print_map(map);
	lst_free(&pieces);
	kill_map(&map);
	return (EXIT_SUCCESS);
}
