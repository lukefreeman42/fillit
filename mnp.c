/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:05:46 by llelias           #+#    #+#             */
/*   Updated: 2018/12/19 19:26:14 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fits(env e, int num, int r, int c)
{
	int i;

	i = -1;
	if (e.tset[num].avail == 0)
		return (0);
	while (++i < 4)
	{
		if (e.tset[num].row[i])
			if (i + r == e.dim)
				return (0);
		if (ft_power(2, c) * e.tset[num].row[i] > ft_power(2, e.dim) - 1)
			return (0);
		if ((e.map[i + r] ^ (e.tset[num].row[i] * ft_power(2, c)))
			!= e.map[i + r] + (e.tset[num].row[i] * ft_power(2,c)))
			return (0);
	}
	return (1);
}

int		place(env e, int num, int r, int c)
{
	int i;

	i = -1;
	while (++i < 4)
		e.map[i + r] = (e.map[i + r] ^ (e.tset[num].row[i] * ft_power(2, c)));
	e.tset[num].avail = 0;
	e.tset[num].r = r;
	e.tset[num].c = c;
	return (1);
}

int		rmv(env e, int num, int r, int c)
{
	int i;

	i = -1;
	while (++i < 4)
		e.map[i + r] = (e.map[i + r] ^ (e.tset[num].row[i] * ft_power(2, c)));
	e.tset[num].avail = 1;
	return (1);
}