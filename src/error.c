/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:55:50 by llelias           #+#    #+#             */
/*   Updated: 2019/01/17 17:21:32 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		usage(void)
{
	ft_putstr("USAGE: ./fillit file\n");
	exit(-1);
}

void		error(void)
{
	ft_putstr("error");
	exit(-1);
}

static int	aw_check_tbl(int tbl[4][4])
{
	int x[3];

	x[0] = -1;
	x[2] = 0;
	while (++x[0] < 4 && (x[1] = -1))
	{
		while (++x[1] < 4)
		{
			if (tbl[x[0]][x[1]] == 1)
			{
				if (x[1] - 1 >= 0 && tbl[x[0]][x[1] - 1] == 1)
					x[2]++;
				if (x[1] + 1 <= 3 && tbl[x[0]][x[1] + 1] == 1)
					x[2]++;
				if (x[0] + 1 <= 3 && tbl[x[0] + 1][x[1]] == 1)
					x[2]++;
				if (x[0] - 1 >= 0 && tbl[x[0] - 1][x[1]] == 1)
					x[2]++;
			}
		}
	}
	if (x[2] == 6 || x[2] == 8)
		return (1);
	return (0);
}

static int	valid_t(t_tetra t)
{
	int tbl[4][4];
	int row[4];
	int i;
	int j;

	i = -1;
	while (++i < 4)
		row[i] = t.row[i];
	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (row[i] % 2 == 1)
				tbl[i][j] = 1;
			else
				tbl[i][j] = 0;
			row[i] /= 2;
		}
		j = -1;
	}
	return (aw_check_tbl(tbl));
}

int			valid_tset(t_tetra *tset, int num)
{
	int i;
	int check;

	i = 0;
	while (i < num)
		if (!(check = valid_t(tset[i++])))
			error();
	return (1);
}
