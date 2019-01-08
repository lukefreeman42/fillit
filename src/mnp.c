/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:05:46 by llelias           #+#    #+#             */
/*   Updated: 2019/01/08 04:28:41 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		fits(t_env e, int num, int r, int c)
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
				!= e.map[i + r] + (e.tset[num].row[i] * ft_power(2, c)))
			return (0);
	}
	return (1);
}

int		place(t_env e, int num, int r, int c)
{
	int i;
	int flag;

	flag = 0;
	i = -1;
	if (!fits(e, num, r, c))
		flag = 1;
	while (++i < 4)
		e.map[i + r] = (e.map[i + r] ^ (e.tset[num].row[i] * ft_power(2, c)));
	e.tset[num].avail = 0;
	e.tset[num].r = r;
	e.tset[num].c = c;
	if (flag)
		return (0);
	return (1);
}

int		rmv(t_env e, int num, int r, int c)
{
	int i;

	i = -1;
	while (++i < 4)
		e.map[i + r] = (e.map[i + r] ^ (e.tset[num].row[i] * ft_power(2, c)));
	e.tset[num].avail = 1;
	return (1);
}
