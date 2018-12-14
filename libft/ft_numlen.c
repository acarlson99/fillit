/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:00:55 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/24 15:11:06 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns number of digits in some number n in some base
*/

#include "libft.h"

size_t	ft_numlen(int n, int base)
{
	int count;

	count = 0;
	if (n < 0)
		count++;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}
