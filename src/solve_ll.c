/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:23:23 by llelias           #+#    #+#             */
/*   Updated: 2019/01/08 04:29:08 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** t_check(t_env e) will check the array of peices in enviornment e.
** It will check how many peices are still available to be placed. This is
** used to find out when all the  peices have been placed, and terminate any
** recurssive processes.
*/

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

/*
** This is a backtracking algorithm that will solve fillit. The algorithm
** will check to see if peice NUM can be placed at cordinate (Column, Row) on
** the map contained in the Enviornment E. If the peice cannot be placed it will
** attempt to peice NUM + 1 until all peices have been attempted. If not one can
** be placed on that spot it will then move to the next coordinate. It will
** return a 1 once all peices are placed, or a 0 should the puzzle be
** unsolvable with the dimentions stored in E.
*/

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
