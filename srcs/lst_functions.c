/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:49:40 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/04 15:31:38 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_box_i(char *p[4])
{
	int i;

	i = 0;
	while (p[i] && !(ft_isin('#', p[i])))
		i++;
	return (i);
}

int		get_box_j(char *p[4], int i)
{
	int		j;
	char	*str;

	j = 4;
	while (i < 4)
	{
		str = ft_strchr(p[i], '#');
		if (str)
			j = MIN(j, str - &p[i][0]);
		i++;
	}
	return (j);
}

t_lst	*lst_new(char c, int fd)
{
	t_lst	*new;
	char	*line;
	int		i;

	i = 0;
	NULL_CHECK(!(new = (t_lst*)ft_memalloc(sizeof(t_lst))));
	new->next = NULL;
	new->c = c;
	while (i < 4 && get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 4)
			break ;
		new->p[i++] = ft_strdup(line);
		free(line);
	}
	if (!(new->p[3]))
		print_err("error\n");
	new->i = get_box_i(new->p);
	new->j = get_box_j(new->p, new->j);
	return (new);
}

void	lst_addtail(t_lst **alst, t_lst *new)
{
	t_lst	*head;
	t_lst	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	(*alst) = head;
}

void	lst_free(t_lst **head)
{
	t_lst *tmp;

	while (*head)
	{
		tmp = *head;
		free((*head)->p[0]);
		free((*head)->p[1]);
		free((*head)->p[2]);
		free((*head)->p[3]);
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
