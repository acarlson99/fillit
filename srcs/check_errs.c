/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:04:11 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/04 16:10:21 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_err(char *error)
{
	ft_putstr(error);
	exit(1);
}

int		touching(char *p[4], size_t i, size_t j)
{
	int t;

	t = 0;
	if (i < 3)
		t += p[i + 1][j] == '#';
	if (i != 0)
		t += p[i - 1][j] == '#';
	if (j < ft_strlen(p[i]) - 1)
	{
		if (p[i][j + 1] == '\0')
			print_err("error\n");
		t += p[i][j + 1] == '#';
	}
	if (j != 0)
	{
		if (p[i][j - 1] == '\0')
			print_err("error\n");
		t += p[i][j - 1] == '#';
	}
	return (t);
}

int		check_connections(t_lst *lst)
{
	int sum;
	int i;
	int j;

	sum = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (lst->p[i][j] == '#')
				sum += touching(lst->p, i, j);
		}
	}
	return (sum);
}

int		count_chars(t_lst *lst)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = -1;
	while (++k < 4)
	{
		l = -1;
		while (++l < 4)
		{
			if (lst->p[k][l] == '#')
				i++;
			else if (lst->p[k][l] == '.')
				j++;
			else
				print_err("error\n");
		}
	}
	return (i == 4 && j == 12);
}

void	check_all(t_lst *lst)
{
	int connections;

	while (lst)
	{
		if (count_chars(lst))
		{
			connections = check_connections(lst);
			if (!(connections == 6 || connections == 8))
				print_err("error\n");
		}
		else
			print_err("error\n");
		lst = lst->next;
	}
}
