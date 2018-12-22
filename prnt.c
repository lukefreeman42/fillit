/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llelias <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:31:21 by llelias           #+#    #+#             */
/*   Updated: 2018/12/20 17:41:08 by llelias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_map(int dim, char map[dim][dim])
{
	int i;
	int j;

	j = 0;
	while (j < dim)
	{
		i = 0;
		while (i < dim)
			write(1, &map[j][i++], 1);
		ft_putstr("\n");
		j++;
	}
}

static void		plac_t(int dim, char map[dim][dim], tetra t)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (t.row[j] % 2 == 1)
				map[t.r + j][t.c + i] = t.a;
			t.row[j] /= 2;
		}
	}
}

void			make_map(env e)
{
	char	map[e.dim][e.dim];
	int		i;
	int		j;

	j = 0;
	while (j < e.dim)
	{
		i = 0;
		while (i < e.dim)
			map[j][i++] = '.';
		j++;
	}
	i = 0;
	while (i < e.nop_m)
		plac_t(e.dim, map, e.tset[i++]);
	print_map(e.dim, map);
}
