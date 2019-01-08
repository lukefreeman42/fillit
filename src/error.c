/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 10:55:50 by llelias           #+#    #+#             */
/*   Updated: 2019/01/08 04:28:11 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		usage(void)
{
	ft_putstr("./fillit file");
	exit(-1);
}

void		error(void)
{
	ft_putstr("error");
	exit(-1);
}

static int	check_tbl(int tbl[4][4])
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (tbl[i][j] == 1)
			{
				if ((j - 1 < 0 || tbl[i][j - 1] != 1)
					&& (j + 1 > 3 || tbl[i][j + 1] != 1)
					&& (i + 1 > 3 || tbl[i + 1][j] != 1)
					&& (i - 1 < 0 || tbl[i - 1][j] != 1))
					return (0);
			}
		}
		j = -1;
	}
	return (1);
}

static int	valid_t(t_tetra t)
{
	int tbl[4][4];
	int row[4] = {t.row[0], t.row[1], t.row[2], t.row[3]};
	int i;
	int j;

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
	return (check_tbl(tbl));
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
