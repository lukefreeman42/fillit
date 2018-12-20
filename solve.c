/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:23 by llelias           #+#    #+#             */
/*   Updated: 2018/12/19 18:52:47 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		t_check(env e)
{
	int num;
	int	i;

	num = 0;
	i = -1;
	while (++i < e.nop_m)
		if (e.tset[i].avail == 1)
			num += 1;

	return (num);
}

int		solve(env e,int num, int r, int c)
{
	if (t_check(e) == 0)
		return (1);
	if (r == e.dim - 1)
		return (0);
	if (num >= e.nop_m)
	{
		if (c == e.dim - 1)
			return (solve(e, 0, r + 1, 0));
		else
			return (solve(e, 0, r, c + 1));
	}
	if (!fits(e, num, r, c))
		return (solve(e, num + 1, r, c));
	else
	{
		place(e, num, r, c);
		if (c == e.dim - 1)
		{
			if (solve(e, 0, r + 1, 0))
				return (1);
			else
			{
				rmv(e, num, r, c);
				return (solve(e, num + 1, r, c));
			}
		}
		else
		{
			if(solve(e, 0, r, c + 1))
				return (1);
			else
			{
				rmv(e, num, r, c);
				return (solve(e, num + 1, r, c));
			}
		}
	}
}
