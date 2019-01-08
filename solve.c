/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:23 by llelias           #+#    #+#             */
/*   Updated: 2019/01/07 16:04:41 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		t_check(t_env e)
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

int		solve(t_env e, int num, int r, int c)
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
	else if ((place(e, num, r, c)))
	{
		if (c == e.dim - 1)
		{
			if (solve(e, 0, r + 1, 0))
				return (1);
			else if ((rmv(e, num, r, c)))
				return (solve(e, num + 1, r, c));
		}
		else
		{
			if (solve(e, 0, r, c + 1))
				return (1);
			else if (rmv(e, num, r, c))
				return (solve(e, num + 1, r, c));
		}
	}
	return (0);
}

int		sharris_try(t_env e, int i)
{
	int r;
	int c;
	int sf;

	sf = 0;
	r = 0;
	while(r < e.dim && t_check(e) && sf == 0)
	{
		c = 0
		while (c < e.dim && sf == 0)
		{
			if(fits(e, i, r, c) && place(e, i, r, c))
				if(sharris_try(t_env, i + 1))
					sf = 1;
			if(sf = 0)
				rmv(e, i, r, c);
			c++;
		}
		r++;
	}
	if (t_check(e) == 0 || sf)
		return (1);
	else
		return (0);
}
