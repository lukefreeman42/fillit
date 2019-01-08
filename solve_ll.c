/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:23 by llelias           #+#    #+#             */
/*   Updated: 2019/01/07 16:28:33 by llelias          ###   ########.fr       */
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

int		solve_ll(t_env e, int num, int r, int c)
{
	if (t_check(e) == 0)
		return (1);
	if (r == e.dim - 1)
		return (0);
	if (num >= e.nop_m)
	{
		if (c == e.dim - 1)
			return (solve_ll(e, 0, r + 1, 0));
		else
			return (solve_ll(e, 0, r, c + 1));
	}
	if (!fits(e, num, r, c))
		return (solve_ll(e, num + 1, r, c));
	else if ((place(e, num, r, c)))
	{
		if (c == e.dim - 1)
		{
			if (solve_ll(e, 0, r + 1, 0))
				return (1);
			else if ((rmv(e, num, r, c)))
				return (solve_ll(e, num + 1, r, c));
		}
		else
		{
			if (solve_ll(e, 0, r, c + 1))
				return (1);
			else if (rmv(e, num, r, c))
				return (solve_ll(e, num + 1, r, c));
		}
	}
	return (0);
}
